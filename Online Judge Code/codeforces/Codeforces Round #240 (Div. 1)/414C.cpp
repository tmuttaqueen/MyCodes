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
const int M = 1<<21;
int ara[M];
intl inv[22][2]; //0=a1<a2, 1=a2<a1

vector<int> process( int l, int r, int lvl)
{
    //what_is(lvl);
    if( l == r )
    {
        inv[lvl][0] = inv[lvl][1] = 0;
        vector<int>vec;
        vec.pb( ara[l] );
        return vec;
    }
    int m = (l+r)/2;
    vector<int> v1 = process(l, m, lvl+1);
    vector<int> v2 = process(m+1, r, lvl+1);
    intl p1 = -1, p2 = 0, s1 = 0, s2 = 0;
    //cout << "ok " << endl;
    while( p2 < v2.size() )
    {
        while( p1+1 < v1.size() && v1[p1+1] < v2[p2] )
        {
            p1++;
        }
        s1 += p1+1;
        p2++;
    }
    p1 = 0;
    p2 = -1;
    while( p1 < v1.size() )
    {
        while( p2+1 < v2.size() && v2[p2+1] < v1[p1] )
        {
            p2++;
        }
        s2 += p2+1;
        p1++;
    }
    //cout << "ok" << endl;
    inv[lvl][0] += s1;
    inv[lvl][1] += s2;
    vector<int>vec;
    p1 = 0;
    p2 = 0;
    while(1)
    {
        if( p2 == v2.size() && p1 == v1.size() ) break;
        if( (p1 < v1.size() && v1[p1] <= v2[p2]) || p2 == v2.size() )
        {
            vec.pb( v1[p1++] );
        }
        else if( (p2 < v2.size() && v2[p2] < v1[p1]) || p1 == v1.size() )
        {
            vec.pb( v2[p2++] );
        }

    }
    return vec;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    int tot = 1<<n;
    for( int i = 1; i <= tot; i++ )
    {
        cin >> ara[i];
    }
    //debug;
    process(1, tot, 0);
    //debug;
    int q;
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        intl ans = 0;
        for( int i = n-a; i <= 20; i++ )
        {
            swap( inv[i][0], inv[i][1] );
        }
        for( int i = 0; i <= 20; i++ )
        {
            ans += inv[i][1];
        }

        cout << ans << endl;
    }
    return 0;
}
