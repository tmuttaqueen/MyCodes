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

vector<pii>vec;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m, k, a, b;
    map<int, int>mm, ind;
    cin >> n >> m >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        mm[i] = a;
    }
    int ans = 0;
    for( int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if( a > b )
        {
            int t = a;
            a = b;
            b = a;
        }
        vec.pb( mp(a,b) );
        ind[a]++;
        ind[b]++;
    }
    for( int i = 0; i < m; i++ )
    {
        if( mm[ vec[i].xx ] != mm[ vec[i].yy ] )
        {
            if( ind[ vec[i].xx ] > ind[ vec[i].yy ] )
            {
                mm[ vec[i].yy ] = mm[ vec[i].xx ];
                ind[ vec[i].xx ]--;
                ind[ vec[i].yy ]++;
            }
            else
            {
                mm[ vec[i].xx ] = mm[ vec[i].yy ];
                ind[ vec[i].xx ]++;
                ind[ vec[i].yy ]--;
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}




