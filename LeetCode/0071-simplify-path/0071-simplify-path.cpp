class Solution {
public:
    string simplifyPath(string path) {
        
        istringstream s(path);

        string split_str;
        stack<string> output_stack;

        deque<string> ans_deq;
        string ans ="";
        while(getline(s,split_str,'/'))
        {
            if(split_str == "" || split_str == ".")
                continue;
            
            if(split_str == "..")
                {
                    if(!output_stack.empty())
                        output_stack.pop();
                    continue;
                }
            output_stack.push(split_str);
        }

        if(output_stack.empty())
        {
            ans += "/";
        }
        else
        {        
            while(!output_stack.empty())
            {
                ans_deq.push_front(output_stack.top());
                output_stack.pop();
            }
        }

        while(ans_deq.size() > 0)
        {
            ans += "/" + ans_deq.front();
            ans_deq.pop_front();
        }
        return ans;
    }
};