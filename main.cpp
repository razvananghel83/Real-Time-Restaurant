#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace  std::chrono;       // pentru folosirea literalului min


std::ostream& operator << ( std::ostream& out, const std::chrono::minutes& duration )
{
    out << duration.count() << " minute";
    return out;
}



class Menu_Item{

private:
    std::string name;
    std::string category;
    float price;
    int item_id;
    int pieces;
    std::chrono::minutes timp_preparare;


public:

    // Constructors :

    // Default constructor :
    Menu_Item()
        : name("Unknown"), category("Unknown"), price(0.0f), item_id(0), pieces( 0 ), timp_preparare( 0min )  {

    }

    // Constructor parametrizabil :
    Menu_Item( const std::string& name, const std::string& category, float price, int item_id, int pieces ,std::chrono::minutes timp_preparare )
        : name(name), category(category), price( price ), item_id(item_id), pieces( pieces ), timp_preparare( timp_preparare ) {

    }

    // Copy constructor :
    Menu_Item( Menu_Item const& Item ) = default;

    // Destructor :
    ~Menu_Item() = default;



    // Getters and setters :

    // Name field
    const std::string &getName() const {
        return this->name;
    }

    void setName( const std::string &new_name ) {
        this->name = new_name;
    }


    // Categoty field
    const std::string &getCategoty() const {
        return this->category;
    }

    void setCategory( const std::string &new_category ) {
        this->category = new_category;
    }


    // Price field
    float getPrice() const {
        return this->price;
    }

    void setPrice( const float& new_price ) {
        this->price = new_price;
    }


    // Id field
    int getId() const{
        return this->item_id;
    }

    void setId( const int& new_id ) {
        this->item_id = new_id;
    }


    // Pieces field:
    int getPieces() const {
        return pieces;
    }

    void setPieces( const int& new_number_of_pieces) {
        this->pieces = new_number_of_pieces;
    }

    // timp_preparare field
    std::chrono::minutes getTimp_preparare() const {
        return this->timp_preparare;
    }

    void setTimp_preparare( const std::chrono::minutes& duration ){
        this->timp_preparare = duration;
    }

    // Operatori :
    Menu_Item& operator =( const Menu_Item& item ) = default;

    friend std::ostream& operator << ( std::ostream &out, const Menu_Item& item ) {
        out << item.name << " are id-ul " << item.item_id << ", apartine categoriei " << item.category << ", costa " << item.price <<
        " lei, se prepara in " << item.timp_preparare << " si a fost comandat in " << item.pieces <<" bucati.\n";
        return out;
    }

    bool operator == (const Menu_Item &item) const {
        return name == item.name &&
               category == item.category &&
               price == item.price &&
               item_id == item.item_id &&
               pieces == item.pieces &&
               timp_preparare == item.timp_preparare;
    }

    bool operator != (const Menu_Item &item) const {
        return !( item == *this );
    }
};


class Menu{
private:
    std::vector<Menu_Item> Menu_list;

public:

    // Constructors :

    // Default constructor :
    Menu(){
        Menu_list.reserve(30);
    }

    // Constructor parametrizabil :
    Menu( std::vector<Menu_Item>& list ) {
        Menu_list = list;
    }

    // Copy constructor is not necessary because a single menu will be implemented
    Menu( Menu & meniu ) = delete;

    // Destructor :
    ~Menu() =  default;


    // Getter :
    const std::vector<Menu_Item> &getMenu_list() const {
        return Menu_list;
    }

    void setMenu_list(const std::vector<Menu_Item> &new_list) {
        Menu_list = new_list;
    }


    // Other vector methods:
    void clearMenu(){
        Menu_list.clear();
    }

    void addItem( Menu_Item& item ){
        Menu_list.emplace_back( item );
    }

    void removeItem( Menu_Item& item ){

        for( auto it = Menu_list.begin(); it != Menu_list.end(); it++ ) {
            if ( item == *it ) {
                Menu_list.erase(it);
                break;
            }
        }
    }

