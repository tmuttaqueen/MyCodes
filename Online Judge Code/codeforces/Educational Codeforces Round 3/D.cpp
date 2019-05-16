#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define endl        "\n"

vector<pii>cost[3];
intl n,m,k,s,a,b;

bool comp( pii a, pii b )
{
    return a.yy < b.yy;
}

bool ispos( intl c1, intl c2 )
{
    intl c = 0, l=0, r=0;
    for( int i = 0; i < k; i++ )
    {
        if( cost[1].size() <= l )
        {
            c += cost[2][r++].yy*c2;
        }
        else if( cost[2].size() <= r )
        {
            c += cost[1][l++].yy*c1;
        }
        else if( cost[1][l].yy*c1 < cost[2][r].yy*c2  )
        {
            c += cost[1][l++].yy*c1;
        }
        else
        {
            c += cost[2][r++].yy*c2;
        }
    }
    return c<=s;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> n >> m >> k >> s;
    intl dn[n+1], pn[n+1];
    intl dd[n+1], pp[n+1];
    dd[0] = pp[0] = 1000000000;
    dn[0] = pn[0] = 0;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        dd[i] = a;
        if( a < dd[dn[i-1]] )
            dn[i] = i;
        else
            dn[i] = dn[i-1];
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        pp[i] = a;
        if( a < pp[ pn[i-1] ] )
            pn[i] = i;
        else
            pn[i] = pn[i-1];
    }

    for( int i = 1; i <= m; i++ )
    {
        cin >> a >> b ;
        cost[a].pb(mp(i,b));
    }
    sort( cost[1].begin(), cost[1].end(), comp );
    sort( cost[2].begin(), cost[2].end(), comp );
    intl ans = -1,low=1,high=n;
    while(low <= high)
    {
        intl mid = (low+high)/2;
        if( ispos( dd[dn[mid]], pp[pn[mid]]) )
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    cout << ans << endl;
    if( ans != -1 )
    {
        intl c1 = dd[dn[ans]], c2 = pp[pn[ans]];
        intl c = 0, l=0, r=0;
        for( int i = 0; i < k; i++ )
        {
            if( cost[1].size() <= l )
            {
                //c += cost[2][r++].yy*c2;
                cout << cost[2][r++].xx << " " << pn[ans] << endl;
            }
            else if( cost[2].size() <= r )
            {
                //c += cost[1][l++].yy*c1;
                cout << cost[1][l++].xx << " " << dn[ans] << endl;
            }
            else if( cost[1][l].yy*c1 < cost[2][r].yy*c2  )
            {
                //c += cost[1][l++].yy*c1;
                cout << cost[1][l++].xx << " " << dn[ans] << endl;
            }
            else
            {
                //c += cost[2][r++].yy*c2;
                cout << cost[2][r++].xx << " " << pn[ans] << endl;
            }
        }
    }
    cout << endl;
    return 0;
}



