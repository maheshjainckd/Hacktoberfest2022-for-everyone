// String to Integer
#include<cstring>
#include<cmath>
int stringToNumber(char input[]) {
    // Write your code here
    if(strlen(input)==1){
        int a=input[0]-48;
        return a;
    }
    int smallOutput=stringToNumber(input+1);
    int a=input[0]-48;
    int ans;
    ans=a*pow(10,strlen(input)-1)+smallOutput;
    
    return ans;
}
