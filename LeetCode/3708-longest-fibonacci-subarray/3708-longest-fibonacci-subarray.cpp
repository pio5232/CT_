class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        vector<int> fib_len(nums.size(), 0);

        int max_len = 0;
        int len=0;
        for(int i = 2; i<nums.size();i++)
        {
            if(nums[i] == nums[i-1] + nums[i-2])
            {
                len++;
                max_len = max(max_len, len);
            }
            else
                len = 0;
        }

        return max_len+2;
    }
};