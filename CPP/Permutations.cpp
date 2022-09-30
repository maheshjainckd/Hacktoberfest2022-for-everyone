#include <bits/stdc++.h>

using namespace std;



// Time Complexity:O(N!);


// Space Complexity:O(N) 
    
//     N=(length of string) 

void print_permutation(string permutation,string result){

    if(permutation.size()==0)cout<<result;
    
    for(int i=0;i<permutation.size();++i)
        //Here What I did is just  picked up a specific character from permutation appended to result  and then removed that character from permutation
        //This Process continues till permutation string is null
   
        print_permutation(permutation.substr(0,i)+permutation.substr(i+1,perutation.size()),result+permutation[i]);
    
}

main(){

string premutation="Hacktoberfest";
    
  print_permutation(permutation,"");  
  
}
