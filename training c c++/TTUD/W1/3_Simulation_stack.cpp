/*
Mô tả
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

string s;
stack<int> st;
queue<string> pop_res;
int a;

void input()
{
    while (1)
    {
        cin >> s;

        if (s == "#")
        {
            break;
        }
        else if (s == "PUSH")
        {
            cin >> a;
            st.push(a);
        }
        else if (s == "POP")
        {
            if (!st.empty())
            {
                pop_res.push(to_string(st.top()));
                st.pop();
            }
            else
            {
                pop_res.push("NULL");
            }
        }
    }
}

void output()
{
    while (!pop_res.empty())
    {
        cout << pop_res.front() << endl;
        pop_res.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();

    output();

    return 0;
}