#include <bits/stdc++.h>

using namespace std;


int main()
{
	string s, res;
	cin >> s;
	s += "$";
	int last_count = 0;
	
	for(int i = 0; i < s.length()-1; ++i)
	{
		char cur = s[i], next = s[i+1];
		res.push_back(cur);
		
		if(next == cur)
		{
			if(last_count == 2)
			{
				last_count = 1;
			}
			else
			{
				last_count = 2;
				res.push_back(cur);
			}

			while(next == cur)
			{
				next = s[++i];
			}
			i--;
		}
		else
		{
			last_count = 1;
		}

		
	}
	cout << res << endl;
	return 0;
}