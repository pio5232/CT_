class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        
        vector<int> ret;
        sort(nums.begin(), nums.end());

        for(int i =0;(i+1)<nums.size(); i+=2)
        {
            int alice = i;
            int bob = i+1;

            ret.push_back(nums[bob]);
            ret.push_back(nums[alice]);
        }

        if(nums.size() % 2 != 0)
        ret.push_back(nums[nums.size()-1]);





         return ret;
    }
};