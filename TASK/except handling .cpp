#include <iostream>

using namespace std;

class Calculator
{
public:

  
    int add(int num1, int num2)
    {
       
        if (num1 < 0)
        {
            throw "Error: First number cannot be negative!";
        }

   
        if (num2 < 0)
        {
            throw "Error: Second number cannot be negative!";
        }

        return num1 + num2;
    }
};


int main()
{
    Calculator calc;

    int num1, num2;

    cout << "==================================" << endl;
    cout << "       SIMPLE CALCULATOR" << endl;
    cout << "       EXCEPTION HANDLING" << endl;
    cout << "==================================" << endl;

    try
    {
        cout << "\nEnter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

      
        int result = calc.add(num1, num2);

        cout << "\nResult = " << result << endl;
    }

    catch (const char* errorMessage)
    {
        cout << "\nException: " << errorMessage << endl;
    }

    cout << "\n==================================" << endl;
    cout << "          PROGRAM END" << endl;
    cout << "==================================" << endl;

    return 0;
}
