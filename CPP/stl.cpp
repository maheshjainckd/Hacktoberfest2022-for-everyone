#include<iostream>
#include<array>
using namespace std;
int main(){
array<int,4>a = {1,2,3,4};
int size =a.size();
for(int i=0;i<size;i++){

cout<<a[i]<<endl;

}
cout<<"emp"<<a.empty()<<endl;
cout<<"psu"<<a.front()<<endl;
cout<<"djf"<<a.back()<<endl;
cout<<"dc"<<a.at(2)<<endl;

return 0;
}