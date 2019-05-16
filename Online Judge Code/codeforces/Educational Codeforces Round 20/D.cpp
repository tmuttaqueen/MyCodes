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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

char s[1111111];
vector<int>v;
int len, k;

int isp( int x )
{
    int st = 0, c = 0;
    for( int m: v)
    {
        if( m - st > x )
            return 0;
        st = m;
    }
    st = 0;
    for( int i = 0; i < v.size(); i++ )
    {
        //what_is(st);
        while( i < v.size() && v[i] <= st+x )
        {
            i++;
        }
        if( i == v.size() )
        {
            if( c+1 <= k )
                return 1;
            else
                return 0;
        }
        else
        {
            i--;
            st = v[i];
            c++;
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;

    scanf("%d\n", &k);
    gets(s);
    len = strlen(s);
    for( int i = 0; i < len; i++ )
    {
        if( s[i] == ' ' || s[i] == '-' )
        {
            v.pb(i+1);
        }
    }
    v.pb(len);
    /*for( int x: v )
        cout <<x << " ";
    cout << endl;*/
    int l = 1, r = len, ans = -1;
    while( l <= r )
    {
        int m = (l+r)/2;
        //cout << l << " " << r << " " << m << endl;
        int v = isp( m );
        if(v)
        {
            ans = m;
            r = m-1;
        }
        else
            l = m+1;
    }
    cout << ans << endl;
    return 0;
}




