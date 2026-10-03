class Solution {
public:

    unordered_map<char,int> cnt_letter;

    int cvt_alpha_to_num(char c)
    {
        return c - 'a';
    }
    int get_dist(int left, int right)
    {
        return right - left;
    }

    int lengthOfLongestSubstring(string s) {
        
        int left = 0,right = 0;
        int longest_len = 0;


        while(left <=right && right < s.size())
        {
            // cout << "---------------------------------------------------\n";
            // cout << "left : " << left << ", right : "<<right << "\n";
            char c_left = s[left];
            char c_right = s[right++];
            
            // cout << cvt_alpha_to_num(c_right) << "\n";
            // has duplicated member
            if(++cnt_letter[c_right] > 1)
            {
                // cout << "[changed] c_right : " << c_right << " c_left : "<< c_left << "\n";

                while(cnt_letter[c_right] > 1)
                {
                    --cnt_letter[c_left];
                   left++;
                   c_left = s[left];
                }
            }

            // completely has no duplicated members
            // if(has_duplicated_member() == false)
            // {
                longest_len = max(longest_len, get_dist(left, right));
            // }
            // cout << "END left : " << left << ", right : "<<right << "\n";

        }

        return longest_len;
    }
};