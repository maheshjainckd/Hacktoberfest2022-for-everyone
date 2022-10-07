#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)
{
    int n = s.length();
    bool ans = true;
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }

        else
        {
            if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }

            if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }

            if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }

                else
                {
                    ans = false;
                    break;
                }
            }
        }
    }

    if (!st.empty())
    {
        ans = false;
    }

    return ans;
}

int main()
{
    bool res = isValid("({[]})");

    if (res)
        cout << "valid string" << endl;
    else
        cout << "invalid string" << endl;
}
