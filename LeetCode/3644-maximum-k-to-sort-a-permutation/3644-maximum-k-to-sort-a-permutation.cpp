class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        int ret = INT_MAX;
        for(int i =0;i<nums.size();i++)
        {
            if(i != nums[i])
            ret &= i;
        }


        return ret == INT_MAX ? 0 : ret;
    }
};