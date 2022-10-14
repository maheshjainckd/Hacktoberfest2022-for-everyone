// Check AB
#include<cstring>
bool helper(char input[]){
    int leng=strlen(input);
    if(leng<=1){
        return true;
    }
    
    bool smallOutput=helper(input+1);
    if(smallOutput){
        if(input[0]=='a'){
            if(input[1]=='a'){
                return true;
            }
            else if(input[1]=='b' && input[2]=='b'){
                return true;
            }
            else{
                return false;
            }
        }
        if(input[0]=='b' && input[1]=='b'){
            if(leng==2){
                return true;
            }
            else if(input[2]=='a'){
                return true;
            }
            else{
                return false;
            }
        }
        // return true;
    }
    return smallOutput;
}
bool checkAB(char input[]) {
	// Write your code here
    if(input[0]=='a'){
        return helper(input);
    }
    else{
        return false;
    }
}
