#include <bits/stdc++.h>

using namespace std;

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
#define double      long double

intl ara[100005];
intl dp[100005];
map<intl, intl >mm;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k;
    cin >> n >> k;
    for( int i =0; i < n; i++ ) cin >> ara[i];
    intl s = ara[0];
    mm[s]++;
    intl mx = s;
    for( int i = 1; i < n; i++ )
    {
        s += ara[i];
        mm[s]++;
        mx = max(mx, s);
    }

    set<intl>ss;
    ss.insert(1);
    intl kk = k;
    mx = 1000000000000000LL;
    //what_is(mx);
    for( int i = 1; abs(kk) <= mx && i < 52 ; i++ )
    {
       // what_is(kk);
        ss.insert(kk);
        kk *= k;
    }
    intl temp[100];
    int c = 0;
    auto it = ss.begin();
    while( it != ss.end() )
    {
        temp[c++] = *it;
        it++;
    }
    intl ans = 0;
    s = ara[0];
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            //cout << temp[j] << " ";
            ans += mm[ temp[j] ];
            temp[j] += ara[i];
        }
       //cout << endl;
        if( i > 0 ) s += ara[i];
        mm[s]--;

    }

    cout << ans << endl;
    return 0;
}



