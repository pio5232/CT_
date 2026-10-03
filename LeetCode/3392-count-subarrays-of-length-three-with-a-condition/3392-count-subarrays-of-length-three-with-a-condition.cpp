class Solution {
public:
    int countSubarrays(vector<int>& nums) {

        int ret=0;
        for(int i =0;i<nums.size()-2; i++)
        {
            int k = i+1;
            int j = k+1;

            if(nums[i]+nums[j] == nums[k]*0.5)
            ret++;
        }
         return ret;
    }
};