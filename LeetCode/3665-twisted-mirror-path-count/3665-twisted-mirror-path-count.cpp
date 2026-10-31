class Solution {
public:

    const int mod = 1e9 + 7;
    enum
    {
        RIGHT = 0,
        DOWN,
        DIR_MAX,
    };
    bool can_go(int y, int x, const vector<vector<int>>& grid)
    {
        const int Y = grid.size();
        const int X = grid[0].size();

        return ((y >= 0 && y < Y) && (x >= 0 && x < X));
        
    }
    // ENTRY DIR
    int go(const int destY, const int destX, int y, int x, int entry_dir, const vector<vector<int>>& grid, std::vector<std::vector<std::vector<int>>>& dp)
    {
        if (y == destY && x == destX)
            return 1;

        if(false == can_go(y,x, grid))
            return 0;

        int& ret = dp[entry_dir][y][x];
        if(ret != -1)
            return ret;

        if(grid[y][x] == 1)
        {
            int extra_y = entry_dir == RIGHT ? 1 : 0;
            int extra_x = entry_dir == DOWN ? 1 : 0;

            ret = go(destY, destX, y+extra_y, x+extra_x,(entry_dir + 1) % DIR_MAX ,grid, dp) % (mod);    
        }
        else
            ret = (go(destY, destX, y, x+1, RIGHT, grid, dp) + go(destY,destX,y+1,x,DOWN,grid, dp)) % (mod);
        
        return ret;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        
        const int Y = grid.size();
        const int X = grid[0].size();

        std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(Y, std::vector<int>(X, -1)));
        // int dp[2][Y][X];

        // fill_n(&dp[0][0][0], Y*X*2, -1);

        // 도착지의 위, 왼쪽에서 도착지로 갈 수 있는 경우의 수는 1개.
        // dp[Y-2][X-1] = dp[Y-1][X-2] = 1;

        int ans = go(Y-1,X-1, 0,0,RIGHT, grid, dp);
        cout << ans << "\n";

        return ans;
    }
};