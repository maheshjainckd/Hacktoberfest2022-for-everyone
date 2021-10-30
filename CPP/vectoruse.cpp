#include<iostream>
#include<vector>
using namespace std;

int main(){
    // vector <int> *vp = new vector<int>();  dynamically allocated
    vector<int> v;

    for(int i=0;i<100;i++){
       cout<<"cap : "<< v.capacity()<<endl;
       cout<<"size : "<< v.size()<<endl;
       v.push_back(i+1);
 
    }

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[1]=100;
 
 /* don't use for inserting element
    v[2]=200;
    v[3]=300;
*/
    v.push_back(40);
    v.push_back(50);
/*
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;

    cout<<"size : "<< v.size()<<endl;

    cout<< v.at(2)<<endl;
    cout<< v.at(6)<<endl;
*/

for(int i =0; i<v.size();i++){
    cout<<v[i]<<endl;
}


    return 0;

}