    void replaceItem( Menu_Item& old_item, Menu_Item& new_item ){

        for(auto & Item : Menu_list) {
            if ( old_item == Item ) {
                Item = new_item;
                break;
            }
        }
    }

    int MenuLength() const{
        return Menu_list.size();
    }


    // Operators :
    Menu& operator = ( const Menu& other_menu ) = delete;

    friend std::ostream& operator << (std::ostream& out, const Menu& menu)
    {
        out << "Lista felurilor de mancare din meniu este: \n";
        for(const auto & it : menu.Menu_list)
            out << it;
        out << "\n\n";
        return out;
    }

};


class Order{

private:
    int order_id;
    std::vector<Menu_Item> Items;


public:

    // Construstors:

    // Fiecare camp Items va avea rezervate 5 locatii deoarece am considerat ca rareori un om comanda mai mult de 5 feluri de mancare
    // La feluri de mancare am inclus si bauturile. Cu alte cuvinte, presupun ca un client va comanda
    // Bautura 1, fel 1, bautura 2, fel 2, desert

    // Default constructor:
    Order()
        : order_id( 0 ) {
        Items.reserve(5);
    }

    // Constructori parametrizabili :
    Order( int order_id )
        : order_id( order_id ) {
        Items.reserve(5);
    }

    Order( int order_id, std::vector<Menu_Item>& Items )
        : order_id( order_id ), Items( Items ) {
        Items.reserve(5);
    }

    // Copy constructor :
    Order( Order& order )
        : order_id( order.order_id ), Items( order.Items ) {

    }

    // Destructor :
    ~Order() = default;



    // Getters and setters:


    // Order_Id field:
    int getOrderId() const {
        return order_id;
    }

    void setOrderId( int new_orderId ) {
        order_id = new_orderId;
    }


    // Items field:
    const std::vector<Menu_Item> &getItems() const {
        return Items;
    }

    void setItems(const std::vector<Menu_Item> &new_Items) {
        Items = new_Items;
    }


    // Other vector methods:
    void clearOrder(){
        Items.clear();
    }

    void addItem( Menu_Item& item ){
        Items.emplace_back( item );
    }

    void removeItem( Menu_Item& item ){

        for( auto it = Items.begin(); it != Items.end(); it++ ) {
            if (item == *it) {
                Items.erase(it);
                break;
            }
        }
    }

    void replaceItem( Menu_Item& old_item, Menu_Item& new_item ){

        for(auto & Item : Items) {
            if ( old_item == Item ) {
                Item = new_item;
                break;
            }
        }
    }

    float calculate_price() {       // suma float a preturilor Menu_item-elor comandate

        float price = 0;
        for (auto & Item : Items)
            price += ( Item.getPieces() * Item.getPrice() );

        return price;
    }

    std::chrono::minutes calculate_timp_preparare_comanda(){

        // Definesc timpul de preparare al unei comenzi ca maximul dintre timpii de preparare ai fiecarui item din meniu

        std::chrono::minutes maxim = Items[ 0 ].getTimp_preparare();

        for (auto & Item : Items)
            if( Item.getTimp_preparare() > maxim )
                maxim = Item.getTimp_preparare();

        return maxim;
    }

    int orderItems() const{
        return this->Items.size();
    }



    // Operators :
    Order& operator = ( const Order& other_order ) = default;

    friend std::ostream& operator << (std::ostream& os, const Order& order )
    {
        os << "Comanda cu id-ul " << order.order_id << " este alcatuita din felurile: " << '\n';
        for(const auto & Item : order.Items)
            os << Item << ", ";
        os << ".\n";
        return os;
    }

};


class Table{
private:
    int table_id;
    bool occupied;
    Order order;


public:

    // Constructors :

    // Default constructor :
    Table()
        : table_id( 0 ), occupied( false ) {

    }

