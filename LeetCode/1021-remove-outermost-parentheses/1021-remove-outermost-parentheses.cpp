class Solution {
public:
    string removeOuterParentheses(string s) {
        string ret = "";
        stack<int> _stack;

        for(int i =0;i<s.size();i++)
        {
            if(s[i] == '(')
                _stack.push(i);
            else
            {
                int t = _stack.top();
                
                _stack.pop();
                
                if(_stack.empty())
                    ret += s.substr(t+1, i-t-1);
            }
        }

        return ret;
    }
};