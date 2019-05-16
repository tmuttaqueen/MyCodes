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

char s[100005];

int main()
{
    //ios::sync_with_stdio(0);
    int n, k, num = 0;
    scanf("%d %d\n", &n, &k);
    scanf("%s", s);
    vector<int>vec;
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == '0' ) vec.pb(i+1);
    }
    num = vec.size();
    /*for( int i = 0; i < num; i++ )
    {
        cout << i << "  " << vec[i] << endl;
    }*/
    int ans = 1e9, temp1, temp2, pos, p;
    for( int s = 0; s < (num-k); s++ )
    {
        int e = s + k;
        p = (vec[s] + vec[e])/2;
        auto pp = lower_bound( vec.begin(), vec.end(), p );
        int tt = pp - vec.begin() - s;
        temp1 = max(vec[e] - vec[s+tt], vec[s+tt] - vec[s]);
        if( tt > 0 ) temp2 = max(vec[e] - vec[s+tt-1], vec[s+tt-1] - vec[s]);
        else temp2 = 1e9;
        temp1 = min(temp1, temp2);
        ans = min(ans, temp1);
    }
    printf("%d\n", ans);
    return 0;
}
