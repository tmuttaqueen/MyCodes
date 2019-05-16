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
#define pii         pair<char, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 1234567;

string s;
int ara[M];
vector<pii>vec[2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    cin >> s;
    int ans = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        if( i == 0 || s[i-1] != s[i] )
        {
            if( i != 0 )
            {
                vec[0].pb( mp( s[i-1], ara[i-1] ) );
            }
            ara[i] = 1;
        }
        else ara[i] = ara[i-1] + 1;
    }
    vec[0].pb( mp( s[ s.size()-1 ], ara[s.size()-1] ) );
    int cur = 1, prev = 0;
    for( ans = 0; ans < M; ans++ )
    {
        //for( int i = 0; i < vec[prev].size(); i++ ) cout << vec[prev][i].xx << " " << vec[prev][i].yy<< endl;
        if( vec[prev].size() <= 1 ) break;
        for( int i = 0; i < vec[prev].size(); i++ )
        {
            if( i == 0 || i == vec[prev].size()-1 ) vec[prev][i].yy--;
            else vec[prev][i].yy = max( vec[prev][i].yy-2, 0 );
            if( vec[prev][i].yy > 0 )
            {
                if( vec[cur].size() > 0 && vec[cur][ vec[cur].size()-1 ].xx == vec[prev][i].xx )
                {
                    vec[cur][ vec[cur].size()-1 ].yy += vec[prev][i].yy;
                }
                else
                {
                    vec[cur].pb( vec[prev][i] );
                }
            }
        }
        vec[prev].clear();
        swap( cur, prev );
    }
    cout << ans << endl;
    return 0;
}
