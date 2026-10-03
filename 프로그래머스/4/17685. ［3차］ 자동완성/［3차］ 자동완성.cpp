#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// string과 string을 비교해서 시작부터 동일한 개수를 반환
int str_cmp(const string& str1, const string& str2)
{
    size_t min_size = min(str1.size(), str2.size());

    int i = 0;
    for (; i < min_size; i++)
    {
        if (str1[i] != str2[i])
            break;

    }

    return i;
}
int solution(vector<string> words) {
    
    // 맨 앞과 맨 뒤에 추가하기위함
    // 아스키코드 a보다 작은 값, z보다 큰 값 넣음
    words.push_back("A");
    words.push_back("~");

    // string 사전순 정렬. 원하는 바로 나옴
    sort(words.begin(), words.end());

    // 추가한 원소를 제외한 기존 원소를 대상으로 -1,+1비교

    size_t words_size = words.size();
    int answer = 0;
    for (int i = 1; i < words_size - 1; i++)
    {
        int left_cmp_cnt = str_cmp(words[i - 1], words[i]);
        int right_cmp_cnt = str_cmp(words[i], words[i + 1]);
        
        // 왼쪽과 오른쪽 비교한 것들 중에서 동일한 개수가 얼마나 존재하냐 => 검색을 할때 얼마만큼을 검색해야하나
        int max_cmp_cnt = max(left_cmp_cnt, right_cmp_cnt);

        // 만약 이 값이 내 단어의 길이와 똑같다 => 이만큼을 검색
        // 근데 동일한 개수가 내 단어의 개수보다 짧으면 => 그거보다 1개만 더 검색하면 된다.
        
        if (max_cmp_cnt < words[i].size())
            answer += 1;

        answer += max_cmp_cnt;
    }

    return answer;
}

int main()
{
    cout << solution({ "word", "war", "warrior", "world" });
}