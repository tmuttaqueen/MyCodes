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
#define pii         pair<int, int>

bool comp( pii a, pii b )
{
    return a.xx < b.xx;
}

bool comm( pii a, int b )
{
    return a.xx < b;
}
bool cccc( pii a , pii b )
{
    return a.yy < b.yy;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m, a, b;
    cin >> n >> m;
    vector<pii> vec;
    vector<pii> data;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        data.pb( {a, i} );
    }
    sort( data.begin(), data.end(), comp );

    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b;
        auto x = lower_bound( data.begin(), data.end(), a, comm );
        auto y = lower_bound( data.begin(), data.end(), b, comm );
        //cout << x->xx << endl;
        a = x - data.begin();
        b = y - data.begin();
        //cout << "index   " << data[a].yy << "  " << data[b].yy << endl;
        if( data[a].yy < data[b].yy ) vec.pb( {data[a].yy,data[b].yy} );
        else  vec.pb( {data[b].yy,data[a].yy} );
    }
    sort( vec.begin(), vec.end(), cccc );
    vector<int> ara(n);
    long long ans = 0;
    for( int i = 0, j = 0; i < m && j < n; i++ )
    {
        int x = vec[i].xx, y = vec[i].yy;
        while( j < n && j <= x )
        {
            //ara[j++] = n - y;
            ans += n - y;
            j++;
        }
    }
    cout << (long long)n*(n-1)/2 + (long long)n - ans << endl;
    return 0;
}



