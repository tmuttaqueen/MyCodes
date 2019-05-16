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
int r, c, n;

char str[100][100], s1[100][100], s2[100][100], temp[100][100], s3[100][100];


bool isvalid()
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for( int i = 0; i < 2*r; i++ )
    {
        for( int j = 0; j < 2*c; j++ )
        {
            int d = 0;
            if( i+r >= 2*r || j+c >= 2*c ) continue;
            for( int x1 = i, x2 = 0; x2 < r; x1++, x2++ )
            {
                for( int y1 = j, y2 = 0; y2 < c; y1++, y2++ )
                {
                    if( temp[x2][y2] == '.' || s1[x1][y1] == temp[x2][y2] ) d++;
                }
            }
            cnt1 = max(cnt1, d);
        }
    }
    for( int i = 0; i < 3*r; i++ )
    {
        for( int j = 0; j < 3*c; j++ )
        {
            int d = 0;
            if( i+r >= 3*r || j+c >= 3*c ) continue;
            for( int x1 = i, x2 = 0; x2 < r; x1++, x2++ )
            {
                for( int y1 = j, y2 = 0; y2 < c; y1++, y2++ )
                {
                    if( temp[x2][y2] == '.' || s2[x1][y1] == temp[x2][y2] ) d++;
                }
            }

            cnt2 = max(cnt2, d);
        }
    }
    for( int i = 0; i < 4*r; i++ )
    {
        for( int j = 0; j < 4*c; j++ )
        {
            int d = 0;
            if( i+r >= 4*r || j+c >= 4*c ) continue;
            for( int x1 = i, x2 = 0; x2 < r; x1++, x2++ )
            {
                for( int y1 = j, y2 = 0; y2 < c; y1++, y2++ )
                {
                    if( temp[x2][y2] == '.' || s3[x1][y1] == temp[x2][y2] ) d++;
                }
            }

            cnt3 = max(cnt3, d);
        }
    }
    return (cnt1 == r*c && cnt2 == r*c && cnt3 == r*c) || (cnt2 == r*c && cnt3 == r*c) ;
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
        cin >> r >> c;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                cin >> str[i][j];
            }
        }
        int x = 0, y = 0;
        for( int i = 0; i < r; i++ )
        {
            y = 0;
            for( int j = 0; j < c; j++ )
            {
                char ch = str[i][j];
                s1[x][y] = ch;
                s1[x+1][y] = ch;
                s1[x][y+1] = ch;
                s1[x+1][y+1] = ch;
                y += 2;
            }
            s1[x][y] = '\0';
            s1[x+1][y] = '\0';
            x += 2;

        }

        x = 0; y = 0;
        for( int i = 0; i < 2*r; i++ )
        {
            y = 0;
            for( int j = 0; j < 2*c; j++ )
            {
                char ch = s1[i][j];
                s2[x][y] = ch;
                s2[x+1][y] = ch;
                s2[x][y+1] = ch;
                s2[x+1][y+1] = ch;
                y += 2;
            }
            s2[x][y] = '\0';
            s2[x+1][y] = '\0';
            x += 2;
        }

        x = 0; y = 0;
        for( int i = 0; i < 3*r; i++ )
        {
            y = 0;
            for( int j = 0; j < 3*c; j++ )
            {
                char ch = s2[i][j];
                s3[x][y] = ch;
                s3[x+1][y] = ch;
                s3[x][y+1] = ch;
                s3[x+1][y+1] = ch;
                y += 2;
            }
            s3[x][y] = '\0';
            s3[x+1][y] = '\0';
            x += 2;
        }

        int ans = 0;
        int mask = (1<<(r*c));
        for( int i = 1; i < mask; i++ )
        {
            n = 0;
            for( int j = 0; j < (r*c); j++ )
            {
                temp[ j/c ][j%c] = '.';
                if( i&(1<< j) )
                {
                    n++;
                    int rr = j/c, cc = j%c;
                    temp[rr][cc] = str[rr][cc];
                }
            }
            if( isvalid() )
            {
                ans = max(ans, n);
            }
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;

    }
    return 0;
}
