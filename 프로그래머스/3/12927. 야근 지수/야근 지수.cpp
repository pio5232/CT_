#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

int work_cnt[50002]{};
long long solution(int n, vector<int> works) {
      
    // Go GREEDY

    long long answer =0 , sum = 0;
    int cur_n = n;
    long long t = 0;
    for(int i=0;i<works.size();i++)
    {
        long long work_t = works[i];
        work_cnt[work_t]++;
        
        sum += work_t;
        t = max(t, work_t);
    }
    
    if( n >= sum)
        return 0;
                
    while(cur_n)
    {
        int& val = work_cnt[t];
     
        if(val > 0)
        {
            int rem_cnt = (cur_n >= val) ? val : cur_n;
            
            cur_n -= rem_cnt;
            val -= rem_cnt;

            work_cnt[t-1] += rem_cnt;
            
            if(val >0)
                break;
        }
        t--;
    }
    //cnt[works]
    
    for(long long i =0;i<=t;i++)
    {
        if(work_cnt[i] == 0)
            continue;
        
        //cout << i << " : " <<work_cnt[i] << "\n";
        answer += i* i* work_cnt[i];
    }
    return answer;
}