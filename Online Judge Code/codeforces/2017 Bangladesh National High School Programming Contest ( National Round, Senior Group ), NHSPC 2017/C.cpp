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
const int SZ = 1000005, mod = 1000000001;

vector<pii>ara(SZ,mp(0,0));
map<int,int>mm;
int c = 0;

intl gcd( intl a, intl b )
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    if( n <= 3 )
    {
        intl ara[3];
        for( int i =0; i < n; i++ ) cin >> ara[i];
        if( n == 1 )
        {
            cout << ara[0]%mod << endl;
        }
        else if( n == 2 )
        {
            intl g = gcd( ara[0], ara[1] );
            ara[0]/=g;
            ara[1]/=g;
            ara[0] %= mod;
            ara[1] %= mod;
            intl ans = ara[0]*ara[1];
            ans %= mod;
            cout << ans << endl;
        }
        else
        {
            intl g = gcd( ara[0], ara[1] );
            g = gcd( g, ara[2] );
            for( int i = 0; i < 3; i++ ) ara[i]/=g;
            for( int i = 0; i < 3; i++ )
            {
                for( int j = i+1; j < 3; j++ )
                {
                    intl g = gcd( ara[i], ara[j] );
                    ara[i]/=g;
                    ara[j]/=g;
                }
            }
            for( int i = 0; i < 3; i++ ) ara[i]%=mod;
            intl ans = 1;
            for( int i = 0; i < 3; i++ ) ans = (ans*ara[i])%mod;
            cout << ans << endl;
        }
    }
    else
    {
        intl d = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> d;
            for( intl x = 2; x*x <= d; x++ )
            {
                if( d%x == 0 )
                {
                    int p = 0;
                    while(d%x==0)
                    {
                        p++;
                        d/=x;
                    }
                    if( mm[x] == 0 )
                    {
                        mm[x] = c++;
                    }
                    int ind = mm[x];
                    if( ara[ind].xx <= p )
                    {
                        ara[ind].yy = ara[ind].xx;
                        ara[ind].xx = p;
                    }
                    else if( ara[ind].yy <= p )
                    {
                        ara[ind].yy = p;
                    }
                }
            }
            //what_is(d);
            if( d != 1 )
            {
                int x = d, p = 1;
                if( mm[x] == 0 )
                {
                    mm[x] = c++;
                }
                int ind = mm[x];
                if( ara[ind].xx <= p )
                {
                    ara[ind].yy = ara[ind].xx;
                    ara[ind].xx = p;
                }
                else if( ara[ind].yy <= p )
                {
                    ara[ind].yy = p;
                }
            }
        }

        intl ans = 1;
        for( auto x = mm.begin(); x != mm.end(); x++ )
        {
            int a = x->xx, b = x->yy;

            intl temp = 1;
            intl p = ara[b].xx - ara[b].yy;
            for( int i  =1; i <= p; i++ )
            {
                temp *= a;
            }
            temp %= mod;
            ans = (ans*temp)%mod;
        }
        cout << ans << endl;
    }
    return 0;
}



