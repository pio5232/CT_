#include<string>
#include <iostream>
#include <stack>
using namespace std;

stack<char> s;
bool solution(string str)
{
    bool answer = true;
    
    for(char c : str)
    {
        if(s.size() && s.top() == '(' && c == ')')
        {
            s.pop();
        }
        else
        {
            s.push(c);
        }
    }
    if(s.size())
        answer = false;

    return answer;
}