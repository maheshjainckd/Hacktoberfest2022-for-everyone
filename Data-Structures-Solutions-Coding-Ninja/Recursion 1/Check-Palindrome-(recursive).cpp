//Check Palindrome
bool helper(char input[],int s,int e){
    if(e-s<=0){
        return true;
    }
    if(input[s]!=input[e]){
        return false;
    }
    return helper(input,s+1,e-1);
}


bool checkPalindrome(char input[]) {
    // Write your code here
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    i--;
    helper(input,0,i);
}