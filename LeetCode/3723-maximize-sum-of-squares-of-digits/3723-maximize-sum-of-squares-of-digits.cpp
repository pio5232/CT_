class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        // 큰자릿수에 최대한 큰 수를 넣는다 
        string ret = "";
        int quot_cnt = sum / 9;
        int rem_cnt = sum % 9 ? 1 : 0;

        int use_cnt = num - (quot_cnt + rem_cnt);

        if(use_cnt < 0)
            return "";
        
        for(int i =0;i<quot_cnt;i++)
        {
            ret += "9";
        }
        
        if(rem_cnt)
        ret += to_string(sum%9);

        for(int i =0;i<use_cnt;i++)
        {
            ret += "0";
        }
        
        return ret;
    }
};