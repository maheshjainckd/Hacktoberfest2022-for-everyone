//Print Numbers
void print(int n){
    //write your code here
    if(n<=1){
        cout<<1<<" ";
        return;
    }
    print(n-1);
    cout<<n<<" ";
}
