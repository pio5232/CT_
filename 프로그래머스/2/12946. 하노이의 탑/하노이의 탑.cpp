#include <string>
#include <vector>

using namespace std;

void hanoi_t(int n, int from, int to, int tmp, vector<vector<int>>& ans)
{
    vector<int> v;
    if(n == 1)
    {
        v.push_back(from);
        v.push_back(to);
        ans.push_back(v);
        return;
    }
    
    hanoi_t(n-1, from, tmp, to, ans);
    v.push_back(from);
    v.push_back(to);
    ans.push_back(v);
    hanoi_t(n-1, tmp, to, from, ans);
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi_t(n,1, 3, 2, answer);
    return answer;
}