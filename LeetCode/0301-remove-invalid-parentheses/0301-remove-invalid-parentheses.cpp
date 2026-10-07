class Solution {
public:
    vector<string> ret;

    int l_cnt, r_cnt;


    bool chk_valid_str(const string& str)
    {
        int cnt =0;
        for(int i = 0; i<str.size(); i++)
        {
            if(str[i] == '(')
                cnt++;
            else if(str[i] == ')')
                cnt--;
            
            if(cnt < 0)
                return false;
        }

        return cnt == 0;
    }

   
    vector<string> removeInvalidParentheses(string s) {
 
        queue<string> q;
        unordered_set<string> us;

        q.push(s);
        us.insert(s);

        bool is_exist = false;
        while(q.size())
        {
            int level = q.size();

            for(int i =0;i<level;i++)
            {
                string str = q.front();
                q.pop();

                if(chk_valid_str(str))
                {    
                    ret.push_back(str);
                    is_exist = true;
                }   

                if(is_exist)
                continue;

                for(int j =0;j<str.size(); j++)
                {
                    if(str[j] != '(' && str[j] != ')')
                        continue;

                    string new_Str = str.substr(0,j)+str.substr(j+1);

                    if(us.contains(new_Str) == false)
                    {
                        q.push(new_Str);
                        us.insert(new_Str);
                    }
                }
            }

            if(is_exist)
            break;
        }
      
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(),ret.end()),ret.end());
        return ret;
    }
};