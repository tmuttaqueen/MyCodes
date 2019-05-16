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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;
intl n;
intl ara[SZ];
stack<pii>mn, mx;
intl sumn, sumx;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    intl ans = 0;
    sumn = ara[0];
    sumx = ara[0];
    mn.push( mp(sumn, sumn) );
    mx.push( mp(sumn, sumx) );
    for( int i = 1; i < n; i++ )
    {
        intl x = ara[i], s = x;
        while( !mn.empty() && mn.top().xx >= x )
        {
            sumn -= mn.top().yy;
            //cout << "mn out " << mn.top().xx << " " << mn.top().yy << endl;
            s += x*( mn.top().yy/mn.top().xx );
            mn.pop();

        }
        sumn += s;
        mn.push( mp( x,s ) );

        x = ara[i], s = x;
        while( !mx.empty() && mx.top().xx <= x )
        {
            sumx -= mx.top().yy;
            //cout << "mx out " << mx.top().xx << " " << mx.top().yy << endl;
            s += x*( mx.top().yy/mx.top().xx );
            mx.pop();
        }
        sumx += s;
        mx.push( mp( x,s ) );
        ans += (sumx-sumn);
        //what_is(ans);
    }
    cout << ans << endl;
    return 0;
}




