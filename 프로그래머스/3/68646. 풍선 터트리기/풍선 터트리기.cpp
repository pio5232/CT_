#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {

    int a_size = a.size();
    
    // 왼쪽부터 오른쪽으로 진행한 최소값 갱신
    vector<int> left_min (a_size);
    
    // 오른쪽부터 왼쪽으로 진행한 최소값 갱신
    vector<int> right_min (a_size);
    
    left_min[0] = a[0];
    right_min[a_size-1] = a[a_size-1];
    
    for(int i=1;i<a_size; i++)
    {
        left_min[i] = min(a[i], left_min[i-1]);
    }
    
    for(int i = a_size-2; i>=0;i--)
    {
        right_min[i] = min(a[i], right_min[i+1]);
    }
    
    int cnt = 0;
    for(int i =0;i<a_size;i++)
    {
        int small_cnt = 0;
        int left = i-1;
        int right = i+1;
        if(left >= 0 && left_min[left] < a[i])
            small_cnt++;
        
        if(right <= a_size-1 && right_min[right] < a[i])
            small_cnt++;
        
        if(small_cnt != 2)
            cnt++;
    }
    
    return cnt;
}