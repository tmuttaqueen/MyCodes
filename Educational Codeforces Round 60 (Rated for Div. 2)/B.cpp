#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl m1 = -1, m2 = -1;
    int n, m, k;
    cin >> n >> m >> k;

    for( int i = 1; i <= n; i++ )
    {
        intl a;
        cin >> a;
        if( a >= m1 )
        {
            m2 = m1;
            m1 = a;
        }
        else if( a > m2 )
        {
            m2 = a;
        }
    }
    int d = k+1, q = m/d, r = m%d;
    //cout << m1 << " " << m2 << " " << q << " " << r << endl;
    intl sum = 1LL*q*( k*m1+m2 );
    sum += 1LL*r*m1;
    cout << sum << endl;

    return 0;
}
