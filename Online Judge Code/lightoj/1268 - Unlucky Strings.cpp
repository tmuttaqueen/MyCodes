#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

char all[55], s[55];
intl ara[55][55];
int fail[55], k;

void kmp_failure( char str[], int fail[] )
{
    fail[0] = 0;
    int l = strlen(str);
    int i = 1, sofar = 0;
    while(i < l)
    {
        if( str[i] == str[sofar] )
        {
            fail[i++] = ++sofar;
        }
        else
        {
            if( sofar != 0 )
            {
                sofar = fail[sofar-1];
            }
            else
            {
                if( str[i] == fail[sofar] )
                {
                    fail[i++] = ++sofar;
                }
                else
                    fail[i++] = sofar;
            }
        }
        //what_is(i);
        //what_is(sofar);
    }
}

intl res[55][55];

void multiply( intl res[55][55], intl ara[55][55] )
{
    intl temp[55][55];
    for( int i = 0; i < k; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            intl r = 0;
            for( int l = 0; l < k; l++ )
            {
                r += res[i][l]*ara[l][j];
            }
            temp[i][j] = r;
        }
    }
    for( int i = 0; i < k; i++ )
    {
        for( int j = 0; j < k; j++ )
            res[i][j] = temp[i][j];
    }
}

void matrix_expo(int n)
{
    if( n == 0 )
    {
        return;
    }
    matrix_expo(n/2);
    multiply(res, res);
    if(n&1)
        multiply(res, ara);

}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d %s %s", &n, all, s);
        memset( ara, 0, sizeof ara );
        kmp_failure(s, fail);
        k = strlen(s);
        for( int i = 0; all[i]; i++ )
        {
            for( int j = 0; j < k; j++ )
            {
                if( all[i] == s[j] && j == k-1 ) continue;
                int t = j;
                while( all[i] != s[t] && t > 0 )
                {
                    t = fail[t-1];
                }
                if( t == 0 && s[0] != all[i] ) t--;
                t++;
                //cout << t << "  " << i << "  " << j << endl;
                ara[t][j]++;
            }
        }
        for( int i = 0; i < k; i++ )
        {
            for( int j = 0; j < k; j++ )
            {
                res[i][j] = (i==j);
                //cout << ara[i][j] << " ";
            }
            //cout << endl;
        }
        intl ini[55];
        memset( ini, 0, sizeof ini);
        for( int i= 0; all[i]; i++ )
        {
            if( all[i] == s[0] ) ini[1]++;
            else ini[0]++;
        }
        //cout << ini[0] << " " << ini[1] << endl;
        //printf("Case %d: ", caseno++);
        matrix_expo(n-1);
        intl ans = 0;
        for( int i = 0; i < k; i++ )
        {
            for( int j = 0; j < k; j++ )
            {
                //cout << res[i][j] << " ";
                ans += res[i][j]*ini[j];
            }
            //cout << endl;
        }
        printf("Case %d: %u\n", caseno++, ans);



    }
    return 0;
}
