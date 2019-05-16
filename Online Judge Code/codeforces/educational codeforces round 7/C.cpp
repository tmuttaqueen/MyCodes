#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

vector<int>v[1000001];

int main()
{
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        int a;
        scanf("%d", &a);
        v[a].pb(i);
        //what_is(a);
        //what_is(i);
    }
    for( int i = 0; i < m; i++ )
    {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int ans = l;

        auto it = lower_bound( v[x].begin(), v[x].end(), l );
        //what_is(it - v[x].begin());
        if( it == v[x].end() )
        {
            cout << l << "\n";
            continue;
        }
        if( *it != l )
        {
            cout << l << endl;
            continue;
        }

        else
        {
            int s = it - v[x].begin();
            ans++;
            while( v[x][s] <= r && ans > v[x][s] )
            {
                if( v[x][s+1] == ans )
                {
                    ans++;
                }
                s++;
            }
            if( ans <= r )
                cout << ans << "\n";
            else
                cout << -1 << "\n";
        }
    }
    return 0;
}



