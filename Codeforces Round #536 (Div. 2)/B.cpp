#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

pii food[MAXN];

intl cost[MAXN];
intl rem[MAXN];
int n, m;
void print()
{
    cout << "---> " ;
    for( int i = 1; i <= n; i++ )
    {
        cout << rem[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> rem[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> cost[i];
        food[i] = mp( cost[i], i );
    }

    sort( food+1, food+n+1 );
    int cur = 1;
    for( int i = 1; i <= m; i++ )
    {
        int t, d;
        cin >> t >> d;
        intl ans = 0;
        if( rem[t] >= d )
        {
            ans = d*cost[t];
            rem[t] -= d;
        }
        else
        {
            ans += rem[t]*cost[t];
            d -= rem[t];
            rem[t] = 0;
            int f = 1;
            //cout << ans << " " << d << endl;
            while( cur <= n && d > 0 && f == 1 )
            {
                intl type = food[cur].yy, cc = food[cur].xx;
                if( rem[type] >= d )
                {
                    ans += d*cc;
                    rem[type] -= d;
                    d = 0;
                }
                else
                {
                    cur++;
                    ans += rem[type]*cc;
                    d -= rem[type];
                    rem[type] = 0;
                }
                //print();
            }
            if( d > 0 && cur == n+1 )
            {
                ans = 0;
            }
        }

        cout << ans << endl;
        //print();
    }

    return 0;
}
