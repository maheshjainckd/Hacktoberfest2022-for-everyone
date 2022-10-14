// Remove X
#include<iostream>
#include<cstring>
using namespace std;
void removeX(char input[]) {
    // Write your code here
    int leng=strlen(input);
    // cout<<leng<<endl;
    if(leng<=0){
        return;
    }
    removeX(input+1);
    int len2=strlen(input);
    // cout<<len2<<endl;
    if(input[0]=='x'){
        for(int i=0;i<len2-1;i++){
            input[i]=input[i+1];
        }
        input[len2-1]='\0';
    }
    
    
}
