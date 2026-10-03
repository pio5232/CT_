#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

bool check(const vector<int>& numb, const vector<int>& temp)
{
	for (int i = 0; i < numb.size(); i++)
	{
		if (numb[i] > temp[i])
			return false;
	}

	return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {

	unordered_map<string, int> um;

	for (int i = 0; i < want.size(); i++)
	{
		um[want[i]] = i;
	}
    int n = number.size();

	vector<int> tmp(n + 2, 0);


	int basket_cnt = min(10, (int)discount.size());
	for (int i = 0; i < basket_cnt; i++)
	{
		string ele = discount[i];
		
		// 임시 주머니에 항목 추가.
		if(um.find(ele) != um.end())
		tmp[um[ele]]++;
	}

	int _left = 0;
	int _right = basket_cnt-1;


	int cnt = 0;
	while (_left < discount.size())
	{
		if (check(number, tmp))
			cnt++;

		string left_ele = discount[_left];
		
		if(um.find(left_ele) != um.end())
			tmp[um[left_ele]]--;
		
		_left++;

		if (_right < discount.size() -1)
		{
			_right++;
			
			string right_ele = discount[_right];

			if(um.find(right_ele) != um.end())
			tmp[um[right_ele]]++;
		}
	}
	
    return cnt;
}