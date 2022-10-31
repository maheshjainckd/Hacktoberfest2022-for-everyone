//OOPs in c++
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class student{
    public:
    string name;
    int age;
    bool gender;

    
    void printInfo(){
         cout<<"Name= ";
         cout<<name<<endl;
         cout<<"Age= ";
         cout<<age<<endl;
         cout<<"Gender= ";
         cout<<gender<<endl;
     

    }
};
int main()
{
    // student a;
    // a.name="Ayush";
    // a.age=19;
    // a.gender=1;
    // cout<<a.name<<endl;
    // cout<<a.age<<endl;
    // cout<<a.gender<<endl;

    // Second method to take all liat of students in a array
    
    student arr[3];
    for(int i=0;i<3;i++){
        cout<<"Enter Name\n";
        cin>>arr[i].name;
         cout<<"Enter Age\n";
         cin>>arr[i].age;
          cout<<"Enter gender\n";
          cin>>arr[i].gender;
    }
    for(int i=0;i<3;i++){
        arr[i].printInfo();
    }
 
    return 0;
}