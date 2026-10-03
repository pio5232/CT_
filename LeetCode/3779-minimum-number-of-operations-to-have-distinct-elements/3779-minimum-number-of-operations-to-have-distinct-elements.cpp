class Solution {
public:

    int dup_cnt = 0;
    int counts[100002]{};

    void dec_cnt(int n)
    {
        if(--counts[n] > 0)
            dup_cnt--;
    }
    int has_no_dup_ele() const{return dup_cnt == 0;}
    int get_dist(int left ,int right)
    {
        return right - left + 1;
    }
    int minOperations(vector<int>& nums) {
        // 0 ~ nums.size()-1
        for(int n : nums)
        {
            if(++counts[n] > 1)
                dup_cnt++;
        }

        int ret = 0;
        int left = 0;
        int right = nums.size()-1;
        while(1)
        {
            if(true == has_no_dup_ele() || (left == right))
                break;

            int rmv_cnt = min(3, get_dist(left,right));

            for(int l_cnt = 0; l_cnt < rmv_cnt; l_cnt++)
            {
                dec_cnt(nums[left + l_cnt]);
            }
            left += rmv_cnt;
            ret++;
        }

        return ret;
    }
};