#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dp[20];
int solution(int n) {
    
    // 괄호는 무조건 열려야한다.
    // 처음이 무조건 열려야하기 때문에 머리와 몸통을 분리하듯 분리한 경우의 수를 계산
    
    dp[0] = 1;
    
    for(int i=1;i<=14;i++)
    {
        for(int j =0;j<i;j++)
        {dp[i] += dp[j] * dp[i-j - 1];
        }
        
        cout << dp[i] << "\n";
    }
    
    return dp[n];
    
}