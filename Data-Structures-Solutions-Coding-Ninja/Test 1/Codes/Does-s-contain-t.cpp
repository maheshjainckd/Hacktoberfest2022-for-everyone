// Does s contain t ?
bool checksequenece(char large[] , char*small) {
    if(large[0]=='\0'){
        return false;
    }
    if(large[0]==small[0]){
        int i=0;
        int j=0;
        while(large[j]!='\0' && small[i]!='\0'){
            if(small[i]!=large[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        if(small[i]=='\0'){
            return true;
        }
        if(large[j]=='\0'){
            return false;
        }
    }
    return checksequenece(large+1,small);
}
