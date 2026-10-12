class Solution {
public:

    const char dot = '.';
    int n_arr[10]{};
    void clear_arr()
    {
        fill_n(n_arr, 10, 0);
    }
    bool chk_y(const int y, const int size, const vector<vector<char>>& board)
    {
        clear_arr();
        for(int x = 0; x<size;x++)
        {
            const char& c = board[y][x];
            if(c == dot)
                continue;

            if(++n_arr[c-'0'] > 1)
                return false; 
        }

        return true;
    }

    bool chk_x(const int x, const int size, const vector<vector<char>>& board)
    {
        clear_arr();       
        for(int y = 0; y< size; y++)
        {
            const char& c = board[y][x];
            
            if(c == dot)
                continue;

            if(++n_arr[c-'0'] > 1)
                return false;            
        }

        return true;
    }

    bool chk_sub_grid(const int center_y, const int center_x, const vector<vector<char>>& board)
    {
        clear_arr();
        for(int y = -1;y<=1;y++)
        {
            for(int x = -1; x<=1;x++)
            {
                const char& c = board[center_y + y][center_x + x];
                if(c == dot)
                    continue;

                if(++n_arr[c-'0'] > 1)
                    return false;      
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = board.size();
        for(int y = 0;y<n;y++)
        {
            for(int x = 0;x<n;x++)
            {
                if(board[y][x] == dot)
                continue;
                
                if(false == (chk_y(y,n,board) && chk_x(x,n,board)))
                    return false;
            }
        }

        for(int y = 1; y<=7; y+=3)
        {
            for(int x = 1; x<=7; x+=3)
            {
                if(false == chk_sub_grid(y,x,board))
                    return false;
            }
        }

        return true;
    }
};