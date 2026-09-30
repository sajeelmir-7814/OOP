#include <iostream>
#include <string>

using namespace std;


class Account
{
private:
    string accountNumber;
    double balance;

protected:
    
    double getBalance()
    {
        return balance;
    }

    void setBalance(double newBalance)
    {
        balance = newBalance;
    }

public:
  
    Account(string accNo, double bal)
    {
        accountNumber = accNo;
        balance = bal;
    }

   
   
    virtual void withdraw(double amount) = 0;

    
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Amount deposited successfully." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

  
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

  
    virtual ~Account()
    {
    }
};



class SavingsAccount : public Account
{
public:

    SavingsAccount(string accNo, double bal)
        : Account(accNo, bal)
    {
    }

    
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > getBalance())
        {
            cout << "Insufficient balance!" << endl;
        }
        else
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful from Savings Account." << endl;
        }
    }
};



class CurrentAccount : public Account
{
public:

    CurrentAccount(string accNo, double bal)
        : Account(accNo, bal)
    {
    }

    
    void withdraw(double amount)
    {
    
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > getBalance() + 5000)
        {
            cout << "Withdrawal exceeds the allowed limit!" << endl;
        }
        else
        {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful from Current Account." << endl;
        }
    }
};


int main()
{
    cout << "====================================" << endl;
    cout << "       BANK ACCOUNT SYSTEM" << endl;
    cout << "====================================" << endl;

   
    SavingsAccount savings("SA-1001", 20000);
    CurrentAccount current("CA-2001", 10000);

    cout << "\n========== SAVINGS ACCOUNT ==========" << endl;

    savings.display();

    cout << "\nDepositing Rs. 5000..." << endl;
    savings.deposit(5000);

    cout << "\nWithdrawing Rs. 8000..." << endl;
    savings.withdraw(8000);

    cout << "\nUpdated Savings Account:" << endl;
    savings.display();



    cout << "\n\n========== CURRENT ACCOUNT ==========" << endl;

    current.display();

    cout << "\nDepositing Rs. 3000..." << endl;
    current.deposit(3000);

    cout << "\nWithdrawing Rs. 15000..." << endl;
    current.withdraw(15000);

    cout << "\nUpdated Current Account:" << endl;
    current.display();


    cout << "\n====================================" << endl;
    cout << "           PROGRAM END" << endl;
    cout << "====================================" << endl;

    return 0;
}
