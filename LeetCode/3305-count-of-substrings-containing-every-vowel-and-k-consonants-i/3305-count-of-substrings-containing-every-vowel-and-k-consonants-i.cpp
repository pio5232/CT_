class Solution {
public:

    enum 
    {
        none = 0,
        ret_consonant = 0,
        ret_a = 1,
        ret_e = 2,
        ret_i = 3,
        ret_o = 4,
        ret_u = 5,

        vowel_a = 1 << 1,
        vowel_e = 1 << 2,
        vowel_i = 1 << 3,
        vowel_o = 1 << 4,
        vowel_u = 1 << 5,
        
        vowel_all = vowel_a | vowel_e | vowel_i | vowel_o | vowel_u,
    };

    int ret_arr[30]{};
    const int cvt_char_to_int(char c)
    {
        return c - 'a';
    }

    int countOfSubstrings(string word, int k) {
        ret_arr[cvt_char_to_int('a')] = ret_a;
        ret_arr[cvt_char_to_int('e')] = ret_e;
        ret_arr[cvt_char_to_int('i')] = ret_i;
        ret_arr[cvt_char_to_int('o')] = ret_o;
        ret_arr[cvt_char_to_int('u')] = ret_u;

        int ans = 0;
        
        for(int start = 0; start < word.size()-4;start++)
        {
            int chk_vowel = none;
            int consonants_cnt = 0;

            for(int i = start; i<word.size();i++)
            {
                char c = word[i];
                int ret = ret_arr[cvt_char_to_int(c)];

                if(ret > 0)
                    chk_vowel |= ( 1 << ret);
                else
                    consonants_cnt++;

                if(consonants_cnt > k)
                    break;

                if(chk_vowel == vowel_all && consonants_cnt == k)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};