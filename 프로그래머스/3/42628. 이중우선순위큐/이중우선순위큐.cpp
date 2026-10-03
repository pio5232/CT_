#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    
    multiset<int, less<int>> min_set;
    multiset<int, greater<int>> max_set;

    vector<int> answer(2,0);

    for(const string& oper : operations)
    {
        if (oper[0] == 'I')
        {
            int v = stoi(oper.substr(2));

            min_set.insert(v);
            max_set.insert(v);
        }
        else // (oper[0] == 'D')
        {
            if (oper[2] == '-')
            {
                // min 빼기
                if (min_set.size())
                {
                    int f = *min_set.begin();

                    min_set.erase(f);
                    max_set.erase(f);
                }
            }
            else
            {
                // max 빼기
                if (max_set.size())
                {
                    int f = *max_set.begin();

                    min_set.erase(f);
                    max_set.erase(f);
                }
            }
        }
    }

    if (max_set.size())
    {
        answer[0] = *max_set.begin();
        answer[1] = *min_set.begin();
    }
    return answer;
}