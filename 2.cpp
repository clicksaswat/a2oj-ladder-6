#include <bits/stdc++.h>

using namespace std;

int a[1000010];
int cnt[1000010];


int main()
{
	long long s = 0;
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		s += a[i];
	}
	if(s%3 != 0)
	{
		cout << "0" << endl;
	}
	else
	{
		s /= 3;
		long long ss = 0;
		for(int i = n-1; i >= 0; --i)
		{
			ss += a[i];
			if(ss == s)
				cnt[i] = 1;
		}

		for(int i = n-2; i >= 0; --i)
		{
			cnt[i] += cnt[i+1];
		}

		long long ans = 0;
		ss = 0;
		for(int i = 0; i+2 < n; ++i)	
		{
			ss += a[i];
			if(ss == s)
				ans += cnt[i+2];			
		}

		cout << ans << endl;
	}

	return 0;
}