#include <iostream>
#include <vector>
using namespace std;

const int nmax = 503;

int dp[nmax][nmax];
const vector<vector<int>>* pTriagnle;
// 벡터는 0부터 시작, 인덱스는 1부터 시작이므로 유의
// Top-down
int go(int h, int w)
{
    if (h == pTriagnle->size())
        return 0;

    int& ret = dp[h][w];

    if (ret != -1)
        return ret;

    return ret = max(go(h + 1, w), go(h + 1, w + 1)) + (*pTriagnle)[h][w];
}
int solution(vector<vector<int>> triangle
) {

    // top-down => 효율성 1개 안맞음 ㅡ,.ㅡ
    //pTriagnle = &triangle;
    //fill_n(&dp[0][0], nmax * nmax, -1);

    // bottom-up
    for (int i = triangle.size() - 1; i >= 0; i--)
    {
        // 어차피 dp의 상한선을 넉넉하게 채워놨기 때문에 leaf_node에 대해 dp를 채우는 것도 max(0,0) + leaf_node 값으로 들어간다.
        for (int j = 0; j < triangle[i].size(); j++)
        {
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
        }
    }
    return dp[0][0];
}