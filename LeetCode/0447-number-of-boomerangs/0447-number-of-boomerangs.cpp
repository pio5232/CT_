class Solution {
public:

    int get_dist(int x1, int y1, int x2, int y2) const
    {
        int dx = x1-x2;
        int dy = y1-y2;
       return dx*dx + dy*dy; 
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        int ret = 0;

        unordered_map<int,int> dist_cnt;
        for(int i =0;i<points.size();i++)
        {
            dist_cnt.clear();

            for(int j = 0; j<points.size(); j++)
            {            
                if(i==j)continue;

                int dist = get_dist(points[i][0], points[i][1], points[j][0], points[j][1]);
                dist_cnt[dist]++;
            }

            // n * n-1 
            // 해당 i번째에서 매칭가능한 녀석들을 뽑아서 cnt * cnt-1 하는게 아닌가?
            // 아 manhatan아니고 euclidean라고 명시를 좀 해놔라
            for(const auto& p : dist_cnt)
            {
                ret += p.second * (p.second-1);
            }
        }

        return ret;

    }
};