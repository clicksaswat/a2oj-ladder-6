#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int min_bs = a-1;
	int max_bs = 2*(a+1);
	if(b < min_bs || b > max_bs)
	{
		cout << "-1" << endl;
	}
	else
	{
		int ones = b;
		ones -= (a-1);
		int f_ones = (ones > 2) ? 2 : ones;
		ones -= f_ones;
		int b_ones = (ones > 2) ? 2 : ones;
		ones -= b_ones;
		int m_ones = ones;
		for(int i = 0; i < f_ones; ++i)
		{
			cout << "1";
		}
		for(int i = 0; i < m_ones; ++i)
		{
			cout << "011";
		}
		for(int i = 0; i < (a-1-m_ones); ++i)
		{
			cout << "01";
		}
		cout << "0";
		for(int i = 0; i < b_ones; ++i)
		{
			cout << "1";
		}
		cout << endl;
	}
	return 0;
}