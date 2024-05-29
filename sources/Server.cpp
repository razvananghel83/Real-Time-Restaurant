#include <iostream>
#include <fstream>
#include <cstring>
#include <Ws2tcpip.h>
#include <WinSock2.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

#define DEFAULT_PORT "27015"
#define DEFAULT_LENGTH 512

void trim(char* text) {

	int i = 0;
	while ( ( text[ i ] >= 'a' && text[ i ] <= 'z' ) || (text[i] >= 'A' && text[i] <= 'Z') ||
		      strchr( ". ;:1234567890-!", text[ i ] ) != NULL )
					i++;

	text[ i ] = '\0';
}

void clear(char* text) {

	int length = strlen(text);
	int i = 1;

	while (i <= length)
		text[i++] = '\0';

}

int main() {

	/// WSADATA holds information about the Winsock implementation. It’s used for initializing Winsock.
	WSADATA wsadata;
	/// an integer result that will be used to store error codes and stop the server if something goes wrong
	int errorCode;

	// sockets are set to a nil value
	/// The socket used by the server to connect to the client
	SOCKET ListenSocket = INVALID_SOCKET;
	/// The socket used by the client to connect to the server
	SOCKET ClientSocket = INVALID_SOCKET;

	// Struct used to store information about the server adress
	addrinfo* result = NULL;

	/**  Speciefies prefferences for the address resolution process : <br>
	 *   - <i>address family</i> will be  <i><b>IPv4</i></b> <br>
	 *   - <i>socket type</i> will be <i><b>Stream Socket</i></b> <br>
	 *   - <i>protocol</i> used will be <i><b>TCP IP</i></b> */
	addrinfo prefferences;
	
	/// The result of the sending process. Can store potential error codes
	int sendResult;
	/// The buffer received from the client
	char receiveBuffer[ DEFAULT_LENGTH ];
	/// The buffer that will be sent to the client
	char sendBuffer[ DEFAULT_LENGTH ];


	// The function initializes the Winsock library and provides version information
	errorCode = WSAStartup( MAKEWORD(2, 2), &wsadata);
	if (errorCode != 0) {
		printf("WSAStartup failed: %d\n", errorCode);
		return 1;
	}


	ZeroMemory( &prefferences, sizeof(prefferences) );
	prefferences.ai_family = AF_INET;         // Specifies the IPv4 adress type
	prefferences.ai_socktype = SOCK_STREAM;   // Specifies the type of socket as a stream 
	prefferences.ai_protocol = IPPROTO_TCP;   // Specifies the use of TCP proctocol
	// AI_PASSIVE flag indicates that the caller intends to use the returned socket address structure in a call to the bind function
	prefferences.ai_flags = AI_PASSIVE;	  


	/*   Finds the corresponding IP adress and port number to the domain name provided by the servname parameter.
	 *   Stores a list of possible IP adresses associated with the given servname inside result.   */
	errorCode = getaddrinfo( NULL, DEFAULT_PORT, &prefferences, &result );
	if (errorCode != 0 ) {

		printf("getaddrinfo failed: %d\n", errorCode);
		WSACleanup();
		return 1;
	}


	// Create a SOCKET for the server to listen for client connections
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {

		printf( "Error at socket(): %ld\n", WSAGetLastError() );
		freeaddrinfo( result );
		WSACleanup();
		return 1;
	}


	// Setup the TCP listening socket
	// The bind functions assigns the server a port and an IP adress so the client knows where to send data to
	errorCode = bind( ListenSocket, result->ai_addr, (int)result->ai_addrlen );
	if ( errorCode == SOCKET_ERROR ) {

		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	// After binding the result addrinfo is not needed anymore, so it is deleted
	freeaddrinfo(result);

	if (listen(ListenSocket, 1) == SOCKET_ERROR) {

		printf( "Listen failed with error: %ld\n", WSAGetLastError() );
		closesocket( ListenSocket );
		WSACleanup();
		return 1;
	}


	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if( ClientSocket == INVALID_SOCKET ) {

		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	cout << "Connected succesfully!\n";
	int userRequest = 2;



	// Receive until the client shuts down the connection
	do {
		
		errorCode = recv( ClientSocket, receiveBuffer, DEFAULT_LENGTH, 0 );

		if ( errorCode > 0 ) {

			trim(receiveBuffer);
			cout << "The following information has been received:\n" << receiveBuffer << '\n';
			cout << "\nWhat would you like to do now?\n";
			cin >> userRequest;
			cin.get();
		}
		else if ( errorCode == 0 )
		{
			printf("Connection closing...\n");
			break;
		}
		else {

			printf("recv failed: %d\n", WSAGetLastError());
			closesocket( ClientSocket );
			WSACleanup();
			return 1;
		}

		if (userRequest == 1) {

			// read the send buffer
			cout << "What would you like to send?\n";
			clear(sendBuffer);
			cin.getline( sendBuffer, DEFAULT_LENGTH );


			// end the buffer
			sendBuffer[ strlen( sendBuffer ) ] = '\0';

			// send the buffer
			sendResult = send(ClientSocket, sendBuffer, strlen(sendBuffer), 0);

			if (sendResult == SOCKET_ERROR) {

				printf("send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}

			cout << "Information sent!\n\n";
		}
		else
		{
			cout << "Connection closing...\n\n";
			break;
		}

	} while ( errorCode > 0 && userRequest > 0 );


	// shutdown the send half of the connection since no more data will be sent
	errorCode = shutdown( ClientSocket, SD_SEND );
	if ( errorCode == SOCKET_ERROR ) {

		printf("shutdown failed: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}


	// cleanup
	closesocket(ClientSocket);
	WSACleanup();

}