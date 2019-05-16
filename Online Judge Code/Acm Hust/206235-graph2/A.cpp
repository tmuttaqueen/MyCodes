#include <bits/stdc++.h>

using namespace std;

#define intl long long

const int MAX = 105;

/// n = number of row and m = number of columns in 1 based, flag = 1-MAXIMIZE or 0-MINIMIZE
/// match[i] contains the column to which row i is matched
/// set mat[i][j] to inf if i and j is not connected
template<typename T>
struct WBM
{
    bool visited[MAX];
    int  P[MAX], way[MAX], match[MAX];
    T minv[MAX], ar[MAX][MAX], U[MAX], V[MAX];

    T hungarian(int n, int m, T mat[MAX][MAX], int flag = 0)
    {
        memset(U, 0, sizeof(U));
        memset(V, 0, sizeof(V));
        memset(P, 0, sizeof(P));
        memset(ar, 0, sizeof(ar));
        memset(way, 0, sizeof(way));
        T inf = 1e18;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ar[i][j] = mat[i][j];
                if (flag) ar[i][j] = -ar[i][j];
            }
        }
        if (n > m) m = n;

        int i, j, a, b, c, d;
        T r, w;
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
            }
            while (P[b] != 0);

            do
            {
                d = way[b];
                P[b] = P[d], b = d;
            }
            while (b != 0);
        }
        for (j = 1; j <= m; j++) match[P[j]] = j;

        return (!flag) ? -V[0] : V[0];
    }
};

double ara[MAX][MAX];

vector< pair<double,double> >vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl ant;
    double a, b;
    while(cin >> ant)
    {
        WBM<double> wm;
        vec.clear();
        for( int i = 1; i <= ant; i++ )
        {
            cin >> a >> b;
            vec.push_back( make_pair(a,b) );
        }
        for( int i = 1; i <= ant; i++ )
        {
            cin >> a >> b;
            for( int j = 1; j <= ant; j++ )
            {
                ara[j][i] = sqrt(( a-vec[j-1].first )*( a-vec[j-1].first ) + (b-vec[j-1].second)*(b-vec[j-1].second));
            }
        }
        wm.hungarian(ant, ant, ara);
        for( int i = 1; i <= ant; i++ )
            cout << wm.match[i] << endl;
        cout << endl;
    }



    return 0;
}
