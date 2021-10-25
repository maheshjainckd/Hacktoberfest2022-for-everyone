#include <iostream>
using namespace std;

//I have taken a function with some parameter..
void reverseString(string str)
{
    int s = str.length(); // If u have taken a string 'Yuvi' then its length will be four..

    // Taken start and end variable for swapping the starting and ending characters of the string..
    int start = 0;
    int end = s - 1;

    while (start < end) //While loop starts..
    {
        swap(str[start], str[end]); //I have used a built-in function swap which will swap the staring and ending characters of the string..
        start++; //Increment..
        end--; //Decrement.. 
    }
    cout << "Reversed string is : " << str; //To print the reversed string..
}

int main()
{
    //Taking input from the user..
    string str;
    cout << "Enter a string : ";
    cin >> str;

    reverseString(str); //Passing str 'parameter' in the 'reverseString' function..
    return 0;
}