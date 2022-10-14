// Print Keypad Combinations Code
#include <iostream>
#include <string>
using namespace std;
void helper(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    string values[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(int i=0;i<values[num%10].length();i++){
        helper(num/10,values[num%10][i]+output);
    }
}
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    helper(num,"");
    
}
