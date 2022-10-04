
// C++ program to check for balanced brackets.
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to check if brackets are balanced
bool areBracketsBalanced(string str)
{
    // Declare a stack to hold the previous brackets.
    stack<char> temp;
    for (int i = 0; i < str.length(); i++) {
        if (temp.empty()) {
             
            // If the stack is empty
            // just push the current bracket
            temp.push(str[i]);
        }
        else if ((temp.top() == '(' && str[i] == ')')
                 || (temp.top() == '{' && str[i] == '}')
                 || (temp.top() == '[' && str[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            temp.pop();
        }
        else {
            temp.push(str[i]);
        }
    }
    if (temp.empty()) {
         
        // If stack is empty return true
        return true;
    }
    return false;
}
 

int main()
{
    string str = "";
    cin>>str;

    if (areBracketsBalanced(str))
        cout << "It is Valid parenthesis";
    else
        cout << "It is not valid parenthesis";
    return 0;
}