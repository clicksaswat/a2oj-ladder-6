#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll poww(ll a, ll b, ll mod)
{
	ll ans = 1;
	while(b != 0)
	{
		if(b & 1)
		{
			ans = (ans*a)%mod;
		}
		a = (a*a)%mod;
		b /= 2;
	}
	return ans;
}

int main()
{
	string s;
	int a,b;
	cin >> s >> a >> b;
	int last_mod = 0;
	vector<int> left, right;
	
	for(int i = 0; i < s.length()-1; ++i)
	{
		int cur_num = s[i]-'0';
		int cur_mod = (cur_num + last_mod*10)%a;
		if(cur_mod == 0)
		{
			left.push_back(i);
		}
		last_mod = cur_mod;
	}
	last_mod = 0;
	for(int i = s.length()-1, j = 0; i > 0; --i,++j)
	{
		int cur_num = s[i]-'0';
		if(cur_num != 0)
		{
			int cur_mod = (poww(10,j,b)*cur_num+last_mod)%b;
			if(cur_mod == 0)
			{
				right.push_back(i);
			}
			last_mod = cur_mod;
		}
		
	}
	reverse(right.begin(),right.end());
	bool found = false;
	for(int i = 0; i < left.size(); ++i)
	{
		if(binary_search(right.begin(),right.end(),left[i]+1))
		{
			found = true;
			cout << "YES" << endl;
			for(int j = 0; j < s.size(); ++j)
			{
				cout << s[j]; 
				if(j == left[i])
				{
					cout << endl;
				}
			}
			cout << endl;
			break;
		}
	}
	if(!found)
	{
		cout << "NO" << endl;
	}
	return 0;
}