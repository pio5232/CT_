#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <format>
#include <iostream>
using namespace std;



//int binary_search_minute_timetable(int std_min, const deque<int>& minute_timetable)
//{
//    // std_min보다 큰 값의 시작 index를 찾는다.
//    int left = 0;
//    int right = minute_timetable.size() - 1;
//
//  
//    while (left <= right)
//    {
//        int m = (left + right) / 2;
//        
//        if (minute_timetable[m] < std_min)
//        {
//            left = m + 1;
//        }
//        else // if (minute_timetable[m] >= std_min)
//        {
//            right = m - 1;
//        }
//    }
//
//    return left;
//}
string solution(int n, int t, int m, vector<string> timetable) {

    // n : 셔틀 운행 횟수
    // t : 셔틀 운행 간격
    // m : 한 셔틀에 탈 수 있는 사람 수
    // timetable : 크루가 셔틀 타려고 도착하는 시각

    deque<int> minute_timetable;

    for (int i = 0; i < timetable.size(); i++)
    {
        int hour = stoi(timetable[i].substr(0, 2));
        int minute = stoi(timetable[i].substr(3, 2));

        minute_timetable.push_back(hour * 60 + minute);
    }
    // 시간 순 정렬.
    //sort(timetable.begin(), timetable.end(), [](const string& str1, const string& str2)
    //    {
    //        int hour_1 = stoi(str1.substr(0, 2));
    //        int hour_2 = stoi(str2.substr(0, 2));
    //        int minute_1 = stoi(str1.substr(3, 2));
    //        int minute_2 = stoi(str2.substr(3, 2));

    //        if (hour_1 != hour_2)
    //            return hour_1 < hour_2;

    //        return minute_1 < minute_2;
    //    });
    //
    sort(minute_timetable.begin(), minute_timetable.end());

    // 9시
    int cur_min = 540;
    int idx = 0;
    int cnt = 0;

    int last_min = cur_min;

    bool is_full = false;
    while (cnt < n)
    {
        is_full = false;
        // 출발 시각 이전에 모인 사람의 개수
        //int wait_people_cnt = binary_search_minute_timetable(cur_min, minute_timetable);
        int wait_people_cnt = upper_bound(minute_timetable.begin(), minute_timetable.end(), cur_min) - minute_timetable.begin();
        int ride_people_cnt;

        if (wait_people_cnt >= m)
        {
            ride_people_cnt = m;
            is_full = true;
        }
        else
            ride_people_cnt = wait_people_cnt;

        for (int i = 0; i < ride_people_cnt; i++)
        {
            last_min = minute_timetable.front();
            minute_timetable.pop_front();
        }

        cur_min += t;
        cnt++;
    }
    // 핵심 => 차가 도착하는 마지막 시간에 탈 수 있냐
    // 사람이 적으면 이걸 체크해야하고, 사람이 많다면 
    // 만약 시간안에 사람이 없으면 출발한다.
    // 시간이 다 되면 출발한다.

    // 꽉 찼으면 마지막으로 탑승할 수 있는 사람보다 1이 작으면 됨 ( 여유 없음)
    int ret_min;
    if (is_full)
        ret_min = last_min - 1;
    else // 그게 아니면 막차까지 기다려도 된다.
        ret_min = cur_min - t;

    string answer = std::format("{:02}:{:02}", ret_min / 60, ret_min % 60);

    return answer;
}

