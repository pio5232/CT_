class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
       
        long long sum = 0;
        // type == 0 -> row         y
        // type == 1 -> column      x
        // 우리가 모르는 것 : 덮어씌울때 없어지는 값이 몇개인가?

        // y축을 추가할 때는 x축에 있는 모든 것들을 건드려야한다.
        // x축을 추가할 때는 y축에 있는 모든 것들을 건드려야한다.
        
        // 역으로 생각해보면 마지막부터는 모두 이어진다!!

        vector<int> rows(n+1);
        vector<int> columns(n+1);
        int row_cnt = n;
        int col_cnt = n;

        // 중복에 대한 제거만 있으면 된다.
        for(auto rit = queries.rbegin(); rit != queries.rend(); rit++)
        {
            int type = (*rit)[0];
            int idx = (*rit)[1];
            int value = (*rit)[2];

            int* p_cnt, *another_cnt;
            vector<int>* prop;
            if(type == 0)
            {
                p_cnt = &row_cnt;
                another_cnt = &col_cnt;
                prop = &rows;
            }
            else
            {
                p_cnt = &col_cnt;
                another_cnt = &row_cnt;
                prop = &columns;
            }
            
            // changed
            if((*prop)[idx] != 0)
            continue; 
            
            sum += (value*(*p_cnt));
             (*prop)[idx] = value;
            // sum += (value*(*p_cnt) - (*prop)[idx]);

            // cout << format("idx : {}, value : {}, sum : {}\n",idx,value,sum);
            (*another_cnt)--;
        }
        return sum;
    }
};