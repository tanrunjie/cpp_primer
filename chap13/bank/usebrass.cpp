#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;
    Brass Piggy("Porcelot pigg", 318299, 4000.0);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.0);
    Piggy.ViewAcct();
    std::cout << std::endl;

    Hoggy.ViewAcct();
    cout << endl;

    cout <<"Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout <<"New balance: $" << Hoggy.Balance() << endl;
    cout <<"Withdrawing $4200 from the Pigg Account: \n";
    Piggy.Withdraw(4200);
    cout <<"Pigg account balance: $" <<Piggy.Balance() << endl;
    cout <<"Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
    
    return 0;
}