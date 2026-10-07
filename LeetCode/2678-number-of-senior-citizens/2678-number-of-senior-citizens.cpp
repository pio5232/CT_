class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int ret = 0;
        for(const string& s : details)
        {
            if(stoi(s.substr(11,2)) > 60)
            ret++;
        }
        return ret;
    }
};