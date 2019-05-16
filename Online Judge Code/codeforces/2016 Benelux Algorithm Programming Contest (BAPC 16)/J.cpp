#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

pii ara[223];
int deg[223];
int n;

int solve( int m )
{
    memset( deg, 0, sizeof deg );
    for( int i = 1; i <= n; i++  )
    {
        for( int  j = n+1; j <= 2*n; j++ )
        {
            if( abs( ara[i].xx-ara[j].xx )+abs( ara[i].yy - ara[j].yy ) <= m )
            {
                deg[i]++;
                deg[j]++;
            }
        }
    }
    for( int i = 1; i <= 2*n; i++ )
    {
        if( deg[i] < 1 ) return  0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    cin >> n;
    for( int i = 1; i <= 2*n; i++ )
    {
        cin  >> ara[i].xx >> ara[i].yy;
    }
    int l = 0, r = 1000000000, ans = -1;
    while( l <= r )
    {
        int m = (l+r)/2;
        int f = solve(m);
        if(f)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m+1;
    }
    cout << ans << endl;

    return 0;
}
