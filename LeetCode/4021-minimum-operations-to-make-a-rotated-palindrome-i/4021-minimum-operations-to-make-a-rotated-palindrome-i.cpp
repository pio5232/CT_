class Solution {
public:

    int min_cnt = 1e9+2;
    int get_convert_cnt(char from, char to)
    {
        if(from <= to)
        {
            return to - from;
        }

        return ('z' - from) + (to - 'a') + 1;
    }
    
    // total
    void set_required_cnt(const string& str, int start, int chk_size)
    {
        const int half = chk_size/2; 
        const int center = start + half;

        int convert_cnt = start; // rotate cnt
        char r_c, l_c;

        // odd
        // ex) [] [] [center] [] []

        // even 
        // ex) [] []     [center] []

        for(int i =1; i<=half;i++)
        {
            l_c = str[center -i];
            r_c = (chk_size%2 != 0) ? str[center+i] : str[center+i-1];

            // cout << l_c << " : " << r_c << " \n";
            convert_cnt += min(get_convert_cnt(l_c,r_c), get_convert_cnt(r_c,l_c));

            if(convert_cnt > min_cnt)
                return;
        }

        min_cnt = min(min_cnt, convert_cnt);
    }
    // str => s+s
    bool IsPal(const string& str, int start, int chk_size)
    {
        const int half = chk_size/2; 
        const int center = start + half;
        
        // odd
        // ex) [] [] [center] [] []
        if(chk_size % 2 != 0)
        {
            for(int i =1; i<=half;i++)
            {
                if(str[center-half] != str[center+half])
                    return false;
            }
        }
        else // even
        {
            // ex) [] []     [center] []
            for(int i =0;i<half;i++)
            {
                if(str[center+i] != str[center-(i+1)])
                    return false;
            }
        }

        return true;

    }
    int minOperations(string s) {
        
        string tmp = s;
        tmp += s;
        
        // max_left_rotate => % s.size()
        // max_increment_문자 => % 26 (a~z)
        for(int i =0;i<s.size();i++)
        {
            set_required_cnt(tmp, i, s.size());
        }

        return min_cnt;
    }
};