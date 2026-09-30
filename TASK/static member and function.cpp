#include <iostream>
#include <string>

using namespace std;

class Ride
{
private:

  
    int rideID;
    double fare;

    
    static int totalRides;
    static double totalRevenue;
    static double taxRate;

public:

   
    Ride(double rideFare)
    {
       
        totalRides++;
        rideID = totalRides;


        fare = rideFare;

      
        totalRevenue = totalRevenue + fare;
    }

  
    void displayRide()
    {
        cout << "Ride ID: " << rideID << endl;
        cout << "Fare: Rs. " << fare << endl;
    }

  
    static void showCompanyData()
    {
        cout << "\n========== COMPANY DATA ==========" << endl;
        cout << "Total Rides: " << totalRides << endl;
        cout << "Total Revenue: Rs. " << totalRevenue << endl;
        cout << "Platform Tax Rate: " << taxRate << "%" << endl;
    }

   
    static void changeTaxRate(double newRate)
    {
        if (newRate >= 0)
        {
            taxRate = newRate;
            cout << "\nTax rate changed successfully!" << endl;
        }
        else
        {
            cout << "\nInvalid tax rate!" << endl;
        }
    }
};


int Ride::totalRides = 0;
double Ride::totalRevenue = 0.0;
double Ride::taxRate = 10.0;


int main()
{
    cout << "====================================" << endl;
    cout << "       RIDE SHARING SYSTEM" << endl;
    cout << "    STATIC MEMBER DEMONSTRATION" << endl;
    cout << "====================================" << endl;


    // Create Ride objects
    Ride ride1(500);
    Ride ride2(750);
    Ride ride3(1000);



    cout << "\n========== RIDE 1 ==========" << endl;
    ride1.displayRide();

    cout << "\n========== RIDE 2 ==========" << endl;
    ride2.displayRide();

    cout << "\n========== RIDE 3 ==========" << endl;
    ride3.displayRide();



    Ride::showCompanyData();


 
    cout << "\nChanging Platform Tax Rate to 12%..." << endl;

    Ride::changeTaxRate(12);


   
    Ride::showCompanyData();


 
    cout << "\nCreating another ride..." << endl;

    Ride ride4(1200);

    cout << "\n========== RIDE 4 ==========" << endl;
    ride4.displayRide();


    
    Ride::showCompanyData();


    cout << "\n====================================" << endl;
    cout << "           PROGRAM END" << endl;
    cout << "====================================" << endl;

    return 0;
}
