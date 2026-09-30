#include <iostream>

using namespace std;


// ======================================================
// Q1: SHAPE AREA - RUNTIME POLYMORPHISM
// ======================================================


class Shape
{
public:

   
    virtual double area() = 0;

    
    virtual ~Shape()
    {
    }
};



class Rectangle : public Shape
{
private:
    double length;
    double width;

public:

    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

   
    double area()
    {
        return length * width;
    }
};



class Circle : public Shape
{
private:
    double radius;

public:

    Circle(double r)
    {
        radius = r;
    }

    
    double area()
    {
        return 3.14159 * radius * radius;
    }
};


// ======================================================
// Q2: NEO-TOKYO CENTRALIZED FLEET CONTROLLER
// ======================================================


class Vehicle
{
private:
    double fuel;

protected:

    
    double getFuel()
    {
        return fuel;
    }

   
    void consumeFuel(double amount)
    {
        if (amount <= fuel)
        {
            fuel = fuel - amount;
        }
    }

public:

    
    Vehicle(double initialFuel)
    {
        fuel = initialFuel;
    }

  
    void showFuel()
    {
        cout << "Current Fuel: " << fuel << " units" << endl;
    }

    
    virtual void move() = 0;


    virtual ~Vehicle()
    {
    }
};



class Drone : public Vehicle
{
public:

    Drone(double fuel)
        : Vehicle(fuel)
    {
    }

   
    void move()
    {
        cout << "\nDrone attempting to move..." << endl;

  
        if (getFuel() >= 10)
        {
            
            consumeFuel(5);

            cout << "Drone moved successfully." << endl;
            cout << "5 units of fuel consumed." << endl;
        }
        else
        {
            cout << "Drone cannot move!" << endl;
            cout << "At least 10 units of fuel are required." << endl;
        }
    }
};



class Train : public Vehicle
{
public:

    Train(double fuel)
        : Vehicle(fuel)
    {
    }

   
    void move()
    {
        cout << "\nTrain attempting to move..." << endl;

       
        if (getFuel() > 0)
        {
       
            if (getFuel() >= 10)
            {
                consumeFuel(10);

                cout << "Train moved successfully." << endl;
                cout << "10 units of fuel consumed." << endl;
            }
            else
            {
                cout << "Train cannot complete the move." << endl;
                cout << "10 units of fuel are required for one move." << endl;
            }
        }
        else
        {
            cout << "Train cannot move!" << endl;
            cout << "No fuel available." << endl;
        }
    }
};


// ======================================================
// MAIN FUNCTION
// ======================================================

int main()
{
    // ==================================================
    // Q1: SHAPE AREA
    // ==================================================

    cout << "========================================" << endl;
    cout << "       Q1: SHAPE AREA SYSTEM" << endl;
    cout << "        RUNTIME POLYMORPHISM" << endl;
    cout << "========================================" << endl;

   
    Rectangle rectangle(10, 5);
    Circle circle(7);


    Shape *shape;

   
    shape = &rectangle;

    cout << "\nRectangle Area = " << shape->area() << endl;

 
    shape = &circle;

    cout << "Circle Area = " << shape->area() << endl;


    // ==================================================
    // Q2: NEO-TOKYO FLEET CONTROLLER
    // ==================================================

    cout << "\n\n========================================" << endl;
    cout << "       Q2: NEO-TOKYO FLEET CONTROLLER" << endl;
    cout << "        RUNTIME POLYMORPHISM" << endl;
    cout << "========================================" << endl;


    
    Drone drone(25);
    Train train(40);

    
    Vehicle *vehicle;


    // ==================================================
    // CONTROL DRONE
    // ==================================================

    cout << "\n========== DRONE ==========" << endl;

    vehicle = &drone;

    cout << "Initial ";
    vehicle->showFuel();

    vehicle->move();

    cout << "After Move ";
    vehicle->showFuel();


    // ==================================================
    // CONTROL TRAIN
    // ==================================================

    cout << "\n========== TRAIN ==========" << endl;

    vehicle = &train;

    cout << "Initial ";
    vehicle->showFuel();

    vehicle->move();

    cout << "After Move ";
    vehicle->showFuel();


    // ==================================================
    // MOVE DRONE AGAIN
    // ==================================================

    cout << "\n========== DRONE SECOND MOVE ==========" << endl;

    vehicle = &drone;

    vehicle->move();

    cout << "After Second Move ";
    vehicle->showFuel();


    // ==================================================
    // MOVE TRAIN AGAIN
    // ==================================================

    cout << "\n========== TRAIN SECOND MOVE ==========" << endl;

    vehicle = &train;

    vehicle->move();

    cout << "After Second Move ";
    vehicle->showFuel();


    // ==================================================

    cout << "\n========================================" << endl;
    cout << "          PROGRAM COMPLETED" << endl;
    cout << "========================================" << endl;

    return 0;
}
