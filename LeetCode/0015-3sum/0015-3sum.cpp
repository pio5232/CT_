class Solution {
public:
    int f(int left, int right, int num, const vector<int>& nums)
    {
        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(nums[mid] == num)
                return mid;
            else if(nums[mid] < num)
            {
                left = mid + 1;
            }
            else 
                right = mid-1;
        }
        return -1;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // 주어진 배열에서
        vector<vector<int>> ret;
        // 0을 만족하는 세 쌍을 출력하라.
        // 중복은 허용하지 않는다.

        // unique로 다 지워도 됨? => 현재
        // 0이 하나 존재할때
        // (0,a,b) => 0을 만족하는 a,b

        // (a,b,c)의 형태일 때
        // c == (a+b) || a == (b+c) || b == (a+c) 를 만족하면 된다.
        // 결국 이것만 만족하는 것을 찾으라는 말이다.

        sort(nums.begin(), nums.end());
        
        set<vector<int>> my_set;
        for(int i =0;i<nums.size();i++)
        {
            for(int j =i+1;j<nums.size();j++)
            {
                int sum = nums[i] + nums[j];

                // find index
                int f_idx = f(j+1, nums.size()-1, -sum, nums);

                if(f_idx > 0)
                {
                    // cout << format("f_idx : {}, nums[i] : {}, nums[j] : {}, nums[f_idx] : {}\n",f_idx, nums[i], nums[j], nums[f_idx]);
                    if(my_set.contains({nums[i],nums[j],nums[f_idx]}))
                        continue;
                        
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[f_idx]);

                    sort(v.begin(), v.end());
                    my_set.insert(v);
                }
            }
        }

        for(const auto& v : my_set)
        {
            ret.push_back(v);
        }
        // sort(ret.begin(), ret.end());
        // ret.erase(unique(ret.begin(), ret.end()), ret.end());

        return ret;
    }

// new2
};