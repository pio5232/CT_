#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string,string> um;

string chat[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};


vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string,string>> ord;
    
    string views[3];
    for(int i = record.size() -1; i>=0;i--)
    {
        int viewCnt = 0;
        
        int s = 0;
        int f = record[i].find_first_of(" ",s);

        while(f != string::npos)
        {
            views[viewCnt++] = record[i].substr(s,f - s );   
            
            s = f + 1;
            
            f = record[i].find_first_of(" ",s);
        }
        
        views[viewCnt] = record[i].substr(s);
        
//        for(int i=0;i<=viewCnt;i++)
//        {
//            cout << i<<" : " << views[i] << " __";
//        }
//        cout << "\n\n";
        // 현재 상태에서는 views[0] : type, views[1] : before_id, views[2] : after_id
    
        // 1. Enter / Leave 순서 넣기
        if(views[0] != "Change")
        {
            ord.push_back({views[0], views[1]});
        }
    
        // 2. Enter / Change 일때 um[ID] == ""이면 ID 채워넣기.
        if(views[0] != "Leave")
        {
            if(um[views[1]] == "")
                um[views[1]] = views[2];
        }
    }
    
     reverse(ord.begin(), ord.end());
    
    for(auto& pa : ord)
    {
        string t = pa.first;
        string id = pa.second;
        
        int chatType = t == "Enter" ? 0 : 1;
        
        answer.emplace_back(um[id] + chat[chatType]);    
    }
       return answer;
}