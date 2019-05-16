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

vector<pii>vec[111111][2]; //0-horizontal, 1- vertical
map<int,int>mm;
int c;
int ara[111111][2];
int ans[111111];
pii point[111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, w, h;
    cin >> n >> w >> h;
    int a, x, t;
    c = 1;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a >> x >> t;
        int d = x-t;
        if( mm[d] == 0 )
        {
            mm[d] = c++;
        }
        int ind = mm[d];
        if( a == 1 )
        {
            vec[ind][0].pb( mp(x,i) );
            point[i] = mp( x, h );
        }
        else
        {
            vec[ind][1].pb( mp(x,i) );
            point[i] = mp(w,x);
        }

    }
    for( int i = 1; i < c; i++ )
    {
        sort( vec[i][0].begin(), vec[i][0].end() );
        sort( vec[i][1].begin(), vec[i][1].end() );
        reverse( vec[i][1].begin(), vec[i][1].end() );
        int k = 0, l = 0;
        for( int j = 0; j < vec[i][0].size(); j++ )
        {
            ara[k++][0] = vec[i][0][j].yy;
        }
        for( int j = 0; j < vec[i][1].size(); j++ )
        {
            ara[k++][0] = vec[i][1][j].yy;
        }
        for( int j = 0; j < vec[i][1].size(); j++ )
        {
            ara[l++][1] = vec[i][1][j].yy;
        }
        for( int j = 0; j < vec[i][0].size(); j++ )
        {
            ara[l++][1] = vec[i][0][j].yy;
        }
        /*debug;
        for( int j = 0; j < l; j++ )
        {
            cout << ara[j][1] << " ";
        }
        cout << endl;
         for( int j = 0; j < l; j++ )
        {
            cout << ara[j][0] << " ";
        }
        cout << endl;*/
        for( int j = 0; j < l; j++ )
        {

            ans[ ara[j][1] ] = ara[j][0];
        }
    }
    /*for( int i = 1; i <= n; i++ )
    {
        cout << i << " -> " << ans[i] << endl;
    }*/
    for( int i = 1; i <= n; i++ )
    {
        cout << point[ ans[i] ].xx << " " << point[ ans[i] ].yy << endl;
    }

    return 0;
}
