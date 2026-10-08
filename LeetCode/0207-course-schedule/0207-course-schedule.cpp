class Solution {
public:

    // == 0 => no cycle, > 0  => has cycle
    int go(int n, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dp)
    {
        int& ret = dp[n];

        if(ret != -1)
        return ret;

        ret = 0;

       for(int next : adj[n])
        {
            if(visited[next])
                return 1;
            
            visited[next] = true;
            ret += go(next,adj,visited,dp);
            visited[next] = false;

            if(ret > 0)
                break;
        }

        return ret;
    }
    bool chk_cycle(const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& dp)
    {
        for(int i =0;i<adj.size();i++)
        {
            fill_n(visited.begin(), visited.size(), false);

            visited[i] = true;
            int ret = go(i, adj, visited, dp);
            visited[i] = false;

            if(ret > 0)
                return false;
        }
       
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
       vector<vector<int>> adj(numCourses);
       // -1 : unchecked, 0 : false, 1 : true
       vector<int> dp(numCourses, -1);
       vector<bool> visited(numCourses, false);

       for(const auto& v : prerequisites)
       {
            adj[v[0]].push_back(v[1]);
       }

        // 0 ~ numCourses-1

        bool ret = chk_cycle(adj, visited, dp);

        return ret;
    }
};