class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;

        int last = target.back();

        int cur = 1;
        int idx = 0;
        while(idx < target.size())
        {
            ret.push_back("Push");

            if(cur++ < target[idx])
            {
                ret.push_back("Pop");
                continue;
            }

            idx++;
        }

        return ret;
    }
};