#include<iostream>
#include<vector>

using namespace std;
int main(){
vector<int> v;
vector<int>last(a);
vector<int> a(5,1);
cout<<"a"<<"";
for(int i:last){
    cout<<i<<" "<<endl;
}cout<<endl;
cout<<"cap"<<v.capacity()<<endl;
v.push_back(1);
cout<<v.size()<<endl;

cout<<"cap"<<v.capacity()<<endl;
v.push_back(2);

cout<<"cap"<<v.capacity()<<endl;
v.push_back(3);

cout<<"cap"<<v.capacity()<<endl;
cout<<v.size()<<endl;
cout<<v.front()<<endl;
cout<<v.back()<<endl;
cout<<"HJBBHJGD"<<v.at(2)<<endl;

cout<<"before pop"<<endl;
for(int i:v){

    cout<<i<<endl;
}cout<<endl;
v.pop_back();
cout<<"after pop"<<endl;
for(int i:v){
    cout<<i<<endl;

}cout<<endl;

cout<<"before"<<v.size()<<endl;
v.clear();
cout<<"after"<<v.size()<<endl;
return 0;
}