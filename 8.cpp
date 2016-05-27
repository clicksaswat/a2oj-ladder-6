#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

long long dp[110][2];
int n,k,d;

long long add(long long a, long long b)
{
	return (a+b)%MOD;	
}

void calculate(int val)
{
	if(dp[val][0] > -1)
		return;

	for(int i = 1; i <= k && val-i  >= 0; ++i)
	{
		calculate(val-i);
	}

	dp[val][0] = 0; dp[val][1] = 0;

	for(int i = 1; i <= k && val-i >= 0; ++i)
	{
		
		dp[val][0] = add(dp[val][0], dp[val-i][0]);
		
		if(i >= d)
		{
			dp[val][1] = add(dp[val][1], dp[val-i][0]);
		}
		else
		{
			dp[val][1] = add(dp[val][1], dp[val-i][1]);
		}
	}

	/*cout << "val: " << val << endl;
	cout << dp[val][0] << " " << dp[val][1] << endl << endl;*/
}



int main()
{
	cin >> n >> k >> d;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1; dp[0][1] = 0;
	calculate(n);	
	cout << dp[n][1] << endl;
	return 0;
}