#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 300005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

map<int,int>mm;
multiset<int> pos, rpos;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, z;
    cin >> n >> z;
    set<pii>ss;
    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        mm[a]++;
        pos.insert( a );
        rpos.insert( -a );
    }
    for( pii p: mm )
    {
        ss.insert( mp( -p.yy, p.xx ) );
    }
    int ans = 0;

    while(!ss.empty())
    {
        pii p = *ss.begin();
        ss.erase( p );
        int x = p.yy, cnt = -p.xx;
        //cout << x << " " << cnt << endl;
        cnt--;
        mm[x]--;
        pos.erase( pos.find(x) );
        rpos.erase( rpos.find(-x) );

        int lft = x - z, rgt = x + z;

        multiset<int>::iterator it;
        int v = -1;


       // cout << lft << " lr " << rgt << endl;
        //for( int q: rpos ) cout << q << " ";

        it = rpos.lower_bound( -lft );

        //cout << "ok" << endl;
        if( it != rpos.end() )
        {
            v = *it;
            v *= -1;

        }
        else
        {
            it = pos.lower_bound(rgt);
            if( it != pos.end() )
            {
                v = *it;
            }
        }
        //cout << x << " mil " << v << endl;
        if(v == -1)
            continue;
        ans++;
        pos.erase( pos.find(v) );
        rpos.erase( rpos.find(-v) );
        //pos.erase( pos.find(x) );
        //rpos.erase( rpos.find(-x) );
        ss.erase( mp( -mm[v], v ) );
        mm[v]--;
        int d = mm[v];
        if(d)
        {
            ss.insert( mp(-d, v) );
        }
        if(cnt)
        {
            ss.insert( mp(-cnt, x) );
        }


    }

    cout << ans << endl;

    return 0;
}