    // Constructor parametrizabil :
    Table(int tableId, bool occupied, Order& order )
        : table_id(tableId), occupied( occupied ) ,order( order ) {

    }

    // Copy constructor :
    Table( Table& other_table ) = default;


    // Destructor :
    ~Table() = default;


    // Getters and setters :

    // Id field :
    int getId() const {
        return this->table_id;
    }

    void setId( int new_id ){
        this->table_id = new_id;
    }

    // Occupied field :
    bool getOccupied() const {
        return this->occupied;
    }

    void setOccupied( bool new_state ){
        this->occupied = new_state;
    }

    void placeOrder( Order& order ){

    }

    // Operators :
    Table& operator = ( const Table& other_table ) = default;

    friend std::ostream &operator << ( std::ostream &out, const Table& table ) {
        if( table.occupied == 1 )
            out << "Masa cu id-ul " << table.table_id << " este ocupata si are comanda:\n" << table.order << "\n.";
        else
            out << "Masa cu id-ul " << table.table_id << " este libera.\n";

        return out;
    }

};



int main() {

    Menu_Item Ciorba("Ciorba", "Ciorbe si supe", 12.5, 10001, 1, 5min );
    Menu_Item Paste(Ciorba);
    Menu_Item empty_item;

//    std::cout << "Menu_Item construit parametrizabil:\n" << Ciorba;
//    std::cout << "\nMenu_Item construit prin copiere:\n" << Paste;

    Paste.setId(10002);
    Paste.setPrice(27.89);
    Paste.setTimp_preparare(20min);
    Paste.setCategory("Paste");
    Paste.setName("Paste carbonara");
    Paste.setPieces(4);

    //std::cout << "\n\n\nSetteri testati pentru Menu_Item:\n" << Paste;
    //std::cout << "\n\nUn item gol:\n" << empty_item;

    empty_item = Paste;
    //std::cout << "\nUn item dupa atribuire:\n" << empty_item;
    //std::cout << "\n\nTestez operatorii de egalitate: \n" << "Paste == empty_item " << (Paste == empty_item) << '\n';
    //std::cout << "Paste != Ciorba " << (Paste != Ciorba) << '\n';

    Menu_Item Limonada("Limonada", "Bauturi non-alcoolice", 15, 10003, 2, 2min );
    Menu_Item Tort("Tort", "Desert", 13, 10003, 1, 10min );

    Menu meniu;
//    std::cout << meniu;

    meniu.addItem(Ciorba );
    meniu.addItem(Paste );
    meniu.addItem( Tort );
    meniu.addItem(Limonada);

    meniu.removeItem(Tort);
//    std::cout << "Dupa remove, meniul este:\n" << meniu;

    meniu.replaceItem(Limonada, Tort);
//    std::cout << "Dupa replace, meniul este \n" << meniu;
//    std::cout << "Numarul de elemente din meniu 2 este: " << meniu.MenuLength() << '\n';

    meniu.clearMenu();
//    std::cout << "Meniul dupa clear este: " << meniu;


    std::vector<Menu_Item> lista_comanda;
    lista_comanda.reserve(5);
    lista_comanda.emplace_back( Tort );
    lista_comanda.emplace_back(Ciorba);
    lista_comanda.emplace_back(Paste);

    Order comanda1( 1, lista_comanda);
//    std::cout << comanda1;


    Order comanda2 = comanda1;
//    std::cout << "Comanda copiata este " << comanda2;

    comanda2.removeItem(Paste);

    

//    std::cout << comanda1;
//    std::cout << "Pretul comenzii cu id " << comanda2.getOrderId() << " este " << comanda2.calculate_price() << '\n';
//    std::cout << "Timpul de preparare al comenzii cu id " << comanda2.getOrderId() << " este de " << comanda2.calculate_timp_preparare_comanda() << '\n';
//    std::cout << "Timpul de preparare al comenzii cu id " << comanda1.getOrderId() << " este de " << comanda1.calculate_timp_preparare_comanda() << '\n';


    return 0;
}
