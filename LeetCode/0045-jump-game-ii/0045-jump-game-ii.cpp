class Solution {
public:

        //nums[i]는 i에서 갈 수 있는 최대 길이를 의미함.
        // 인덱스 i에서는 j만큼 자유로 이동이 가능함 (0 <= j <= nums[i])
        // n-1에 도달하기 위한 최소 점프 횟수를 구하라

// dp
    // static const int NMAX = 1e4+4;
    // static int dp[NMAX];
    // static const int INF = 1e4+10;
    // static void Init()
    // {
    //     fill(dp, dp + NMAX,INF);
    // }
    // int jump(vector<int>& nums) {
    
    //     Init();
        
    //     // n-1 == size() -1
    //     int last = nums.size() - 1;
        
    //     dp[0] = 0;

    //     for(int i =0;i<nums.size();i++)
    //     {
    //         int n = nums[i];

    //         int inc = dp[i]+1;
    //         for(int j =1; j<=n;j++)
    //         {
    //             if(i+j > 10000)
    //                 continue;
    //             dp[i+j] = min(dp[i+j], inc);
    //         }
    //     }
    //     return dp[last];
    // }

    // Greedy O(N)
    int jump(vector<int>& nums) {

        int jumpCnt = 0;
        int cur = 0;

        // 내가 최대로 많이 갈 수 있는 다음
        int next = 0;
        for(int i = 0;i<nums.size()-1;i++)
        {
            next = max(next, i + nums[i]);

            // 만약 현재 위치가 내가 갈 수 있는 최대 위치면 갱신
            if(i == cur)
            {
                jumpCnt++;
                cur = next; 

                if(cur >= nums.size() - 1)
                {
                    break;
                }
            }
        }

        return jumpCnt;
    }
};
