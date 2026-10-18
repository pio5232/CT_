class Solution {
public:

    bool can_visit(int y, int x, const vector<vector<bool>>& visited, const vector<vector<int>>& grid)
    {
        return visited[y][x] == false && grid[y][x] == 0;
    }
    int BFS(const int y,const int x , vector<vector<bool>>& visited, const int Y, const int X, vector<vector<int>>& grid)
    {
        if(can_visit(y,x,visited,grid) == false)
            return 0;

        const pair<int,int> dir[]{{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;

        bool ret = true;
        q.push({y,x});
        visited[y][x] = true;

        while(q.size())
        {
            auto [cy,cx] = q.front();
            q.pop();

            if(cy == 0 || cx == 0 || cy == Y-1 || cx == X-1)
                ret = false;
            
            for(const auto& p : dir)
            {
                int ny = cy + p.first;
                int nx = cx + p.second;

                if(ny < 0 || nx < 0 || ny >= Y || nx >=X)
                continue;
\
                if(can_visit(ny,nx,visited,grid) == false)
                continue;

                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }

        return ret ? 1 : 0;
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        const int Y = grid.size();
        const int X = grid[0].size();

        vector<vector<bool>> visited(Y, vector<bool>(X, false));
        int ret = 0;

        for(int y = 0; y<Y;y++)
        {
            for(int x = 0; x<X;x++)
            {
                if(visited[y][x] == false)
                    ret += BFS(y,x,visited, Y,X , grid);
            }
        }

        return ret;
        
    }
};