#include <bits/stdc++.h>

using namespace std;

pair<int,int> arr[5555];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr,arr+n);
	int cur_day = 1;
	for(int i = 0; i < n; ++i)
	{
		if(cur_day <= arr[i].second)
		{
			cur_day = arr[i].second;
		}
		else
		{
			cur_day = arr[i].first;
		}
	}
	cout << cur_day << endl;
	return 0;
}