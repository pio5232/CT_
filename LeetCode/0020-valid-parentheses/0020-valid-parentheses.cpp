class Solution {
public:
    bool isValid(string s) {
        stack<char> my_stack;
        for(char c : s)
        {
            switch(c)
            {
                case '(':
                case '[':
                case '{':
                my_stack.push(c);
                break;

                case ')': if(my_stack.size() && my_stack.top() == '(') my_stack.pop();
                else my_stack.push(c); break;
                case ']': if(my_stack.size() && my_stack.top() == '[') my_stack.pop();
                else my_stack.push(c); break;
                case '}': if(my_stack.size() && my_stack.top() == '{') my_stack.pop();
                else my_stack.push(c); break;
            }
        }

        return my_stack.empty();
    }
};