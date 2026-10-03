class Solution {
public:
    int maxDistinct(string s) {
        bool is_used[30];

int cnt = 0;
        for(char c : s)
        {
            int idx = c - 'a';
            if(is_used[idx] == false)
            {
                is_used[idx] = true;
                cnt++;
            }
        }
        return cnt;
    }
};