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

char str[2][1000];

int dx[] = {1,-1, 0, 0};
int dy[] = {0,0,1,-1};
int vis[2][1000], flag, c, d;

void dfs( int x, int y )
{
    //cout << x << " "  << y << endl;
    d++;
    vis[x][y] = 1;
    int cnt = 0;
    for( int i = 0; i < 4; i++ )
    {
        int x1 = x + dx[i], y1 = y + dy[i];
        if( x1 >= 0 && x1 <= 1 && y1 >= 0 && y1 < c && vis[x1][y1] == 0 && str[x1][y1] == '#' )
        {
            cnt++;
            //cout << x1 << " " << y1 << endl;
            dfs(x1,y1);
        }
    }
    //cout << x << " t "  << y << endl;
    if( cnt > 1 )
        flag = 0;
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        d = 0;
        memset( vis, 0, sizeof vis );
        int r = 2, num = 0;
        flag = 1;
        scanf("%d", &c);
        scanf(" %s", str[0]);
        scanf("%s", str[1]);

        for( int i = 0; i < c; i++ )
        {
            if( str[0][i] == '#' ) num++;
            if( str[1][i] == '#' ) num++;
        }
        int x,y;
        int ans = 0;
        //what_is(c);
        //what_is(str[0]);
        //what_is(str[1]);
        for( int i = 0; i < c; i++ )
        {
            if( str[0][i] == '#' )
            {
                flag = 1;
                d = 0;
                dfs( 0,i );
                if( d == num && flag )
                    ans = 1;
            }
            if( str[1][i] == '#' )
            {
                flag = 1;
                d = 0;
                dfs( 1,i );
                if( d == num && flag )
                    ans = 1;
            }
        }


        if( ans )
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
    }
    return 0;
}




