class Solution {
public:
    string getHint(string secret, string guess) {

        const int crit_max = 10;
        int cnt_secret[crit_max];
        int cnt_guess[crit_max];

        int cnt_matched = 0;
        int cnt_deferred = 0;
        for(int i =0; i<secret.size(); i++)
        {
            if(secret[i] == guess[i])
            {
                cnt_matched++;
                continue;
            }
            cnt_secret[secret[i] - '0']++;
            cnt_guess[guess[i] - '0']++;
        }

        for(int i =0;i<crit_max;i++)
        {
            cnt_deferred += min(cnt_secret[i], cnt_guess[i]);
        }

        string ret = "";
        ret += to_string(cnt_matched) + "A" + to_string(cnt_deferred) + "B";

        return ret;
    }
};