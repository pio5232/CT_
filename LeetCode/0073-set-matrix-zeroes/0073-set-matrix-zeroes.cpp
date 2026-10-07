class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();

        set<int> mod_row, mod_col;
        for(int y = 0; y<row;y++)
        {
            for(int x= 0; x<col;x++)
            {
                if(matrix[y][x] == 0)
                {
                    mod_row.insert(y);
                    mod_col.insert(x);
                }
            }
        }

        for(int r : mod_row)
        {
            for(int x = 0;x<col;x++)
            {
                matrix[r][x] = 0;
            }
        }

        for(int c : mod_col)
        {
            for(int y=  0;y<row;y++)
            {
                matrix[y][c] = 0;
            }
        }
    }
};