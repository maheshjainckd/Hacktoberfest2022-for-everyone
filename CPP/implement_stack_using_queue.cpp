#include<bits/stdc++.h>
using namespace std;
class Mystack
{
    queue<int> s1,s2;
    public:
        int top()
        {
            return s1.front();
        }
        void pop()
        {
            s1.pop();
        }
        bool is_empty()
        {
            return s1.empty();
        }
        int size()
        {
            return s1.size();
        }
        void push(int x)
        {
            while(s1.empty()!=1)
            {
                s2.push(s1.front());
                s1.pop();
            }
            s1.push(x);
            while(s2.empty()!=1)
            {
                s1.push(s2.front());
                s2.pop();
            }
        }
};
int main()
{
    Mystack st;
    st.push(2);
    cout<<st.top()<<endl;
    cout<<"size="<<st.size()<<endl;
    st.push(3);
    cout<<st.top()<<endl;
    cout<<"size="<<st.size()<<endl;
    st.push(4);
    cout<<st.top()<<endl;
    cout<<"size="<<st.size()<<endl;
    st.push(5);
    cout<<st.top()<<endl;
    cout<<"size="<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

}
