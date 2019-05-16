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

intl ara[111], a,c;
map<int,int>mm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    int x = 0;
    c =1;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        if( i > 1 && ara[i] == ara[i-1])
        {
            continue;
        }
        for( intl i = 2; i*i <= a; i++ )
        {
            if( a%i == 0 )
            {
                int p = 0;
                while(a%i==0)
                {
                    a/=i;
                    p++;
                }
                mm[i] = max( mm[i], p );
            }
        }
        if( a != 1 )
        {
            mm[a] = max( mm[a],1 );
        }
    }
    if( c == n )
    {

    }
    if(x || c==n)
    {
        cout << "Arpa" << endl;
    }
    else
        cout << "Mojtaba" << endl;
    //what_is(x);
    return 0;
}
