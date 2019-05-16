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

struct Fraction
{
    long long x, y;
    Fraction()
    {
        x = 0;
        y = 1;
    }
    Fraction( long long a, long long b )
    {
        long long g = gcd(a, b);
        x = a/g;
        y = b/g;
    }
    inline long long gcd( long long a, long long b ) const
    {
        return b == 0? a:gcd(b, a%b);
    }
    inline Fraction operator+( const Fraction &rhs ) const
    {
        long long p = x*rhs.y+y*rhs.x;
        long long q = y*rhs.y;
        long long g = gcd(p, q);
        return Fraction(p/g, q/g);
    }
    inline Fraction operator-( const Fraction &rhs ) const
    {
        long long p = x*rhs.y-y*rhs.x;
        long long q = y*rhs.y;
        long long g = gcd(p, q);
        return Fraction(p/g, q/g);
    }
    inline Fraction operator*( const Fraction &rhs ) const
    {
        long long p = x*rhs.x;
        long long q = y*rhs.y;
        long long g = gcd(p, q);
        return Fraction(p/g, q/g);
    }
    inline Fraction operator/( const Fraction &rhs ) const
    {
        long long p = x*rhs.y;
        long long q = y*rhs.x;
        long long g = gcd(p, q);
        return Fraction(p/g, q/g);
    }
    inline bool operator<( const Fraction &rhs ) const
    {
        return y*rhs.x > x*rhs.y;
    }
    inline bool operator==( const Fraction &rhs ) const
    {
        return y*rhs.x == x*rhs.y;
    }
    inline bool operator>( const Fraction &rhs ) const
    {
        return y*rhs.x < x*rhs.y;
    }
};
const int MAX = 100005;
vector< pair<Fraction, Fraction> > vec;
vector< pair<Fraction, int> >ara;


///1D BIT O(logn)
const int mx = 100005;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, w, x, v;
    cin >> n >> w;
    for( int i = 0; i < n; i++ )
    {
        cin >> x >> v;
        if( x < 0 )
        {
            x = -x;
            vec.push_back( mp(Fraction(x, v-w), Fraction(x, v+w) ));
        }
        else
        {
            v = -v;
            vec.push_back( mp(Fraction(x, v+w), Fraction(x, v-w) ));
        }
    }
    sort( vec.begin(), vec.end() );
    reverse( vec.begin(), vec.end() );
    ara.push_back( mp( Fraction(0,1), 0 ) );
    intl ans = 0, c = 0;;
    for( int i = 0; i < vec.size(); i++ )
    {
        if( i > 0 && vec[i-1].xx == vec[i].xx && !(vec[i-1].yy == vec[i].yy) )
        {
            c++;
        }
        else
        {
            ans += c*(c+1)/2;
            c = 0;

        }
        //cout << vec[i].xx.x << "/" << vec[i].xx.y << " and " << vec[i].yy.x << "/" << vec[i].yy.y << endl;
        ara.push_back( mp( vec[i].yy, i+1 ) );
    }
    ans += c*(c+1)/2;
    sort( ara.begin()+1, ara.end() );

    for( int i = 1; i <= n; i++ )
    {
        ans += query( ara[i].yy );
        update( ara[i].yy, 1 );
    }
    cout << ans << endl;
    return 0;
}
