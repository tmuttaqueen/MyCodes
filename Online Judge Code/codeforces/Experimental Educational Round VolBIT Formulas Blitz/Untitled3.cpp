#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("input.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

long long tt[10005];

int main()
{
    filein;
    int n;
    cin >> n;
    long long ara[n+1], a;
    map<long long, long long> m;
    m[0] = 0;
    for( int i = 1; i <= n; i++  )
    {
        scanf("%lld %lld", &ara[i], &a);
        ara[i] = ara[i]*ara[i]*a;
        //what_is(ara[i]);
    }
    set<long long> s;
    s.insert( 0 );
    for( int i = 1; i <= n; i++ )
    {
        s.insert(ara[i]);
        auto x = s.find( ara[i] );
        x--;
        long long t = m[*x];
        m[ara[i]] = ara[i] + t;
    }
    long long ans = 0;
    for( auto it = m.begin(); it != m.end(); it++ )
    {
        if( it->yy > ans )
            ans = it->yy;
    }
    what_is(ans);
    double d = pi*double(ans);
    cout << d << endl;
    return 0;
}



