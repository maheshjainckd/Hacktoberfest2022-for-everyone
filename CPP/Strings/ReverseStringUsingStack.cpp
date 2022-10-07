#include<iostream>
#include<stack>
using namespace std;

/*
class Stack
{
  private:
    char A[101];
    int top;
  
  public:
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
    
};
*/

void Reverse(char *C, int n)      //Array or character are always passed by reference in C/C++
{
  stack<char> S;
  for(int i = 0; i < n; i++)    //Loop for push
  {
    S.push(C[i]);
  }
  for(int i = 0; i < n; i++)   //Loop for pop
  {
    C[i] = S.top();   //Overwrite the character at index i
    S.pop();          //perform pop
  }
}

int main()
{
  char C[51];
  printf("Enter a string: ");
  gets(C);
  Reverse(C, strlen(C));
  printf("Output = %s", C);
}
