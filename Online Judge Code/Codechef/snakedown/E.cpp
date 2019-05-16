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

int ans[55][55];
pii ara[55][2];
int flag[55]; // 0 - hor, 1 - ver
pii point[55];
int fix[55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i][0].xx >> ara[i][0].yy >> ara[i][1].xx >> ara[i][1].yy;
            if( ara[i][0].xx == ara[i][1].xx  )
            {
                flag[i] = 0;
                point[i] = mp( min(ara[i][0].yy, ara[i][1].yy), max( ara[i][0].yy, ara[i][1].yy )  );
                fix[i] = ara[i][0].xx;
            }
            else
            {
                flag[i] = 1;
                point[i] = mp( min(ara[i][0].xx, ara[i][1].xx), max( ara[i][0].xx, ara[i][1].xx )  );
                fix[i] = ara[i][0].yy;
            }
        }
        int res = 100000000;
        for( int x = 1; x <= 50; x++ )
        {
            for( int y = 1; y <= 50; y++ )
            {
                int an = -1;
                for( int i = 0; i < n; i++ )
                {
                    int dist = 0;
                    if( flag[i] == 0 )
                    {
                        dist += abs( fix[i] - x );
                        if( y < point[i].xx || y > point[i].yy )
                        {
                            dist += min( abs( y - point[i].xx ), abs( y - point[i].yy ) );
                        }

                    }
                    else
                    {
                        dist += abs( fix[i] - y );
                        if( x < point[i].xx || x > point[i].yy )
                        {
                            dist += min( abs( x - point[i].xx ), abs( x - point[i].yy ) );
                        }
                    }
                    an = max( an, dist );
                }
                ans[x][y] = an;
                res = min( res, ans[x][y] );
            }
        }
        cout << res << endl;
    }
    return 0;
}




