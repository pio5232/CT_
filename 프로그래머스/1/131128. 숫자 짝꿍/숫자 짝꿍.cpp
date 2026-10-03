#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    
    int cnt[10][3]{};
    
    for(int i = 0;i<X.size(); i++)
    {
        cnt[X[i]-'0'][0]++;
    }
    for(int i =0;i<Y.size(); i++)
    {
        cnt[Y[i] - '0'][1]++;
    }
    
    for(int i =0;i<10;i++)
    {
        cnt[i][2] = min(cnt[i][0], cnt[i][1]);
    }
    string ans = "";
        
    for(int i=9;i>0;i--)
    {
        while(cnt[i][2])
        {
            ans += i + '0';
            
            cnt[i][2]--;
        }
    }
    
    if(ans.empty())
    {
        if(cnt[0][2])
            return "0";
        else
            return "-1";
    }
    
            while(cnt[0][2])
        {
            ans += '0';
            
            cnt[0][2]--;
        }
    return ans;
    
}
