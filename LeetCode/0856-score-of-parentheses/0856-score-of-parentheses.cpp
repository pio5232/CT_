class Solution {
public:

    int go(const int start, const vector<int>& info)
    {
        int s = start+1;
        const int end = info[start];
        // cout << format("[go] start : {}, end : {}\n",start, end );
        // ()
        if(s == end)
            return 1;
        
        int ret = 0;
        while(s< end)
        {
            ret += go(s,info);

            s = info[s]+1;
        }
        
        return 2*ret;
    }
    int scoreOfParentheses(string s) {
        
        stack<int> idx_stack;
        vector<int> info(s.size(), -1);

        for(int i =0; i<s.size(); i++)
        {
            if(s[i] == '(')
            {
                idx_stack.push(i);
            }
            else
            {
                // (에 해당하는 )인덱스 연결
                // cout << format("[{}] : {}\n",idx_stack.top(), i);
                info[idx_stack.top()] = i;
                idx_stack.pop();

            }
        }

        // divide n conquer
        int ret = 0;
        int start = 0;

        while(start<s.size())
        {
            ret += go(start, info);
            start = info[start]+1;
        }
        return ret;
    }
};