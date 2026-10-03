#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<vector<int>> v(20);
vector<bool> judge(20, false);

int max_sheep;
int cur_sheep, cur_wolf;

// 진입 정점, 양, 늑대, 방문 정점, 정점과 연결된 간선리스트, 해당 정점에서의 동물(양 : 0, 늑대 : 1)
void go(int cur_sheep, int cur_wolf, int visited, const vector<int>& info)
{
    max_sheep = max(max_sheep, cur_sheep);
    
    // 계속해서 세력을 넓혀간다.
    for (int cur =0; cur< info.size();cur++)
    {
        // 방문할 필요가 없는 노드라면 스킵
        if (judge[cur] == false)
            continue;

        // 방문하지 않은 노드라면 스킵
        if ((visited & (1 << cur)) == 0)
            continue;

        for (int next : v[cur])
        {
            // 방문할 필요가 없는 노드라면 스킵
            if (judge[next] == false)
                continue;

            // 이미 방문한 노드에 대해선 방문처리 되어있음 -> 그 다음으로 넘어가기 위해 스킵
            if ((visited & (1 << next)) != 0)
                continue;

            // 바로 갈 수 있는 노드인지 확인
            // 다음 노드가 늑대이면 늑대의 수 < 양-1 인지 확인해야한다.
            if (info[next] == 1)
            {
                // 가지 못한다면 한 바퀴를 돌고 최종적으로 확인할 리스트에 넣는다.
                if (cur_wolf + 1 >= cur_sheep)
                    continue;
                
                go(cur_sheep, cur_wolf + 1, visited | (1 << next), info);
            }
            else
                go(cur_sheep + 1, cur_wolf, visited | (1 << next), info);
        }
    }
}
bool pre_dfs(int n, const vector<vector<int>>& v, vector<bool>& jud_v, const vector<int>& info)
{
    bool is_there_sheep = false;
    for (int next : v[n])
    {
        is_there_sheep |= pre_dfs(next, v, jud_v, info);
    }

    return jud_v[n] = (is_there_sheep |= (info[n] == 0));
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

    for (const vector<int>& edge : edges)
    {
        v[edge[0]].push_back(edge[1]);
    }

    // 해당 지점을 탐색할 필요가 있는지 (자신의 밑으로 내려가서 양을 획득할 수 있는지 체크)
    // 양을 획득할 수 있으면 true
    pre_dfs(0, v, judge, info);

    int visited = 0;

    for (int i = 0; i < info.size(); i++)
    {
        // 양을 획득할 수 없는 구간은 이미 방문한 것으로 설정한다.
        if (judge[i] == false)
        {
            visited |= 1 << i;
        }
    }

    visited |= 1;
    // 0번 노드는 처리한 상태로 진행
    go(1, 0, visited, info);

    return max_sheep;
}
