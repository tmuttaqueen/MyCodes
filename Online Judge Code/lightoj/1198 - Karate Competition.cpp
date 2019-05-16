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

const int MAX = 105;

namespace wm
{

/// n = number of row and m = number of columns in 1 based, flag = 1-MAXIMIZE or 0-MINIMIZE
/// match[i] contains the column to which row i is matched

bool visited[MAX];
int U[MAX], V[MAX], P[MAX], way[MAX], minv[MAX], match[MAX], ar[MAX][MAX];

int hungarian(int n, int m, int mat[MAX][MAX], int flag = 0)
{
    memset(U, 0, sizeof(U));
    memset(V, 0, sizeof(V));
    memset(P, 0, sizeof(P));
    memset(ar, 0, sizeof(ar));
    memset(way, 0, sizeof(way));
    int inf = 1e9;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ar[i][j] = mat[i][j];
            if (flag) ar[i][j] = -ar[i][j];
        }
    }
    if (n > m) m = n;

    int i, j, a, b, c, d, r, w;
    for (i = 1; i <= n; i++)
    {
        P[0] = i, b = 0;
        for (j = 0; j <= m; j++) minv[j] = inf, visited[j] = false;

        do
        {
            visited[b] = true;
            a = P[b], d = 0, w = inf;

            for (j = 1; j <= m; j++)
            {
                if (!visited[j])
                {
                    r = ar[a][j] - U[a] - V[j];
                    if (r < minv[j]) minv[j] = r, way[j] = b;
                    if (minv[j] < w) w = minv[j], d = j;
                }
            }

            for (j = 0; j <= m; j++)
            {
                if (visited[j]) U[P[j]] += w, V[j] -= w;
                else minv[j] -= w;
            }
            b = d;
        }while (P[b] != 0);

        do
        {
            d = way[b];
            P[b] = P[d], b = d;
        }while (b != 0);
    }
    for (j = 1; j <= m; j++) match[P[j]] = j;

    return (!flag) ? -V[0] : V[0];
}
}

int ara[MAX][MAX];
int a[MAX], b[MAX];

int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
        }
        for( int i = 1; i <= n; i++ )
        {
            cin >> b[i];
        }
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                if( a[i] > b[j] )
                    ara[i][j] = 2;
                else if( a[i] == b[j] )
                    ara[i][j] = 1;
                else
                    ara[i][j] = 0;
            }
        }
        int d = wm::hungarian(n,n,ara, 1);
        printf("Case %d: %d\n", caseno++, d);
    }
    return 0;
}
