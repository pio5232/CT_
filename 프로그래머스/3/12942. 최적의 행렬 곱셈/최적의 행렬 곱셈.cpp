#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int nmax = 203;
const int inf = 2e9;

bool visited[nmax];
int max_size;
int m_min = inf;

// s -> e 까지 최소, 예를 들어 
// [1][3]이면
// 1 *(2*3)과
// (1*2)*3을 모두 비교한 최소를 리턴.

int dp[nmax][nmax];

// n은 현재 방문한 개수를 의미
int go(int s,int e, const vector<vector<int>>& matrix)
{
    //printf("S : %d, e : %d 진입\n", s, e);

    if (s == e)
        return 0;

    int& ret = dp[s][e];

    if (ret != inf)
        return ret;

    for (int m = s; m < e; m++)
    {
        ret = min(go(s, m, matrix) + go(m+1,e,matrix) + matrix[s][0] * matrix[m+1][0] * matrix[e][1], ret);
    }

    return ret;
}
int solution(vector<vector<int>> matrix_sizes) {
 
    max_size = matrix_sizes.size();

    //vector<vector<int>> adj(max_size + 2);
    //for (int i =0;i<max_size;i++)
    //{
    //    for (int j = 0; j < max_size; j++)
    //    {
    //        if (i == j)
    //            continue;

    //        // [i]에서의 끝부분과 [j]의 시작부분이 같다 => 행렬곱이 가능하다. 연결
    //        if (matrix_sizes[i][1] == matrix_sizes[j][0])
    //            adj[i].push_back(j);

    //        if (matrix_sizes[j][1] == matrix_sizes[i][0])
    //            adj[j].push_back(i);
    //    }
    //}

    fill_n(&dp[0][0], nmax * nmax, inf);
    

    return  go(0, max_size-1, matrix_sizes);
}

int main()
{
    //vector<vector<int>> v(200);

    //for (int i = 0; i < v.size(); i++)
    //{
    //    v[i].push_back(200);
    //    v[i].push_back(200);
    //}
    cout << solution({ {5, 3},{3, 10},{10, 6} });
    //cout << solution(v);
}