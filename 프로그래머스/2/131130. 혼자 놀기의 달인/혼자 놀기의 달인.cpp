#include <iostream>
#include <vector>
using namespace std;

const int nmax = 104;
bool visited[nmax];

void init(const vector<int>& team_list)
{
    for (int i : team_list)
    {
        visited[i] = false;
    }
}
int go(const vector<int>& cards, int start, vector<int>& team_list)
{
    int cnt = 0;

    // 들어오는 start값은 인덱스 접근을 위해 1씩 빠진 상태.

    while (1)
    {
        if (visited[start])
            break;

        visited[start] = true;
        team_list.push_back(start);

        start = cards[start] -1; // 여기는 1~100까지로 설정돼있어서 인덱스 접근을 위해 1씩 빼준다.
        cnt++;
    }

    return cnt;
}

int solution(vector<int> cards) {

    int max_v = 0;

    fill_n(visited, nmax, false);
    
    for (int i = 0; i < cards.size(); i++)
    {
        vector<int> team1_list;
        int team1_cnt = 0;
        
        if (visited[i] == false)
        {
            team1_cnt = go(cards, i, team1_list);

            for (int j = 0; j < cards.size(); j++)
            {
                vector<int> team2_list;

                if (visited[j] == false)
                {
                    max_v = max(max_v, team1_cnt * go(cards, j, team2_list));
                    
                    init(team2_list);
                }
            }

            init(team1_list);
        }
    }

    return max_v;
}
