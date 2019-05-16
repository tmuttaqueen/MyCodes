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
const int M = 1000006, P = 2;
intl pr[P];
intl fh[M][P], rh[M][P];
intl inv[M][P];
long long exponentiation( long long a, long long b, long long &mod )
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pr[0] = 1000000007;
    pr[1] = 100000007;
    pr[2] = 433494437;
    pr[3] = 99990001;
    for( int i = 0; i < P; i++ )
    {
        intl v = 1;
        inv[0][i] = 1;
        for( int j =  1; j < M; j++ )
        {
            v = v*10;
            v %= pr[i];
            inv[j][i] = exponentiation(v, pr[i]-2, pr[i]);
        }
    }

    //filein;
    string s;
    cin >> s;
    if( s[0] =='0' && s[1] == '0' && s[2] == '0' )
    {
        cout << "0+0=0" << endl;
        return 0;
    }
    for( int i = 0; i < P; i++ )
    {
        intl v = 0;
        for( int j = 0; j < s.size(); j++ )
        {
            v = v*10 + s[j] - '0';
            v %= pr[i];
            fh[j][i] = v;
            //cout << j << ' ' << i << " " << fh[j][i] << endl;
        }
    }

    for( int i = 0; i < P; i++ )
    {
        intl v = 0, d = 1;
        for( int j = s.size()-1; j >= 0; j-- )
        {
            v = v + (s[j] - '0')*d;
            d = d*10;
            d %= pr[i];
            v %= pr[i];
            rh[j][i] = v;
            //cout << j << " " << i << " " << rh[j][i] << endl;
        }

    }
    int len = s.size();
    int ss = -1;
    int pls, mul;
    for( int i = 1; i < len; i++ )
    {
        int f = 1;
        pls = i;
        if( (len-i)/2 < i )
        {
            mul = len - i;
        }
        else
            mul = i + (len-i)/2;
        if( mul-pls == pls && len-mul == pls && s[mul] == '0' )
        {
            mul--;
        }
        if( s[mul] == '0' ) continue;
        if( mul - i > 1 && s[i] == '0' ) continue;
        for( int j = 0; j < P; j++ )
        {
            intl h1 = fh[pls-1][j], h3 = rh[mul][j];
            intl h2 = (rh[pls][j] - rh[mul][j])%pr[j];
            h2 = (h2+pr[j])%pr[j];
            h2 = (h2*inv[len-mul][j])%pr[j];
            //cout << pls << " " << mul << " " << h1 << " " << h2 << " " << h3 << endl;
            if( (h1+h2)%pr[j] != h3%pr[j] )
            {
                f = 0;
            }
        }
        if(f)
        {
            ss = -2;
            break;
        }
    }
    if(ss==-2)
    {
        for( int i = 0; i < pls; i++ ) cout << s[i];
        cout << '+';
        for( int i = pls; i < mul; i++ ) cout << s[i];
        cout << '=';
        for( int i = mul; i < len ; i++ ) cout << s[i];
        cout << endl;
    }
    else
    {
        while(1);
        //cout << -1 << endl;
    }
    return 0;
}
