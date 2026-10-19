class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ret;

        sort(nums.begin(), nums.end());

        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        for(;first != last; first++)
        {
            ret.push_back(first - nums.begin());
        }
        return ret;
    }
};