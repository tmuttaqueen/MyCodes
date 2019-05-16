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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 100005;

vector<int>prime[M], pr;
int bit = 60;
int ind[M];

void sieve()
{
    int mx = 1e5+5;
    for( int i = 2; i < mx; i+=2 )
        prime[i].pb(2);
    pr.pb(2);
    ind[2] = pr.size()-1;
    for( int i = 3; i < mx; i+=2 )
    {
        if( prime[i].size() == 0 )
        {
            pr.pb(i);
            ind[i] = pr.size()-1;
            for( int j = i; j < mx; j+=i )
            {
                prime[j].pb(i);
            }
        }
    }
}


int ara[M];
intl data[10000][2000];


inline void update(int &p, int &x, int &b)
{
    int d = x/bit + 1;
    int offset = x - bit*(d-1);
    if( b == 0 )
    {
        data[p][d] &= ~(1LL<<offset);
    }
    else
    {
        data[p][d] |= (1LL<<offset);
    }
}

inline int query( int &g, int &l, int &r )
{
    int d1 = l/bit+1, d2 = r/bit+1;
    //what_is(d1);
    //what_is(d2);
    vector<intl>vec(d2-d1+1, 0);
    for( int p: prime[g] )
    {
        p = ind[p];
        for( int i = d1; i <= d2; i++ )
        {
            vec[i-d1] |= data[p][i];
        }
    }
    int cnt = 0;
    for( int i = 0; i < d2-d1+1; i++ )
    {
        //what_is(vec[i]);
        if( i == 0 )
        {
            int offset = l - bit*(d1-1);
            for( int j = offset; j <= bit && bit*(d1-1)+j <= r; j++ )
            {
                if( vec[i]&(1LL<<j) )
                {
                    cnt++;
                }
            }
        }
        else if( i == d2-d1 )
        {
            int offset = r - bit*(d2-1);
            for( int j = 0; j <= offset; j++ )
            {
                if( vec[i]&(1LL<<j) )
                {
                    cnt++;
                }
            }
        }
        else
        {
            cnt += __builtin_popcountll(vec[i]);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    int t = 1, f = 0;
    int n, q;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        for( int p: prime[ ara[i] ] )
        {
            p = ind[p];
            update(p, i, t);
        }
    }
    cin >> q;
    while(q--)
    {
        int c;
        cin >> c;
        if(c == 1)
        {
            int x, y;
            cin >> x >> y;
            x--;
            for( int p: prime[ ara[x] ] )
            {
                p = ind[p];
                update(p, x, f);
            }
            ara[x] = y;
            for( int p: prime[ ara[x] ] )
            {
                p = ind[p];
                update(p, x, t);
            }
        }
        else
        {
            int l, r , g;
            cin >> l >> r >> g;
            l--;
            r--;
            int ans = r -l + 1 - query(g,l,r);
            //debug;
            cout << ans << endl;
        }
    }
    return 0;
}
