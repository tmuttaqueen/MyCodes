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

intl base[2] = {59, 67};
intl mod = 122949829;
intl po[M][2], inv[M][2];
string s;

long long exponentiation( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}
intl has[2]={0,0}, rhas[2]={0,0};

void print()
{
    cout << has[0] << " " << rhas[0] << "   " << has[1] << " " << rhas[1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n = 2e5+5;
    for( int i = 0; i < 2; i++ )
    {
        po[0][i] = 1;
        inv[0][i] = 1;
        intl pinv = exponentiation( base[i], mod-2, mod );
        for( int j = 1; j < n; j++ )
        {
            po[j][i] = po[j-1][i]*base[i]%mod;
            inv[j][i] = inv[j-1][i]*pinv%mod;
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        has[1] = has[0] = rhas[0] = rhas[1] = 0;
        cin >> s;
        int n = s.length();
        for(int i = 0; i < 2; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                has[i] = ( has[i] + (s[j]-'a')*po[n-j-1][i]%mod )%mod;
                rhas[i] = ( rhas[i] + ( s[j] -'a')*po[j][i]%mod )%mod;
            }
        }
        int ans = 0;

        if( has[0] == rhas[0] && has[1] == rhas[1] ) ans++;
        //print();
        for( int i = 0; i < n-1; i++ )
        {
            int d = s[i] - 'a';

            for( int j = 0; j < 2; j++ )
            {
                has[j] -= d*po[n-1][j]%mod;
                has[j] *= base[j];
                has[j] += d;
                has[j] %= mod;
                rhas[j] -= d;
                rhas[j] = rhas[j]%mod;
                rhas[j] *= inv[1][j];
                rhas[j] += ( d*po[n-1][j] )%mod;
                has[j] = ( has[j] + mod )%mod;
                rhas[j] = ( rhas[j] + mod )%mod;
            }
            //print();
            if( has[0] == rhas[0] && has[1] == rhas[1] ) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
