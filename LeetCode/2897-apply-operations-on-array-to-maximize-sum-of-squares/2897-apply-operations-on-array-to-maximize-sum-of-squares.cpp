class Solution {
public:
    using ull = unsigned long long;
    const ull g_max = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        
        ull ret = 0;
        // reverse
        int cnt_bit[33]{};
        
        for(int n : nums)
        {
            string s = bitset<32>(n).to_string();

            for(int i =0;i<s.size();i++)
            {
                if(s[i] == '1')
                {
                    cnt_bit[i]++;

                }
            }
        }

        for(int cnt = 0;cnt<k;cnt++)
        {
            bitset<32> b{};
        
        for(int i =0;i<sizeof(cnt_bit)/sizeof(cnt_bit[0]);i++)
        {
            if(cnt_bit[i] > 0)
            {
                cnt_bit[i]--;
                b.set(31-i, true);
            }
        }
            ull val = b.to_ullong();
            ret = (ret + val*val) % g_max;
        }

        return ret;
    }
};