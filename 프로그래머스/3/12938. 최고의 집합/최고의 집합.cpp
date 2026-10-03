#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    
    vector<int> answer;
    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    int v = s / n;
    int rem = s % n;

    for (int i = 0; i < n; i++)
    {
        answer.push_back(v);
    }

    auto iter = answer.rbegin();

    int cnt = 0;
    
    while (cnt < rem)
    {
        *(iter + cnt) += 1;

        cnt++;
    }

    
    return answer;
}