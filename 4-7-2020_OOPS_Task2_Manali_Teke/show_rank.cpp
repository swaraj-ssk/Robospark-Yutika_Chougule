#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll_no;
    string year;

    void getInput() //function to get student details
    {
        cout<<"Enter Student details:\n";
        cout<<"Enter Name: ";
        cin>> name;
        cout<<"Enter Roll.No: ";
        cin>> roll_no;
        cout<<"Enter year: ";
        cin>> year;
    }

    void showDetails(Student s) //function to display student info
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll_no << endl;
        cout << "Year: "<< year << endl;
    }
    
    void showRank(int i) 
    {
        cout<< "Displaying rank only.\n";
        cout<< "Rank: "<< i << endl; 
    }

    void showRank(Student s)
    {
        cout<< "Displaying student details only.\n";
        showDetails(s);
    }

    void showRank(Student s, int i)
    {
        cout<< "Displaying both student details and rank. \n";
        showDetails(s);
        cout << "Rank:"<< i;
    }
};

int main()
{
    Student stud;  //create an object of Student class
    stud.getInput();
    stud.showRank(10); //passing integer parameter
    stud.showRank(stud); //passing student parameter
    stud.showRank(stud,10); //passing student and integer parameter
    
}