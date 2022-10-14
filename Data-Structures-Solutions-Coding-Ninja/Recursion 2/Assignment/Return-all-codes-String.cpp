// Return all codes - String
#include <string.h>
using namespace std;
int helper(string input, string output[100000], int start)
{
    if (input.length() <= 0)
    {
        string newOutput;
        output[start] = newOutput;
        return start + 1;
    }
    int intSingle = input[0] - 48;
    char single = intSingle + 'a' - 1;
    // if(input.length()==1){
    //     string newOutput;
    //     newOutput[0]=single;
    //     output[start]=newOutput;
    //     return start+1;
    // }
    int count = helper(input.substr(1), output, start);

    for (int i = start; i < count; i++)
    {
        output[i] = single + output[i];
    }
    if (input.length() >= 2)
    {
        int intDouble = (input[0] - 48) * 10 + (input[1] - 48);

        if (intDouble >= 10 && intDouble <= 26)
        {
            char doubly = intDouble + 'a' - 1;
            int count2 = helper(input.substr(2), output, count);
            for (int i = count; i < count2; i++)
            {
                output[i] = doubly + output[i];
            }
            return count2;
        }
    }
    return count;
}
int getCodes(string input, string output[10000])
{
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    int ans = helper(input, output, 0);
    return ans;
}
