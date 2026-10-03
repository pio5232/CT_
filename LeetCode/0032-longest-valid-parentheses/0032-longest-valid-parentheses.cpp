class Solution {
public:
    int longestValidParentheses(string s) {

        // 일단 ( => ++ /  ) => --
        int max_len = 0;
        // hoxy ? index stack?
        stack<int> idx_stack;
        idx_stack.push(-1);
        
        for(int i =0;i< s.size();i++)
        {
            char c = s[i];
            int top = idx_stack.top();
            if(c == ')')
            {
                if(top >= 0 && s[top] == '(')
                {
                    idx_stack.pop();
                    top = idx_stack.top();

                    max_len = max(max_len, i - top);
                    continue;
                }
            }
            
            idx_stack.push(i);
        }

        return max_len;
    }
};