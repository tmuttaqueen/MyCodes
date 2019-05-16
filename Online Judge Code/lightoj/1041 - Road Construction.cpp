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

map<string, int> mm;
vector< pair<pii,int> > vec;
int par[110];

bool comp( pair<pii,int> a, pair<pii, int> b )
{
    return a.yy < b.yy;
}

int fpar( int a )
{
    if( par[a] == a )
        return a;
    return par[a] = fpar( par[a] );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        //getchar();
        int n, m, k = 1;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            string a, b;
            cin >> a >> b >> m;
            if( mm[a] == 0 )
            {
                mm[a] = k++;
            }
            if( mm[b] == 0 )
            {
                mm[b] = k++;
            }
            vec.pb( mp( mp(mm[a], mm[b]), m ) );
        }
        for( int i = 0 ; i < 110; i++ ) par[i] = i;
        sort( vec.begin(), vec.end(), comp );
        int ans = 0;
        for( int i = 0; i < n; i++ )
        {
            int pa = fpar( vec[i].xx.xx ), pb = fpar( vec[i].xx.yy );
            if( pa != pb )
            {
                par[pa] = pb;
                ans += vec[i].yy;
            }
        }
        int temp = fpar(1);
        for( int i = 1; i < k; i++ )
        {
            if( fpar(i) != temp )
                ans = -1;
        }
        if( ans != -1 )
            cout << "Case " << caseno++ << ": " << ans << "\n";
        else
            cout << "Case " << caseno++ << ": Impossible" << "\n";
        mm.clear();
        vec.clear();
    }
    return 0;
}



