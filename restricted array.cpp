#include<bits/stdc++.h>

using namespace std;

const int M = 1e5+5;
int cn[M];
set<int>ss;
int ara[M];
long long mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n; i++ )
        cin >> ara[i];
    for( int i = 0; i < k; i++ )
    {
        ss.insert( ara[i] );
        cn[ara[i]]++;
    }
    int tot = ss.size();
    for( int i = k; i < n;i++)
    {
        cn[ ara[i-k] ]--;
        if( cn[ ara[i-k] ] == 0 ) ss.erase( ara[i-k] );
        cn[ ara[i] ]++;
        ss.insert( ara[i] );
        tot = max( tot, (int)ss.size() );
        //cout << "tot " << tot << endl;
    }
    long long ans = 1;
    for( int i = 1; i <= tot; i++ )
    {
        ans = (ans*i)%mod;
    }
    cout << ans << endl;

    return 0;
}
