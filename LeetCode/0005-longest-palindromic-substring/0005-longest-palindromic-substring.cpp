


class Solution {
public:
    static pair<int,int> r ;
    static int maxLen;

    static const int NMAX = 1004;
    static bool p[NMAX][NMAX];
    
    static void SetMax(int s, int e)
    {
        if(maxLen < e - s + 1)
        {

            maxLen = e - s + 1;
            r.first = s;
            r.second = e;            
        }
    }

    string longestPalindrome(string s) {

        r.first = 0;
        r.second = 0;
        maxLen = 1;

        memset(p, 0, sizeof(p));

        int N = s.size();

        // len 1 ,2 구간에 대해서 삽입
        for(int i = 0; i<N;i++)
        {
            p[i][i] = true;
            SetMax(i,i);
        }
        for(int i = 0;i<N-1;i++)
        {
            if(s[i] == s[i+1])
            {
                p[i][i+1] = true;

                SetMax(i,i+1);
            }
        }

        cout << "e : "<<r.second <<" s : "<< r.first << "\n";
        // 길이가 3~N 까지, 개수가 10개면 1~10까지의 len이 존재한다.
        for(int len = 3; len <= N; len++)
        {
            // 만약 길이가 3이면 [0,1,2] / [1,2,3], [2,3,4], ... [N-3,N-2,N-1]와 같이 동작.
            for(int i = 0; i + len -1 < N; i++)
            {
                // 여기서 i는 맨 왼쪽, j는 맨 오른쪽
                int j = i +len - 1;

                if(s[i] == s[j] && p[i+1][j-1])
                {
                    p[i][j] = true;
                    SetMax(i,j);
                }

                // cout << "??? : ";
                // for(int k = 0;k<j-i+1;k++)
                // {
                //     cout << s[k];
                // }
                // cout << "\n";
            }
        }
        
        string ret = s.substr(r.first, r.second - r.first + 1);

        return ret;
    }

};
    pair<int,int> Solution::r ;
    int Solution::maxLen;

    bool Solution::p[NMAX][NMAX];