#include <iostream>
#include <vector>
using namespace std;


#include <queue>
#include <set>
const int nmax = 203;

const int inf = 1e8;
int n, s, a, b;

set<int> my_s;
vector<vector<pair<int, int>>> m(nmax);

vector<int> go(int start, int _n)
{
    vector<int> dist(_n + 3, inf);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({ 0, start });

    while (pq.size())
    {
        // pos까지 걸리는 비용

        auto [cost, pos] = pq.top();
        pq.pop();

        // 해당 지점까지의 비용이 많으면 스킵
        if (dist[pos] < cost)
            continue;;
        
        // 해당 지점으로부터 갈 수 있는 경로에 대한 추가
        for (const auto& [cost_2, _next] : m[pos])
        {
            int next_cost = dist[pos] + cost_2;

            if (next_cost < dist[_next])
            {
                dist[_next] = next_cost;
                pq.push({ next_cost, _next });
            }
        }
    }

    return dist;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {

    vector<vector<int>> new_v(n + 2);

    for (auto& v : fares)
    {
        m[v[0]].push_back({ v[2], v[1] });
        m[v[1]].push_back({ v[2], v[0]});
    }

    vector<int> dist_s = go(s, n);
    vector<int> dist_a = go(a, n);
    vector<int> dist_b = go(b, n);

    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        if (dist_a[i] == inf || dist_b[i] == inf || dist_s[i] == inf)
            continue;

        ans = min(ans, dist_a[i] + dist_b[i] + dist_s[i]);
    }
    return ans;
}