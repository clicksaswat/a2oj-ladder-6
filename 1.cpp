#include <bits/stdc++.h>

using namespace std;

string smallest[110][990];
string largest[110][990];

int main()
{
	int m,s;
	cin >> m >> s;
	
	string small(m, '0'), large(m, '0');
	//cout << small << " " << large << endl;
	int left = s;
	small[0] = '1';
	left--;

	for(int i = m-1; i >= 0; --i)
	{
		if(left > 9)
		{
			small[i] += 9;
			//cout << small[i] << endl;
			left -= 9;
		}
		else
		{
			small[i] += left;
			left = 0;
		}
	}
	left = s;
	for(int i = 0; i < m; ++i)
	{
		if(left > 9)
		{
			large[i] += 9;
			left -= 9;
		}
		else
		{
			large[i] += left;
			left = 0;
		}
	}

	
	if(m == 1)
	{
		if(s <= 9)
		{
			cout << s << " " << s << endl;
		}
		else
		{
			cout << "-1 -1" << endl;
		}
		return 0;
	}
	else
	{
		if(s >= 1 && s <= 9*m)
		{
			cout << small << " " << large << endl;;
		}
		else
		{
			cout << "-1 -1" << endl;;
		}
	}
	return 0;
}