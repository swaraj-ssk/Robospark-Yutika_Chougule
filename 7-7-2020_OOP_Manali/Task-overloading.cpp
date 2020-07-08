#include<bits/stdc++.h>
using namespace std;

class String{
    
    
    string var;
    public:
        String ()
        {
            var= "none";
        }
        String(string s)
        {
            var = s;
        }
        String operator+ (string str);
        String operator* (int num);
        void display();
        friend istream& operator>> (istream& cin, String &s);
        friend ostream& operator<< (ostream& cout, String &s);
};
ostream& operator<< (ostream& cout, String &s)
{
    cout<< "String Output: ";
    cout<<s.var <<endl;
    return cout;
}
istream& operator>> (istream& cin, String &s)
{
    cout<<"Enter string";
    cin>> s.var;
    return cin;
}

String String::operator+(string str)
{
    String temp= *this;
    string s= temp.var;
    temp.var += str;
    return temp;
}

String String::operator*(int num)
{
    String temp= *this;
    string s= temp.var;
    for(int i=1; i<num; i++)
    {
        temp.var= temp.var+s;
    }
    return temp;
}

void String::display()
{
    cout<<var<<endl;
}

int main()
{
    String s;
    cin>>s;
    cout<<s;
    String s1("Hello");
    
    String s3= s1+ " there ";
    s3.display();

    String s4= s1*5;
    s4.display();
}