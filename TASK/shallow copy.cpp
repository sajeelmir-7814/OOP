#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    int employeeID;
    double *salary;

public:

    
    Employee(int id, double sal)
    {
        employeeID = id;

        salary = new double;
        *salary = sal;
    }

   
    Employee(Employee &obj)
    {
        employeeID = obj.employeeID;
        salary = obj.salary;
    }

    
    void setSalary(double sal)
    {
        *salary = sal;
    }

   
    void display()
    {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: Rs. " << *salary << endl;
        cout << "Salary Memory Address: " << salary << endl;
    }

    ~Employee()
    {
        // Memory is not deleted here because
        // shallow copy objects share the same memory.
    }
};




class EmployeeDeep
{
private:
    int employeeID;
    double *salary;

public:

  
    EmployeeDeep(int id, double sal)
    {
        employeeID = id;

        salary = new double;
        *salary = sal;
    }

    
    EmployeeDeep(const EmployeeDeep &obj)
    {
        employeeID = obj.employeeID;

     
        salary = new double;

        
        *salary = *(obj.salary);
    }

  
    void setSalary(double sal)
    {
        *salary = sal;
    }

   
    void display()
    {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Salary: Rs. " << *salary << endl;
        cout << "Salary Memory Address: " << salary << endl;
    }


    ~EmployeeDeep()
    {
        delete salary;
    }
};




int main()
{
    cout << "========================================" << endl;
    cout << "     SHALLOW COPY AND DEEP COPY" << endl;
    cout << "========================================" << endl;


   

    cout << "\n========== SHALLOW COPY ==========" << endl;

    Employee employee1(101, 50000);

  
    Employee employee2(employee1);

    cout << "\nBefore changing copied object:" << endl;

    cout << "\nEmployee 1:" << endl;
    employee1.display();

    cout << "\nEmployee 2:" << endl;
    employee2.display();


  
    cout << "\nChanging Employee 2 salary to Rs. 70000..." << endl;

    employee2.setSalary(70000);


    cout << "\nAfter changing Employee 2:" << endl;

    cout << "\nEmployee 1:" << endl;
    employee1.display();

    cout << "\nEmployee 2:" << endl;
    employee2.display();



    cout << "\n\n========== DEEP COPY ==========" << endl;

    EmployeeDeep employee3(102, 50000);

    
    EmployeeDeep employee4(employee3);

    cout << "\nBefore changing copied object:" << endl;

    cout << "\nEmployee 3:" << endl;
    employee3.display();

    cout << "\nEmployee 4:" << endl;
    employee4.display();


    
    cout << "\nChanging Employee 4 salary to Rs. 70000..." << endl;

    employee4.setSalary(70000);


    cout << "\nAfter changing Employee 4:" << endl;

    cout << "\nEmployee 3:" << endl;
    employee3.display();

    cout << "\nEmployee 4:" << endl;
    employee4.display();


    cout << "\n========================================" << endl;
    cout << "             PROGRAM END" << endl;
    cout << "========================================" << endl;

    return 0;
}
