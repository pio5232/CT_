#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

bool cmp(const string& str1, const string& str2)
{
    // 다른 숫자 개수
    int cnt = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i])
            cnt++;
    }

    return cnt == 1;
}
int solution(string begin, string target, vector<string> words) {
    
    vector<vector<int>> matrix(words.size() + 2);
    vector<bool> visited(words.size() + 2);

    // -1은 절대 도달할 수 없음을 의미.
    int s, t = -1;
 
    // s는 임의로 할당 = words.size로 할당 후 연결

    s = words.size();

    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
            t = i;
        
        // 임의로 설정한 시작지점과 연결. 반대쪽에서 이곳으로 갈 일은 없음.
        if (cmp(words[i], begin))
        {
            matrix[s].push_back(i);
        }

        for (int j = 0; j < words.size(); j++)
        {
            if (i == j)
                continue;

            // 서로 바뀔 수 있기 때문에 양방향
            if (cmp(words[i], words[j]))
            {
                matrix[i].push_back(j);
                matrix[j].push_back(i);
            }
        }
    }

    queue<pair<int,int>> q;
    visited[s] = true;
    q.push({s,0});

    while (q.size())
    {
        auto [cur, cost] = q.front();
        q.pop();

        if (cur == t)
        {
            return cost;
        }
        for (int next : matrix[cur])
        {
            if (visited[next])
                continue;

            visited[next] = true;
            q.push({ next, cost + 1 });
        }
    }

    return 0;
}
int main()
{
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"
}) << "\n";
}