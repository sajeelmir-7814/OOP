#include <iostream>
using namespace std;
class student{
	protected:
	string name;
	int rollno;
	string address;
	public:
	void setdata() {
	cout<<"Enter your name: "<<endl;
	cin>>name;
	cout<<"Enter your Rollno: "<<endl;
	cin>>rollno;
	cout<<"Enter your Address: "<<endl;
	cin>>address;
	}
};
class subject{
	public:
	string offer_subject;
	int semester_year;
	void setdata(){
	cout<<"Enter your offer subject: "<<endl;
	cin>>offer_subject;
	cout<<"Enter your semster year: "<<endl;
	cin>>semester_year;
	}
};
class result{
	public:
	float gpa;
	
	
	void setdata(){
	gpa=3.45;
	}
	void display(float a){
	cout<<"GPA: "<<gpa<<endl;
	}
}; 
int main(){
	student s1;
	s1.setdata();
	subject s2;
	s2.setdata();
	result s3;
	s3.setdata();
	s3.display(3.45);
	
}

