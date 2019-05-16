#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
int ara[MAXN];
intl n, k, A, B;

intl cnt( intl l, intl r )
{
    /*int lo = 0, hi = k-1,  ans1 = k;
    while( lo <= hi )
    {
        int mid = (lo+hi)/2;
        if( ara[mid] >= l )
        {
            ans1 = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    if( ans1 == k )
        return 0;
    lo = 0; hi = k-1;  int ans2 = k;
    while( lo <= hi )
    {
        int mid = (lo+hi)/2;
        if( ara[mid] <= r )
        {
            ans2 = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    if( ans1 == ans2 && (ara[ans1] < l || ara[ans1] > r) )
        return 0;
    return ans2 - ans1+1;*/
    return upper_bound( ara, ara+k, r ) - lower_bound( ara, ara+k, l );
}


intl solve( intl l, intl r )
{
    if( l == r )
    {
        intl d = cnt(l,r);
        if( d > 0 )
            return d*B;
        else
            return A;
    }
    intl d = cnt(l,r);
    if( d == 0 )
        return A;
    intl m = (l+r)/2;
    return min( d*B*(r-l+1), solve( l, m ) + solve(m+1, r));

}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> A >> B;
    for( int i = 0; i < k; i++ )
        cin >> ara[i];
    sort( ara, ara+k );
    intl ans = solve( 1LL, 1LL<<n );

    cout << ans << endl;

    return 0;
}
