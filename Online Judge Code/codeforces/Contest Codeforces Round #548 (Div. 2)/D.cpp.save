#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl mod = 1e9+7;



long long binary_expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << 335*binary_expo(144, mod-2, mod)%mod << endl;

    return 0;
}
