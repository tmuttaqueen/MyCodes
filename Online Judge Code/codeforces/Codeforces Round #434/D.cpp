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
#define filein      freopen("output.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
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
map<intl, int>mm;
string ara[111111];
set<intl>ss[77777];
intl val[] = { 11, 13, 17, 19, 31, 37, 47, 53, 67, 71 };
intl mapp( const string &s, int x, int y )
{
    intl ans = 0;
    int d = x+y;
    for( int i = x; i < d; i++ )
    {
        ans = ans*43 + val[s[i] -'0'];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    string s;
    cin >> n;
    for( int k = 0; k < n; k++ )
    {
        cin >> s;
        ara[k] = s;
        for( int i = 0; i < 9; i++ )
        {
            for( int j = i; j < 9; j++ )
            {
                ss[k].insert( mapp( s,i, j-i+1  ) );
            }
        }
        //cout << ss[i].size() << endl;
        for( intl x: ss[k] )
        {
            mm[x]++;
        }
    }
    for( int i = 0; i < n; i++ )
    {
        s = ara[i];
        int f = 0;
        for( int i = 1; i <= 9 && f == 0; i++ )
        {
            for( int j = 0; j <= 9-i && f == 0; j++ )
            {
                if( mm[ mapp(s, j, i) ] == 1 )
                {
                    cout << s.substr(j,i) << endl;
                    f = 1;
                }
            }
        }
    }
    return 0;
}
