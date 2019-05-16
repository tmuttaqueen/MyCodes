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
vector<intl> vec, ara;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    vec.pb(4);
    vec.pb(7);
    int l = 0, r = 1;
    for( int i = 2; i <= 9; i++ )
    {
        for( int j = l; j <= r; j++ )
        {
            intl d = vec[j];
            vec.pb( d*10+4 );
            vec.pb( d*10+7 );
        }
        l = r+1;
        r = vec.size()-1;
    }
    intl pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;
    for( int i = 0; i < vec.size(); i++ )
    {
        if( vec[i] >= min(pl, vl) && vec[i] <= max(pr, vr) )
        {
            //cout << vec[i] << " ";
            ara.pb( vec[i] );
        }
    }
    //cout << endl;
    if( ara.size() < k )
    {
        cout << "0.00000000000000" << endl;
        return 0;
    }
    intl ans = 0;
    for( int l = 0; l < ara.size(); l++ )
    {
        int r = l + k-1;
        if( r >= ara.size()  ) break;
        intl prev, nxt;
        if( ara[l] >= pl && ara[r] <= vr )
        {
            if( l == 0 ) prev = pl;
            else prev = max(pl, ara[l-1]+1);
            if( r == ara.size()-1 ) nxt = vr;
            else nxt = min( vr, ara[r+1]-1 );
            if( prev <= pr && nxt >= vl  )
                ans += min( pr-prev+1, ara[l]-prev+1 )*min( nxt - vl+1, nxt- ara[r]+1 );
        }
        //what_is(ans);
        if( ara[l] >= vl && ara[r] <= pr )
        {
            if( l == 0 ) prev = vl;
            else prev = max(vl, ara[l-1]+1);
            if( r == ara.size()-1 ) nxt = pr;
            else nxt = min(pr,ara[r+1]-1);
            if( prev <= vr && nxt >= pl  )
                ans += min( vr-prev+1, ara[l]-prev+1 )*min( nxt - pl+1, nxt- ara[r]+1 );
        }
        //what_is(ans);
    }
    l = max(pl, vl); r = min( pr, vr );
    if( r >= l && k == 1  )
    {
        for( int i = 0; i < ara.size(); i++ )
            if( ara[i] >= l && ara[i] <= r )
                ans--;
    }

    //what_is(ans);
    double sol = (pr-pl+1)*(vr-vl+1);
    sol = ans/sol;
    sol = min( sol, 1.00000000000000000 );
    cout << setprecision(12) << fixed << sol << endl;
    return 0;
}
