#include <iostream>
#include <vector>
using namespace std;


void go(const vector<vector<int>>& arr, const int sx, const int sy, const int size, vector<int>& v)
{
	int st = arr[sy][sx];
	
	for (int y = sy; y < sy + size; y++)
	{
		for (int x = sx; x < sx + size; x++)
		{
			if (arr[y][x] != st)
			{
				goto JUDGE;
			}
		}
	}

	v[st]++;
	return;

	JUDGE:
	const int half = size / 2;

	go(arr, sx, sy, half, v);
	go(arr, sx + half, sy, half, v);
	go(arr, sx, sy + half, half, v);
	go(arr, sx + half, sy + half, half, v);
}
vector<int> solution(vector<vector<int>> arr) {
    
	vector<int> answer(2);

	int arr_size = arr.size();
	go(arr, 0, 0, arr_size, answer);
    return answer;
}