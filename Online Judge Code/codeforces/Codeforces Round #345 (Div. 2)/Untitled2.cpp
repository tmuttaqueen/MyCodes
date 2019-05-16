#include <bits/stdc++.h>

using namespace std;
map<pair<int,int>,int>mp;
map<int,int>mx,my;
long long cnt,a,b,n;
int main()
{
	freopen("input.txt", "r", stdin);
	cin>>n;
	for (int i = 0; i <n; ++i)
	{
		cin>>a>>b;
		cnt+=mx[a]+my[b]-mp[make_pair(a,b)],mx[a]++,my[b]++,mp[make_pair(a,b)]++;
	}
	return cout<<cnt, 0;
}
