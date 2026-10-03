#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int mx;
vector<vector<int>> v;
vector<int> visited;

int cnt[20005];
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> v(n + 1);
    vector<int> visited(n + 1, 0);


    for (vector<int>& p : edge)
    {
        v[p[0]].push_back(p[1]);
        v[p[1]].push_back(p[0]);
    }

    queue<int> q;

    q.push(1);
    visited[1] = 1;
    int mx = 1;

    while (q.size())
    {
        int idx = q.front();
        q.pop();

        for (int i : v[idx])
        {
            if (visited[i])
                continue;

            visited[i] = visited[idx] + 1;

            if (mx < visited[i])
                mx = visited[i];

            cnt[mx]++;

            q.push(i);

        }
    }

    return cnt[mx];
}