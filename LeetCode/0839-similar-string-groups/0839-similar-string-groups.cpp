class Solution {
public:
    void go(int n, const vector<vector<int>>& v, vector<bool>& visited, const vector<string>& ss)
    {
        cout << " ---------------------------\n";
        queue<int> q;
        q.push(n);
        visited[n] = true;

        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            // cout << ss[cur] << "\n";

            for(int next : v[cur])
            {
                if(visited[next] == false)
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {

        int ans = 0;

        sort(strs.begin(), strs.end());
        strs.erase(unique(strs.begin(), strs.end()), strs.end());
        const int str_size = strs.size();
        // [string, idx]
        unordered_map<string, int> hash_map;
        vector<vector<int>> v(str_size);
        vector<bool> visited(str_size, false);
        for(int i =0;i<str_size;i++)
        {
            hash_map[strs[i]] = i;
        }

        for(int i =0;i<str_size;i++)
        {
            string s = strs[i];
            const int s_size = s.size();

            for(int j = 0; j<s_size; j++)
            {
                for(int k = j+1; k<s_size; k++)
                {
                    if(s[j] == s[k])
                    continue;

                    swap(s[j], s[k]);
                    // connect idx
                    if(hash_map.contains(s))
                    {
                        int t = hash_map[s];
                        
                        // connect
                        v[i].push_back(t);
                        v[t].push_back(i);
                    }
                    swap(s[j], s[k]);
                }
            }
        }

        for(int i =0;i<v.size();i++)
        {
            if(visited[i] == false)
            {
                go(i,v, visited, strs);
                ans++;
            }
        }
        return ans;
    }
};