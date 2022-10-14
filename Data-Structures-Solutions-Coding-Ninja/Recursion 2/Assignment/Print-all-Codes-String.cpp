// Print all Codes - String
#include <string.h>
using namespace std;
void helper(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    int intSingle=input[0]-48;
    char single=intSingle+'a'-1;
    string newOutput;
    newOutput=newOutput+output;
    output=output+single;
    helper(input.substr(1),output);
    if(input.length()>=2){
        int intDouble=(input[0]-48)*10+(input[1]-48);
        if(intDouble>=10 && intDouble<=26){
            char doubly=intDouble+'a'-1;
            // string newOutput;
            // for(int i=0;i<output.length();i++){
            //     newOutput[i]=output[i];
            // }
            newOutput=newOutput+doubly;
            helper(input.substr(2),newOutput);
        }
    }
}
void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output;
    helper(input,output);
}

