#include <iostream>
#include <string>

using namespace std;


class BankAccount
{
    private:
        string name;
        string account;
        double balance;
    public:
        BankAccount(string n, string a, double b = 0.0)
        {
            name = n;
            account = a ;
            balance = b;
        }
        void show() const
        {
            cout <<"name: " << name << endl;
            cout <<"account: " << account << endl;
            cout <<"balance: " << balance << endl;
        }
        void deposit(double cash)
        {
            balance += cash;
        }
        void withdraw(double cash)
        {
            balance -= cash;
        }
};

int main()
{
    BankAccount b("ryan", "tanrunjie", 1000.0);
    b.show();
    b.deposit(2000);
    b.withdraw(500);
    b.show();
    return 0;
}