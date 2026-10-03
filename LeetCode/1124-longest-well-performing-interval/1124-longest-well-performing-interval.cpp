class Solution {
public:

    bool IsWell(int hour)
    {
        return hour > 8;
    }
    int longestWPI(vector<int>& hours) {
        // longest common sequence

        // len

        int l_len = 0;
        
        for(int i =0; i<hours.size(); i++)
        {
            int cnt = 0;
            for(int j = i; j<hours.size();j++)
            {
                if(IsWell(hours[j]))
                {
                    cnt++;
                }
                else
                    cnt--;

                if(cnt > 0)
                    l_len = max(l_len, j-i+1);
            }

        }
        return l_len;
    }
};