#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int ara[505][505];
vector<int>ans;
int n, m;
bool pos( int x )
{
    int a = 0, b = 0;
    ans.clear();
    ans.resize(n+1, 0);
    int nz[505], z[505];
    memset(nz, -1, sizeof nz);
    memset( z, -1, sizeof z );
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            if( (ara[i][j]&x) == x )
            {
                nz[i] = j;
            }
            else
            {
                z[i] = j;
            }
        }
    }
    int xx = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( nz[i] != -1 )
        {
            a++;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        if( z[i] == -1 )
        {
            ans[i] = nz[i];
            xx++;
        }
    }
    if( xx%2 == 1 )
    {
        for( int i = 1; i <= n; i++ )
        {
            if( ans[i] == 0 ) ans[i] = z[i];
        }
        return 1;
    }
    else
    {
        if( a - xx >= 1 )
        {
            for( int i = 1; i <= n; i++ )
            {
                if( ans[i] == 0 && nz[i] != -1 )
                {
                    ans[i] = nz[i];
                    break;
                }
            }
            for( int i = 1; i <= n; i++ )
            {
                if( ans[i] == 0 )
                    ans[i] = z[i];
            }
            return 1;
        }
    }
    return 0;


}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            cin >> ara[i][j];
        }
    }
    for( int i = 0; i < 10; i++ )
    {
        if( pos(1<<i) )
        {
            cout << "TAK" << endl;
            for( int i = 1; i <= n; i++ )
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NIE" << endl;



    return 0;
}
