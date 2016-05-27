#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	cout << min(n,m)+1 << endl;
	for(int i = 0, j = m; i <= n && j >= 0; ++i, --j)
	{
		cout << i << " " << j << endl;
	}
	return 0;
}