// Pair Star
#include<cstring>
void pairStar(char input[]) {
    // Write your code here
    int leng=strlen(input);
    if(leng==1){
        return;
    }
    pairStar(input+1);
    if(input[0]==input[1]){
        for(int i=strlen(input);i>=1;i--){
            input[i+1]=input[i];
        }
        input[1]='*';
    }
}
