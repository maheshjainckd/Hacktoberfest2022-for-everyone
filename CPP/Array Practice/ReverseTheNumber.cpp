#include <iostream>
using namespace std;

int main()
{
    //Taking input from the user..
    int n;
    cout << "Enter Number : ";
    cin >> n;

    int reverse = 0; //I have made a variable 'reverse' in which i will reverse and store the number..
    
    while (n > 0) 
    {
        int lastdigit = n % 10; //To find lastdigit i have made a variable 'lastdigit' which is equal to n%10..
        reverse = reverse * 10 + lastdigit; //Suppose the lastdigit is 4.. so in next iteration the last digit will become 3 and so on..
        n = n / 10; //I have used this to remove the lastdigit.. so in next iteration we can get the previous number..
    }
    /* The above while loop will run until N becomes 0 */

    cout << "The Reverse Number Is : " << reverse << endl; //To print the reversed number..
    return 0;
}