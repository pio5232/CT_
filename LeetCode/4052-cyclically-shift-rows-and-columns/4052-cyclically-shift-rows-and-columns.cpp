class Solution {
public:

    vector<int> tmp;
    void moveleft(vector<vector<int>>& grid, int col, int cnt)
    {
        vector<int> empty_v(cnt, 0);
        tmp.swap(empty_v);

        int size = grid.size();
        int last = grid[col][size-1];
        for(int x = 0;x<cnt;x++)
        {
            tmp[x] = grid[col][x];
        }
        for(int x = cnt; x < size; x++)
        {
            grid[col][x-cnt] = grid[col][x];
        }

        for(int x = 0; x<cnt; x++)
        {
            grid[col][(x-cnt+size) % size] = tmp[x];
        }
    }

    void moveupward(vector<vector<int>>& grid, int row, int cnt)
    {
        vector<int> empty_v(cnt, 0);
        tmp.swap(empty_v);

        int size = grid.size();
        int last = grid[size-1][row];

        for(int y = 0;y<cnt;y++)
        {
            tmp[y] = grid[y][row];
        }
        for(int y = cnt; y < size; y++)
        {
            grid[y-cnt][row] = grid[y][row];
        }

        for(int y = 0; y<cnt; y++)
        {
            grid[(y-cnt+size) % size][row] = tmp[y];
        }
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        
        for(int y =0;y<n;y++)
        {
            moveleft(grid, y, rowShift[y]);
        }

        for(int x =0; x<n;x++)
        {
            moveupward(grid,x, colShift[x]);
        }

        return grid;
    }
};