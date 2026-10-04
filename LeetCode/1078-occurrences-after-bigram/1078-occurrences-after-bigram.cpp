class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ret;

        vector<string> s;

        int pos = 0;
        while(1)
        {
            cout << pos << "\n";
            int f = text.find(" ", pos);

            if(f == string::npos)
            break;

            string parsed_str = text.substr(pos, f-pos);
            s.push_back(parsed_str);

            pos = f + 1;
        }
            string parsed_str = text.substr(pos);
            s.push_back(parsed_str);

        for(int i = 0; i< s.size()-2; i++)
        {
            if(s[i] == first && s[i+1] == second)
                ret.push_back(s[i+2]);
        }

        return ret;
    }
};