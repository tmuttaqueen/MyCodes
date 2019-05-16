#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int par[111111], sz[111111];
map<string, int >mm;
pair<string, string>pp[111111];

int parent( int v )
{
    if( par[v] == v ) return v;
    else return parent(par[v]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int c = 1;
        mm.clear();
        int n;
        cin >> n;
        cin.ignore();
        for( int i = 0; i < n; i++ )
        {
            cin >> pp[i].xx >> pp[i].yy;
            if( mm[pp[i].xx] == 0 )
                mm[pp[i].xx] = c++;
            if( mm[pp[i].yy] == 0 )
                mm[pp[i].yy] = c++;
        }
        for( int i = 1; i < c; i++ )
        {
            par[i] = i;
            sz[i] = 1;
        }
        for( int i = 0; i < n; i++ )
        {
            int a = mm[ pp[i].xx ], b = mm[ pp[i].yy ];
            int pa = parent(a), pb = parent(b);
            if( pa == pb )
            {
                cout << sz[pa] << endl;
            }
            else
            {
                if( sz[pb] < sz[pa] )
                {
                    par[pb] = pa;
                    sz[pa] += sz[pb];
                    cout << sz[pa] << endl;
                }
                else
                {
                    par[pa] = pb;
                    sz[pb] += sz[pa];
                    cout << sz[pb] << endl;
                }
            }
        }
    }
    return 0;
}
