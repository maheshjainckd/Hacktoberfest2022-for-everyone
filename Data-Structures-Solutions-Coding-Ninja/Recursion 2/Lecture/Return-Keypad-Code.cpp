// Return Keypad Code
#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    string values[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int smallOutput=keypad(num/10,output);
    string helperOutput[smallOutput];
    for(int i=0;i<smallOutput;i++){
        helperOutput[i]=output[i];
    }
    int count=0;
    for(int i=0;i<smallOutput;i++){
        int stringSize=values[num%10].length();
        for(int j=0;j<stringSize;j++){
            output[count]=helperOutput[i]+values[num%10][j];
            count++;
        }
    }
    return count;
    
    
}
