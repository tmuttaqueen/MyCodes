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
const int M = 345678;

template<typename T>
class Bit1D
{
    int sz;
    T *bit;
public:
    Bit1D( int n = 2000000 )
    {
        n += 5;
        sz = n;
        bit = new T[sz];
        init();
    }
    void init(T v = 0)
    {
        for( int i = 0; i < sz; i++ )
            bit[i] = v;
    }
    void add( int x, T val ) //add val to index x
    {
        while( x < sz )
        {
            bit[x] += val;
            x += (x&(-x));
        }
    }

    T query( int x ) //sum from 1 to x (inclusive)
    {
        T sum = 0;
        while( x > 0 )
        {
            sum += bit[x];
            x -= (x&(-x));
        }
        return sum;
    }
};

vector<int>vec;
stack<int>st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    Bit1D<int> bit;
    int n, m, k;
    cin >> n >> m >> k;
    if( k > m )
    {
        cout << 0 << endl;
        return 0;
    }
    int a;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        vec.pb(a);
    }
    sort( vec.begin(), vec.end() );
    int l, r, c = 0;
    m--;
    for( int i = 1; i <= 1000000; i++ )
    {
        l = i;
        r = i+m;
        while( c < vec.size() && vec[c] <= r )
        {
            st.push( vec[c] );
            bit.add( vec[c], 1 );
            c++;
        }
        int s = bit.query( r ) - bit.query(l-1);
        while( s >= k )
        {
            int t = st.top();
            st.pop();
            bit.add( t, -1 );
            s--;
        }
    }
    cout << n-st.size() << endl;
    return 0;
}

