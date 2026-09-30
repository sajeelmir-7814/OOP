#include <iostream>
using namespace std;
class Distance{
	private:
	int feets;
	float inches;
	
	public:
	Distance (): feets(0), inches(0) {
	}
	Distance (int f, float in):feets(f), inches(in){

	}
	void display(){
	cout<<"Feets = "<<feets<<" Inches = "<<inches<<endl;
	}
	void operator ++(){
	feets++;
	inches++;
	}
	void operator ++(int){
	feets++;
	inches++;
	}
	void operator --(){
	feets--;
	inches--;
	}
	void operator --(int){
	feets--;
	inches--;
	}
	
};
int main()
{
	Distance d1(4 , 3.4);
	Distance d2(8 , 8.5);
	cout<<"Before ++ "<<endl;
	cout<<"d1= ";d1.display();
	cout<<"d2= ";d2.display();
	cout<<"After ++ "<<endl;
    d1.operator ++();
    d2.operator ++(); 
    cout<<"d1= ";d1.display();
    cout<<"d2= ";d2.display();
    
    cout<<"After -- "<<endl;
    d1.operator --();
    d2.operator --(); 
    cout<<"d1= ";d1.display();
    cout<<"d2= ";d2.display();
	
}
