// Print Permutations
#include <iostream>
#include <string>
using namespace std;
void helper(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    
    for(int i=0;i<input.length();i++){
        string newOutput=output+input[i];
        string newInput=input;
        newInput.erase(i,1);
        helper(newInput,newOutput);
    }
}
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    helper(input,output);
}