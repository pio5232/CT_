class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        

        sort(tasks.begin(), tasks.end(),[](const vector<int>& v1, const vector<int>& v2)
        {
            int d1 = v1[1] - v1[0];
            int d2 = v2[1] - v2[0];

            if(d1 != d2)
                return d1 > d2;

            return v1[1] > v2[1];
        });

        int ret = tasks[0][1];

        int rem = tasks[0][1] - tasks[0][0];

        for(int i = 1; i<tasks.size();i++)
        {
            if(rem < tasks[i][1])
            {
                ret += tasks[i][1] - rem;
                rem = tasks[i][1];
            }
            rem -= tasks[i][0];
        }

        return ret;
    }
};