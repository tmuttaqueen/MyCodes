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

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

set<int>ss;
int bin = 2;

int trie[333333*20];

void add( int n )
{
    //what_is(n);
    int v = 1;
    for( int i = bin; i >= 0; i-- )
    {
        what_is(v);
        trie[v]++;
        int l = v*2, r = v*2+1;
        if( n&(1<<i) )
        {
            v = r;
        }
        else
        {
            v = l;
        }
    }
    //trie[v]++;
}

int query( int n )
{
    int ans = 0;
    int v = 1;
    for( int i = bin; i>=0; i-- )
    {
        int l = v*2, r = l+1, lim = 1<<(i+1);
        cout << v << " " << lim << " " << l << " " << trie[l] << " " << r << " " << trie[r] << endl;
        if( (n&(1<<i)) && trie[v] < lim )
        {
            cout << "fff 1" << endl;
            ans = ans*2+1;
            v = r;
        }
        else if( (n&(1<<i)) && trie[v] == lim )
        {
            cout << "fff 2" << endl;
            v = l;
            ans = ans*2+0;
        }
        else if(  (n&(1<<i)) == 0 && trie[v] < lim )
        {
            cout << "fff 3" << endl;
            ans = ans*2+0;
            v = l;
        }
        else
        {
            cout << "fff 4" << endl;
            ans = ans*2+1;
            v = r;
        }
    }
    what_is(ans);
    return ans;
}

int c = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n,m;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        ss.insert(a);
    }
    int sz = 0;
    for( int x: ss )
    {
        add(x);
    }
    for( int i =(1<<bin)-1; i> 0 ; i-- )
    {
        trie[i] = trie[i*2] + trie[i*2+1];
    }
    for( int i = 0; i < m; i++ )
    {
        int a;
        cin >> a;
        int ans = a^query(a);
        cout << ans << endl;
    }
    return 0;
}
