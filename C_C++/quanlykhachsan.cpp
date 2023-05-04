#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lớp đại diện cho một món ăn trong menu
class MenuItem
{
    private:
        string name;
        double price;
    public:
        MenuItem(string name, double price);
        string getName();
        double getPrice();
        void setName(string name);
        void setPrice(double price);
};
MenuItem::MenuItem(string name, double price) 
{
    this->name = name;
    this->price = price;
}
string MenuItem::getName() 
{
    return name;
}
double MenuItem::getPrice() 
{
    return price;
}
void MenuItem::setName(string name) 
{
    this->name = name;
}
void MenuItem::setPrice(double price) 
{
    this->price = price;
}
class Room
{
    private:
        int number;
        double hourlyPrice;
        double dailyPrice;
    public:
        Room(int number);
        int getNumber();
        double getHourlyPrice();
        double getDailyPrice();
        void setHourlyPrice(double hourlyPrice);
        void setDailyPrice(double hourlyPrice);
};
Room::Room(int number) 
{
    this->number = number;
}
int Room::getNumber()
{
    return number;
}
double Room::getHourlyPrice()
{
    return hourlyPrice;
}
double Room::getDailyPrice()
{
    return dailyPrice;
}
void Room::setHourlyPrice(double hourlyPrice)
{   
    this->hourlyPrice = hourlyPrice;
}
void Room::setDailyPrice(double dailyPrice)
{
    this->dailyPrice = dailyPrice;
}
// Lớp đại diện cho menu
class Manager 
{
    private:
        vector<MenuItem> items;
        vector<Room> rooms;
    public:
        void addRoom();
        void addItem();
        void removeItem();
        void updateItem();
        void displayMenu();
};
void Manager::addRoom()
{
    int number;
    double hourlyPrice;
    double dailyPrice;
    cout << "Enter number of room:  ";
    cin >> number;
    cout << endl;
    cout << "Enter hourly price:  ";
    cin >> hourlyPrice;
    cout << endl;
    cout << "Enter daily price:  ";
    cin >> dailyPrice;
    cout << endl;
    for (int i = 1; i <= number; i++)
    {
        Room room(i);
        rooms.push_back(room);
    }
}
void Manager::addItem()
{
    string name;
    double price;

    cout <<"Enter name of item: ";
    cin >> name;
    cout <<"Enter price of item: ";
    cin >> price;
    MenuItem item(name, price);
    items.push_back(item);
}
void Manager::removeItem() 
{
    int index;
    
    cout << "Enter id of item want to delete: ";
    cin >> index;
    items.erase(items.begin() + index - 1);
}
void Manager::updateItem() 
{
    int index;
    string name; 
    double price;
    cout << "Enter id of item want to update: ";
    cin >> index;
    cout <<"Enter name of item: ";
    cin >> name;
    cout <<"Enter price of item: ";
    cin >> price;
    items[index - 1].setName(name);
    items[index - 1].setPrice(price);
}
void Manager::displayMenu() 
{
    cout << "Menu:\n";
    for (int i = 0; i < items.size(); i++) 
    {
        cout << i + 1 << ". " << items[i].getName() << " - $" << items[i].getPrice() << endl;
    }
}

class staff
{
    

};
int main() {
    // Tạo một menu mới
    Manager menu;

    // Thêm món ăn vào menu
    menu.addRoom();
    menu.addItem();
    
    // Hiển thị menu
    menu.displayMenu();

    // Xóa một món ăn khỏi menu
    menu.removeItem();
    menu.displayMenu();

    // Sửa thông tin một món ăn trong menu

    menu.updateItem();
    menu.displayMenu();

    return 0;
}
