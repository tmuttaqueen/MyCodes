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
#define pii         pair<intl, intl>
#define piii        pair<intl, pair<intl, intl> >

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

map<pii, int>mm;
priority_queue< piii >pq;
intl n, m, r, k, ns, ms;

intl dx[] = {1,-1, 0, 0}, dy[] = {0, 0, 1, -1};
/*
intl calc( intl x, intl y )
{
    //cout << "f: " << x << ' ' << y << endl;
    if( x <= 0 || x > n || y <= 0 || y > m ) return 0;
    intl v = min( min( min(n-x+1, r)*min(m-y+1,r), min(x, r)*min(y, r) ), min( min(y,r)*min(n-x+1, r), min(x, r)*min(m-y+1, r ) ));
    //what_is(v);
    return v;
}
*/
inline intl calc(intl x,intl y)
{
  if( x < 1 || x > n || y < 1 || y > m ) return 0;
  intl x0=max(1LL,x-r+1),y0=max(1LL,y-r+1);
  if(x0>ns || y0>ms) return 0;
  intl px=min(x,ns),py=min(y,ms);
  return 1.0*(px-x0+1)*(py-y0+1);
}

int main()
{
    mm.clear();
    while( !pq.empty() ) pq.pop();
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    cin >> n >> m >> r >> k;
    if( n > m ) swap(n, m);
    ns = n - r + 1; ms = m - r+1;
    double div = max(ms, 0LL)*max(ns, 0LL);
    double cnt = 0;
    //what_is(ns);
    //what_is(ms);
    for( intl x = n/2-2; x <= n/2+2; x++ )
    {
        for( intl y = m/2-2; y <= m/2+2; y++ )
        {
            pq.push( mp( calc(x, y), mp(x,y) ) );
            mm[ mp(x,y) ] = 1;
        }
    }
    int d = 0;
    //what_is(k);
    //what_is(cnt);
    while( !pq.empty() )
    {
        d++;
        piii t = pq.top();
        pq.pop();
        intl x = t.yy.xx, y = t.yy.yy, px, py;
        intl v = t.xx;

        if( k > 0 )
        {
            k--;
            cnt += v;
            //cout << x << " " << y << " " << v << endl;
        }

        for( int i = 0; i < 4 && k > 0; i++ )
        {
            px = x + dx[i];
            py = y + dy[i];
            if( mm.find( mp(px,py) ) == mm.end() )
            {
                mm[ mp(px,py) ] = 1;
                pq.push( mp( calc(px, py), mp(px,py) ) );
                //k--;
            }
        }
        //cout << d << " " << setprecision(10) << fixed << cnt/div << endl;
    }
    //what_is(cnt);
    //what_is(div);
    cout << setprecision(10) << fixed << cnt/div << endl;
    return 0;//main();
}
