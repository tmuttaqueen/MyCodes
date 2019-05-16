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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const int MX = 111111;
int N, H;
pair<intl, intl>point[MX];
pair<intl, intl>hull[MX];

intl cross( pair<intl, intl> &a, pair<intl, intl> &b, pair<intl, intl> &c )
{
    return (b.xx-a.xx)*(c.yy-a.yy) - (b.yy-a.yy)*(c.xx-a.xx);
}

double dist( pair<intl,intl> &a, pair<intl,intl> &b )
{
    return sqrt( (a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy) );
}

void monotoneChain()
{
    H = 0;
    sort( point, point+N );
    for( int i = 0; i < N; i++ )
    {
        while( H >= 2 && cross( hull[H-2], hull[H-1], point[i] ) <= 0 )
        {
            H--;
        }
        hull[H++] = point[i];
    }
    int f = H-1;
    for( int i = N-1; i >= 0; i-- )
    {
        while( H-f >= 2 && cross( hull[H-2], hull[H-1], point[i] ) <= 0 )
        {
            H--;
        }
        hull[H++] = point[i];
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl d;
        cin >> N >> d;
        for( int i = 0; i < N; i++ )
        {
            cin >> point[i].xx >> point[i].yy;
        }
        monotoneChain();
        //what_is(H);
        double ans = 4*acos(0.0)*d;
        //cout << hull[0].xx << " " << hull[0].yy << endl;
        for( int i = 1; i < H; i++ )
        {
            //cout << hull[i].xx << " " << hull[i].yy << endl;
            ans += dist( hull[i], hull[i-1] );
        }
        ans += dist( hull[0], hull[ H-1 ] );
        cout << "Case " << caseno++ << ": " << setprecision(10) << fixed << ans << endl;
    }
    return 0;
}
