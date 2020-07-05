#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll_no;
    int *marks= new int[5]; //dynamic array
    float cgpa;

    //default constructor
    Student()
    {
        name= "None";
        roll_no= 0;
        cgpa= 0;
    }

    void getInput() //taking user input
    {
        cout<<"Enter Student details:\n";
        cout<<"Enter Name: ";
        cin>> name;
        cout<<"Enter Roll.No: ";
        cin>> roll_no;
        cout<<"Enter marks: ";
        for(int i=0; i<5; i++)
        {
            cin>>marks[i];
        }
    }

    int total() //function to find total marks
    {
        int sum=0;
        for(int i=0;i<5;i++)
        {
            sum+= marks[i];
        }
        return sum;
    }

    float CGPA() //function to fins cgpa
    {
        float percentage= total()/5;
        float cgpa= percentage/9.5;
        delete marks; //free the memory allocated to marks
        return cgpa;
    }

     void showDetails(int total, float cgpa) //print student data
    {
        cout << "Name: " << name << "\n";
        cout << "Roll No: " << roll_no << endl;
        cout << "Total marks:"<< total << endl;
        cout << "CGPA: "<< cgpa <<endl;
    }
    
};

int main()
{
    Student s; //create  an object of student class
    s.getInput();
    int total_marks = s.total();
    float cgpa = s.CGPA();
    s.showDetails(total_marks, cgpa);
}