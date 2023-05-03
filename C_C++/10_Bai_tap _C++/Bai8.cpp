#include <iostream>
#include <string>

using namespace std;

class Acc_Bank
{
    private:
        string acc_number;
        string acc_name;
        double balance;
    public:
        Acc_Bank(string number, string name, double initbalance);
        string get_acc_number();
        string get_acc_name();
        double get_balance();
        void deposit(double amount);
        void withdraw(double amount);
};
Acc_Bank::Acc_Bank(string number, string name, double initbalance)
{
    acc_number = number;
    acc_name = name;
    balance = initbalance;
}

string Acc_Bank::get_acc_number()
{
    return acc_number;
}
string Acc_Bank::get_acc_name()
{
    return acc_name;
}
double Acc_Bank::get_balance()
{
    return balance;
}
void Acc_Bank::deposit(double amount)
{
    balance += amount;
    cout << "Giao dich thanh cong! So du tai khoan cua ban: "<< balance << endl;
}
void Acc_Bank::withdraw(double amount)
{
    if(balance >= amount)
    {
        balance -= amount;
        cout << "Giao dich thanh cong! So du tai khoan cua ban: "<< balance << endl;
    }
    else
    {
        cout << "Giao dich that bai! So du tai khoan cua ban khong du" << endl;
    }
}

int main()
{
    Acc_Bank myAccount("617361736", "Pham Quang Linh", 10000);
    cout <<"So tai khoan: " << myAccount.get_acc_number() << endl;
    cout <<"Chu tai khoan: " << myAccount.get_acc_name() << endl;
    cout <<"So du tai khoan: " << myAccount.get_balance() << endl;

    myAccount.deposit(30000);
    myAccount.withdraw(20000);

    return 0;
}