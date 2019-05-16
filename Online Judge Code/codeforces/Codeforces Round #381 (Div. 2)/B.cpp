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

 int ara[105];
 int sum[105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m, a, b;
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    sum[0] = ara[0];
    for( int i = 1; i < n; i++ )
    {
        sum[i] = sum[i-1] + ara[i];
    }
    int ans = 0;
    int val[105];
    val[0] = 0;
    for( int i = 1; i <= m; i++ )
    {
        cin >> a >> b;
        a--;
        b--;
        ans = max( ans, ans + sum[b] - ((a==0)?0:sum[a-1]) );
        //val[i] = ans;
        //what_is(ans);
        //debug;
    }
    cout << ans << endl;
    return 0;
}



