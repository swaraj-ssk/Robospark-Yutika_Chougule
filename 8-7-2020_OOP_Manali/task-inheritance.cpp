#include<bits/stdc++.h>
using namespace std;


class personalData{
    protected:
    string name, surname, address, DOB, mobile_num;

    //default constructor
    personalData(){
        name= "NONE";
        surname= "NONE";
        address= "Field empty";
        DOB="DD/MM/YYYY";
        mobile_num= "xxxxxxxxxx";
    }

    public:
    void getPersonal()
    {
        cout<<" Enter Personal details of student: ";
        cout<<"\n NAME: ";
        cin>>name;
        cout<<" SURNAME: ";
        cin>>surname;
        cout<<" ADDRESS: ";
        cin>>address;
        cout<<" Date Of Birth : ";
        cin>>DOB;
        cout<<" Contact Detail: ";
        cin>>mobile_num;
    }
    
    void displayPersonal()
    {
        cout<<" Personal details are: "<<endl;
        cout<<" Name: "<< name<<endl;
        cout<<" Surname: "<<surname<<endl;
        cout<<" Address: " <<address<<endl;
        cout<<" Date of Birth: "<<DOB<<endl;
        cout<<" Contact Detail: "<<mobile_num<<endl;
    }
};
class academicData{
    protected:
    string year, college_name, branch;
    float cgpa;

    //default constructor
    academicData()
    {
        college_name="VIT";
        cgpa= 0;
    }

    public:
    void getAcademic(){
        cout<<" Enter Academic Details: ";
        cout<<"\n Year of passing: ";
        cin>>year;
        cout<<" College name: ";
        cin>>college_name;
        cout<<" Branch: ";
        cin>>branch;
        cout<<" CGPA: ";
        cin>>cgpa;
    }

    void displayAcademic()
    {
        cout<<" Academic details are: "<<endl;
        cout<<" Year of passing: "<<year<<endl;
        cout<<" Name of college: "<<college_name<<endl;
        cout<<" Branch: "<<branch<<endl;
        cout<<" CGPA: "<<cgpa<<endl;

    }

};
class professionalData{
    protected:
    string organization, job_profile, project;

    public:
    void getProfessional(){
        cout<<" Enter Professional Data: "<<endl;
        cout<<"\n Name of Organizatio: ";
        cin>>organization;
        cout<<" Job Profile: ";
        cin>>job_profile;
        cout<<" Project Name: ";
        cin>>project;
    }

    void displayProfessional(){
        cout<<" Professional details are: "<<endl;
        cout<<" Name of organization: "<<organization<<endl;
        cout<<" Job profile: "<<job_profile<<endl;
        cout<<" Project Name: "<<project<<endl;
    }
};

//multiple inheritance
class biodata: protected personalData, protected academicData, protected professionalData{
    public:
        void getdata(){
            this->getPersonal();
            this->getAcademic();
            this->getProfessional();
        }
        void display(){
            this->displayPersonal();
            this->displayAcademic();
            this->displayProfessional();
        }

};

int main()
{
    biodata B;
    B.getdata();
    B.display();
}
