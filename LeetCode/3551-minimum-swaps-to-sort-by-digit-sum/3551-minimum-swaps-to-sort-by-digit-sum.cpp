class Solution {
public:

    int get_digit_sum(int n)
    {
        int sum = 0;
        while(n>0)
        {
            sum += n % 10;

            n /= 10; 
        }

        return sum;
    }
    int minSwaps(vector<int>& nums) {
        
        // [sum, idx]
        vector<pair<int,int>> v;
        for(int i =0;i<nums.size();i++)
        {
            v.push_back({get_digit_sum(nums[i]),i});
        }

        sort(v.begin(), v.end(), [&nums](const pair<int,int>& p1, const pair<int,int>& p2)
        {
            if(p1.first != p2.first)
                return p1.first < p2.first;
            
            return nums[p1.second] < nums[p2.second];
        });


        int ret = 0;
        vector<bool> visited(v.size(), false);
        queue<int> q;

        
        for(int i = 0;i<v.size();i++)
        {
            if(i == v[i].second || visited[i])
                continue;

            int cnt = 0;
            q.push(i);
            visited[i] = true;

            while(q.size())
            {
                int idx = q.front();
                q.pop();
                cnt++;

                int next = v[idx].second;
                if(visited[next])
                    continue;

                visited[next] = true;
                q.push(next);
            }

            ret += cnt-1;
        }
    return ret;
    }
};