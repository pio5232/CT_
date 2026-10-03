class Solution {
public:

    void go(const int n, const int opened,const int closed, string str, vector<string>& v)
    {
        if(opened+closed == n*2)
        {
            v.push_back(str);
            return;
        }
        if(opened < n)
            go(n, opened+1, closed, str+'(', v);

        if(closed < opened)
            go(n, opened, closed + 1, str + ')', v);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> gen_vec;
        go(n,0,0,"",gen_vec);
        return gen_vec;
    }
};