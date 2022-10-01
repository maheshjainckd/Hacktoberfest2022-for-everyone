#include<iostream>
#include<list>
using namespace std;
int main(){
list<int> l;
//agar es list ko copy karna nayi list me t0
list<int> n(5,500);//5 element rakhu our 100 se init kar du
cout<<"ggg"<<endl;
for(int i:n){
    cout<<i<<" "<<endl;
}cout<<endl;
l.push_back(1);
l.push_front(2);
for(int i:l){
    cout<<i<<" "<<endl;
}cout<<endl;
cout<<l.size()<<endl;

l.erase(l.begin());
cout<<"afr"<<endl;
for(int i:l){
    cout<<i<<endl;
}


return 0;
}