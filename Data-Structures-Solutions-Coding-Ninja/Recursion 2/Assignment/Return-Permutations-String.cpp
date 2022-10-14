// Return Permutations - String
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.size()<=0){
        string s;
        output[0]=s;
        return 1;
    }
    int smallOutput=returnPermutations(input.substr(1),output);
    int count=smallOutput;
    for(int i=0;i<smallOutput;i++){
        string temp=output[i];
        output[i]=input[0]+output[i];
        int leng=output[i].length();
        for(int j=1;j<leng;j++){
            output[count]=temp.substr(0,j)+input[0]+temp.substr(j,leng);
            count++;
        }
    }
    return count;
    
}
