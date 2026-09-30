#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

class Account
{
private:
    string accountNumber;
    double balance;

public:


    Account(string accNo, double bal)
    {
        accountNumber = accNo;
        balance = bal;
    }


    Account operator+(Account obj)
    {
        double totalBalance = balance + obj.balance;

        string newAccountNumber = "Combined_" + accountNumber;

        return Account(newAccountNumber, totalBalance);
    }

   
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    
    srand(time(0));

    string name1, name2;
    double balance1, balance2;

    cout << "====================================" << endl;
    cout << "        BANKING SYSTEM" << endl;
    cout << "   OPERATOR OVERLOADING (+)" << endl;
    cout << "====================================" << endl;

   
    cout << "\nEnter Account Holder 1 Name: ";
    getline(cin, name1);

    cout << "Enter Balance for Account 1: Rs. ";
    cin >> balance1;

   
    int randomNumber1 = 10000 + rand() % 90000;

    stringstream ss1;
    ss1 << "ACC" << randomNumber1;
    string accNo1 = ss1.str();

    cin.ignore();


    cout << "\nEnter Account Holder 2 Name: ";
    getline(cin, name2);

    cout << "Enter Balance for Account 2: Rs. ";
    cin >> balance2;

   
    int randomNumber2 = 10000 + rand() % 90000;

    stringstream ss2;
    ss2 << "ACC" << randomNumber2;
    string accNo2 = ss2.str();

  
    Account account1(accNo1, balance1);
    Account account2(accNo2, balance2);

   
    cout << "\n\n========== ACCOUNT 1 ==========" << endl;
    cout << "Name: " << name1 << endl;
    account1.display();

    
    cout << "\n========== ACCOUNT 2 ==========" << endl;
    cout << "Name: " << name2 << endl;
    account2.display();

    
    Account combinedAccount = account1 + account2;


    cout << "\n========== COMBINED ACCOUNT ==========" << endl;
    combinedAccount.display();

    cout << "\n====================================" << endl;
    cout << "Account balances successfully added!" << endl;
    cout << "====================================" << endl;

    return 0;
}
