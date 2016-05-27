#include <bits/stdc++.h>

using namespace std;

const long long maxn = 100000;
long long arr[maxn+1];
long long dp[maxn+1];
long long get_ans(int i)
{
	if(i > maxn)
		return 0;
	if(dp[i] != -1)
		return dp[i];
	dp[i]	= max((i*arr[i])+get_ans(i+2), get_ans(i+1));
	return dp[i];
}
int main()
{
	int n, temp;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		arr[temp]++;
	}
	memset(dp, -1, sizeof(dp));
	long long ans = get_ans(1);
	cout << ans << endl;
	return 0;
}