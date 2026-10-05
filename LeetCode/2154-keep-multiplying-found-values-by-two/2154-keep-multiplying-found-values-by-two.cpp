class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        sort(nums.begin(), nums.end());
        
        int f = original;
        bool ret = true;

        while(ret)
        {
            ret = false;
            int left = 0;
            int right = nums.size()-1;

            while(left <= right)
            {
                int mid = (left + right) / 2;

                if(nums[mid] == f)
                {
                    ret = true;
                    f *= 2;
                    break;
                }
                else if(nums[mid] > f)
                {
                    right = mid - 1;
                }
                else 
                    left = mid + 1;
            }
        }

        return f;
    }
};