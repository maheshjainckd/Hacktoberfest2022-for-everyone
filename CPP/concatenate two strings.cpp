#include <iostream>
using namespace std;

int main()
{
    // declare and initialize the string   
    char str1[100] = " Hacktoberfest";
    char str2[100] = " 2022";
    int i, j; // declare variable  

    cout << " The first string is: " << str1 << endl;
    cout << " The second string is: " << str2 << endl;
    for (i = 0; str1[i] != '\0'; i++);
    j = 0; // initialize j with 0;  

    // use while loop that insert the str2 characters in str1  
    while (str2[j] != '\0') // check str2 is not equal to null  
    {
        str1[i] = str2[j]; // assign the character of str2 to str1  
        i++;
        j++;
    }
    str1[i] = '\0';
    cout << " The concatenated string is: " << str1;
    return 0;
}
