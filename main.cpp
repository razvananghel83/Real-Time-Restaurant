#include "headers/Order.h"
#include "headers/Menu.h"
#include "headers/Item.h"
#include "headers/Table.h"
#include "headers/FirstCourse.h"
#include "headers/Drinks.h"

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <cstdlib>

using namespace std::chrono;   // For using 'min' literal, which refers to minutes


/// Defines de default length in bytes for a buffer to be sent or received
#define DEFAULT_LENGTH 512

/// The default port which will connect the client and the server
#define DEFAULT_PORT "27015"


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


int main()
{

    Drinks<int> cola( "Cola", "Racoritoare", 6.5, 330, 2min, 0 );
    Drinks<float> whiskey( "Whiskey", "Tarie", 15.5, 40, 2min, 35.5 );



    /// WSADATA holds information about the Winsock implementation. It’s used for initializing Winsock.
    WSADATA wsaData;
    /// The socket used by the client to connect to the server
    SOCKET ConnectSocket = INVALID_SOCKET;

    /// Pointer to the result returned by <i>getaddrinfo</i>
    addrinfo *result = NULL;
    /// Pointer used to iterate through the list of possible adresses returned by <i>getaddrinfo</i>
    addrinfo *ptr = NULL;

    /**  Speciefies prefferences( hints ) for the address resolution process : <br>
     *   - <i>address family</i> will be  <i><b>IPv4</i></b> <br>
     *   - <i>socket type</i> will be <i><b>Stream Socket</i></b> <br>
     *   - <i>protocol</i> used will be <i><b>TCP IP</i></b> */
    addrinfo prefferences;

    /// The buffer that is sent to the server
    char sendBuffer[ DEFAULT_LENGTH ] = "Test buffer";
    /// The buffer that is received from the server
    char receiveBuffer[ DEFAULT_LENGTH ];

    /// Used to check if the winsock functions encountered errors while running.
    int errorCode;
    /// Request in integer, made by the user in the console regarding the use of the established connection
    int userRequest = 0;


    // Validate the parameters of the main function
//    if (argumentsCounter != 2) {
//        printf("usage: %s server-name\n", argumentsArray[0]);
//        return 1;
//    }


    // The function initializes the Winsock library and provides version information
    errorCode = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (errorCode != 0) {

        printf("WSAStartup failed with error: %d\n", errorCode);
        return 1;
    }

    ZeroMemory(&prefferences, sizeof(prefferences) );
    prefferences.ai_family = AF_INET;         // Specifies the IPv4 adress type
    prefferences.ai_socktype = SOCK_STREAM;   // Specifies the type of socket as a stream
    prefferences.ai_protocol = IPPROTO_TCP;   // Specifies the use of TCP proctocol


    /*   Finds the corresponding IP adress and port number to the domain name provided by the servname parameter.
     *   Stores a list of possible IP adresses associated with the given servname inside result.
     *   Nodename might need to be replaced by the 2nd argument of the command line. */
    errorCode = getaddrinfo(NULL, DEFAULT_PORT, &prefferences, &result);
    if (errorCode != 0 ) {

        printf("getaddrinfo failed with error: %d\n", errorCode);
        WSACleanup();
        return 1;
    }


    // Attempt to connect to an address until one succeeds
    for( ptr = result; ptr != NULL; ptr = ptr->ai_next ) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {

            printf("socket failed with error: %d\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        errorCode = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (errorCode == SOCKET_ERROR) {

            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }

        std::cout << "Connected succesfully!\n";
        break;
    }

    // The result is no longer needed since an IP was found, so it is cleared.
    freeaddrinfo(result);


    if (ConnectSocket == INVALID_SOCKET) {

        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }


    // Send an initial buffer
    errorCode = send(ConnectSocket, sendBuffer, (int)strlen(sendBuffer), 0 );
    if (errorCode == SOCKET_ERROR) {

        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }


    std::cout << "Buffer sent!\n";
    userRequest = 2;


    // Receive until the client closes the connection
    do {

        errorCode = recv(ConnectSocket, receiveBuffer, DEFAULT_LENGTH, 0);
        if ( errorCode > 0 ) {
            trim(receiveBuffer);
            std::cout << "Information received: \n" << receiveBuffer;
            std::cout << "\nWhat would you like to do now?\n";
            std::cin >> userRequest;
            std::cin.get();
        }
        else if (errorCode == 0 ) {

            printf("Connection closed\n");
            break;
        }
        else {

            printf("recv failed with error: %d\n", WSAGetLastError());
            break;
        }

        if( userRequest == 0 ){ // shutdown

            // shutdown the connection since no more data will be sent
            errorCode = shutdown(ConnectSocket, SD_SEND);
            if (errorCode == SOCKET_ERROR) {

                printf("shutdown failed with error: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;
            }
        }
        else if( userRequest == 1 ){ // send

            clear( sendBuffer );
            // read the send buffer
            std::cout << "What data would you like to send?\n";
            std::cin.getline( sendBuffer, DEFAULT_LENGTH );

            // end the buffer
            sendBuffer[ strlen(sendBuffer) ] = '\0';

            // send the buffer
            errorCode = send(ConnectSocket, sendBuffer, (int)strlen(sendBuffer), 0 );

            if (errorCode == SOCKET_ERROR) {

                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;
            }
            std::cout << "Data sent succesfully!\n\n";
        }
        else
            break;

    } while( userRequest > 0 && errorCode > 0 );


    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();


}