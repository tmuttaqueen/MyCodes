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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[1005][1005];
priority_queue<intl>pr, pc;
intl rr[1000005], cc[1000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, m, k, p;
    cin >> n >> m >> k >> p;
    intl row = 0, col = 0;
    for( int i = 0 ; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            cin >> ara[i][j];
        }
    }
    for( int i = 0 ; i < n; i++ )
    {
        intl sum = 0;
        for( int j = 0; j < m; j++ )
        {
            sum += ara[i][j];
        }
        pr.push(sum);
    }
    for( int i = 0 ; i < m; i++ )
    {
        intl sum = 0;
        for( int j = 0; j < n; j++ )
        {
            sum += ara[j][i];
        }
        pc.push(sum);
    }

    for( int i = 1; i <= k; i++ )
    {
        intl d;
        d = pr.top();
        pr.pop();
        rr[i] = d;
        d -= m*p;
        pr.push(d);

        d = pc.top();
        pc.pop();
        cc[i] = d;
        d -= n*p;
        pc.push(d);
        rr[i] += rr[i-1];
        cc[i] += cc[i-1];
    }
    intl ans = -1e18;

    for( intl i = 0; i <= k; i++ )
    {
        ans= max( ans, rr[i] + cc[k-i] - (k-i)*i*p );
    }
    cout << ans << endl;
    return 0;
}




