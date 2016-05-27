#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n,p,ans;
	cin >> n >> p;
	string s(n+1, 'a');

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}

	int ud[n+1],cud[n+1];
	cud[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		int x = abs(s[i]-s[n-i+1]);
		ud[i] = x<13 ? x : 26-x;
		cud[i] = cud[i-1]+ud[i];
	}

	if(p <= (n/2))
	{
		int first = p, last = p;
		for(int i = 1; i < p; ++i)
		{
			if(ud[i] != 0)
			{
				first = i;
				break;
			}
		}
		for(int j = (n/2); j > p; --j)
		{
			if(ud[j] != 0)
			{
				last = j;
				break;
			}
		}

		int left = p-first, right = last-p;
		if(left < right)
		{
			ans = 2*left+right+cud[n/2];
		}
		else
		{
			ans = 2*right+left+cud[n/2];
		}

	}

	else
	{
		int first = p, last = p;
		for(int i = (n/2)+1; i < p; ++i)
		{
			if(ud[i] != 0)
			{
				first = i;
				break;
			}
		}
		for(int j = n; j > p; --j)
		{
			if(ud[j] != 0)
			{
				last = j;
				break;
			}
		}
		int left = p-first, right = last-p;
		if(left < right)
		{
			ans = 2*left+right+cud[n]-cud[n/2];
		}
		else
		{
			ans = 2*right+left+cud[n]-cud[n/2];
		}
	}
	cout << ans << endl;
	return 0;
}