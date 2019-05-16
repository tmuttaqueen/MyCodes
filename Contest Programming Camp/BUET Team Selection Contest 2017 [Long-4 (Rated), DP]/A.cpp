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

int ara[22];
int vec[22], c = 0, d;
int dp1[1111], dp2[1111];

bool ispos()
{
    int x=0, m = c/2;
    dp1[x++] = 0;
    for( int i = 0; i < m; i++ )
    {
        int y = x;
        for( int j = 0; j < y; j++ )
        {
            dp1[x++] = dp1[j] + vec[i];
        }
    }
    int y = 0;
    dp2[y++] = 0;
    for( int i = m; i < c; i++ )
    {
        int p = y;
        for( int j = 0; j < p; j++ )
        {
            dp2[y++] = dp2[j] + vec[i];
        }
    }
    sort( dp2, dp2+y );
    for( int i = 0; i < x; i++ )
    {
        if( binary_search( dp2, dp2+y, d-dp1[i] ) )
        {
            return 1;
        }
    }
    return 0;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n,s = 0;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
            s += ara[i];
        }

        if(s%4)
        {
            cout << "no" << endl;
        }
        else
        {
            d = s/4;
            int f = 0, ss;
            for( int i = (1<<n)-1; i > 0; i-- )
            {
                //what_is(i);
                c = 0;
                ss =0;
                for( int j = n-1; j >= 0; j-- )
                {
                    if( i&(1<<j) )
                    {
                        vec[c++] = ara[j];
                        ss += ara[j];
                    }
                }
                int f1;

                if(2*d == ss && c > 1 )
                    f1 = ispos();
                else
                    f1 = 0;

                c = 0;
                ss = 0;
                for( int j = n-1; j >= 0; j-- )
                {
                    if( !(i&(1<<j)) )
                    {
                        vec[c++] = ara[j];
                        ss += ara[j];
                    }
                }
                int f2;
                if(2*d == ss && c > 1)
                    f2 = ispos();
                else
                    f2 = 0;
                if( f1&f2 )
                {
                    f = 1;
                    cout << "yes" << endl;
                    break;
                }
            }
            if(!f)
            {
                cout << "no" << endl;
            }

        }
    }
    return 0;
}
