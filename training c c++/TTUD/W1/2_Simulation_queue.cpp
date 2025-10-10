/*
Mô tả
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
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
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4
*/

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
queue<string> pop_res;
string s;
int a;

void input()
{

    while (1)
    {
        cin >> s;

        if (s == "PUSH")
        {
            cin >> a;
            q.push(a);
        }
        else if (s == "POP")
        {
            if (!q.empty())
            {
                pop_res.push(to_string(q.front()));
                q.pop();
            }
            else
            {
                pop_res.push("NULL");
            }
        }
        else if (s == "#")
        {
            break;
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
