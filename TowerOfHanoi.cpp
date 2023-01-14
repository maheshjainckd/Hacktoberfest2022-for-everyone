#include <iostream>

using namespace std;

void moveTowerOfHanoi(int num, char source, char helper, char destination)
{
    if(num == 0)
    {
        return;
    }
    
    moveTowerOfHanoi((num-1),source, destination, helper);

    cout << "Move disk:  " << num << " from  " << source << " to  " << destination << endl;

    moveTowerOfHanoi((num-1),helper,source,destination);
}




int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    
    moveTowerOfHanoi(n,'A','B','C');

    return 0;
}
