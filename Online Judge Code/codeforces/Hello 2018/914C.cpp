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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
intl ara[111];
int flag[111];
intl pr[111];
vector<pii>vec, temp;
map< intl, intl > mm[33];

intl solve( intl n, intl v )
{
    //cout << n << " " << v << endl;
    //cout << vec[n].xx << ' ' << vec[n].yy << endl;
    if( v == 0 )
        return mm[n][v] = 0;
    if( mm[n].find(v) != mm[n].end() )
    {
        return mm[n][v];
    }
    if( n == 0 )
    {
        return mm[n][v] = ceil( double(v)/vec[n].yy )*vec[n].xx;
    }
    //cout << n << ' ' << v << endl;
    intl d  = ceil( double(v)/vec[n].yy );
    return mm[n][v] = min( min( solve(n-1, v%vec[n].yy ) + (v/vec[n].yy)*vec[n].xx , d*vec[n].xx), solve( n-1, v ) );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    mm[0][0] = 0;
    ara[0] = 1;
    intl l;
    for( int i = 1; i <= 34; i++ ) ara[i] = ara[i-1]*2;
    int n;
    cin >> n >> l;
    for( int i = 0; i < n; i++ )
    {
        cin >> pr[i];
    }
    for( int i = n-1; i >= 0; i-- )
    {
        int f = 0;
        int g = 0;
        for( int j = 0; j < i; j++ )
        {
            if( ara[i]*pr[j] <= pr[i]*ara[j] )
            {
                f = 1;
            }
        }
        if(f==0)
        {
            temp.pb( mp( pr[i], ara[i] ) );
        }
    }
   // intl ans = 0;
    for( int i = 0; i < temp.size(); i++ )
    {
        //cout << temp[i].xx << " " << temp[i].yy << endl;
        for( int j = i+1; j < temp.size(); j++  )
        {
            if( temp[j].xx >= temp[i].xx )
            {
                flag[j] = 1;
            }
        }
    }
    for( int i  = 0; i < temp.size(); i++ )
    {
        if( flag[i] == 0 )
        {
            vec.pb( temp[i] );
            //cout << temp[i].xx << " " << temp[i].yy << endl;
        }
    }
    reverse( vec.begin(), vec.end() );
    intl ans = solve( vec.size()-1, l );
    cout << ans << endl;
    return 0;
}

