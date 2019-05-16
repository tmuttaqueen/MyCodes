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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
//#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    int num = 1, c = 0, ans=-1, ff = 0;
    cin >> n >> m;
    pii ara[111];
    for( int i  = 0; i < m; i++  )
    {
        cin >> ara[i].xx >> ara[i].yy;
        if( ara[i].xx == n )
        {
            ff = 1;
        }
    }
    if( ff =1 )
    {
        for( int i = 0; i < m; i++ )
         {
             if( ara[i].xx == n )
             {
                 cout << ara[i].yy << endl;
                 return 0;
             }
         }

    }
    for( int i = 1; i <= 1000; i++ )
    {
        int f = 1;
        for( int i = 0; i < m;i++ )
        {
            if( ceil( double(ara[i].xx)/num ) != ara[i].yy )
            {
                f = 0;
                break;
            }
        }
        if(f && ans != ceil( (double)n/num))
        {
            //what_is(num);
            ans = ceil( (double)n/num);
            c++;
        }
        num++;
    }
    //what_is(num);
    //what_is(c);
    if( c != 1 )
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}
