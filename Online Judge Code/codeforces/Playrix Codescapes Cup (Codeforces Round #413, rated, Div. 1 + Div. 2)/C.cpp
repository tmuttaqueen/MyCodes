#include <iostream>
#include<cmath>
#include <stdlib.h>
#include<time.h>



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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii c[300000], d[300000];
intl dp1[300000], dp2[300000];

int main()
{
    srand((unsigned)time(0));
    for( int i = 0; i < 1000; i++ )
    {


        int n, t, k,d;
        //cin >> n >> t >> k >> d;
        n = 1+(43*i+65)%1000;
        t = 1+(54*(i+1)+34)%1000;
        k = 1+(3*(i+3)+5)%1000;
        d = 1+(53*i*i+64)%1000;
        int z = n;
        int x, y;
        int count = 0, cc = 1000000000;
        while ( n > 0)
        {
            count = d;
            x= ceil(double(n)/k);
            x = ceil(x/2.0);
            count += x*t;
            cc = min(count, cc);
            //what_is(cc);
            n -= k;
        }
        n = z;
        /*z = ceil(double(n)/k)*t;
        if( cc >= z )
            cout << "NO\n";
        else
            cout << "YES\n";*/
        int  cur = 1,j = -1;
        int t1 = ceil( double(n)/k )*t, t2 = 0;
        //what_is(t1);
        for( int i = 1; i <= 10000000; i++ )
        {
            if(n > 0 && i%t == 0)
            {
                t2 = i;
                n -= k;
            }
            if(  n > 0 && cur > 1 && j%t == 0 )
            {
                t2 = i;
                n -= k;
            }
            if( n < 1 )
                break;
            if( i == d )
            {
                j = 0;
                cur++;
            }
            if( cur > 1 ) j++;
        }
        n = z;
        if( cc != t2 )
        {
            cout << n << " " << t << " " << k << " " << d << endl;
        }
    }
}




