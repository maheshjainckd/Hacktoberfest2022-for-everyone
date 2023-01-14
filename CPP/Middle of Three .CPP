
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

//1ST METHOD
class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        int x=max(A,max(B,C));
        int y=min(A,min(B,C));
        if(A>y && A<x)
        return A;
         if(B>y && B<x)
        return B;
         if(C>y && C<x)
        return C;
    }
};


//2ND METHOD
class Solution{
  public:
    int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        if(A>B && A<C) return A;
         if(B>A && B<C) return B;
          if(C>B && C<A) return C;
          if(A>C && A<B) return A;
          if(B>C && B<A) return B;
          if(C>A && C<B) return C;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends