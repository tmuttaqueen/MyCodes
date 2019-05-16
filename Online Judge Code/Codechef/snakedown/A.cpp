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

char str[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%s", str);
        int ara[105], m = 0;
        int l = strlen(str);
        for( int i = 0; i < l; i++ )
        {
            if( str[i] == 's' )
                ara[i] = 1;
            else
            {
                m++;
                ara[i] = 0;
            }
        }
        for( int i = 0; i < l; i++ )
        {
            if( str[i] == 'm' )
            {
                if( i > 0 && ara[i-1] == 1 )
                {
                    ara[i-1] = 0;
                }
                else if( i < l - 1 && ara[i+1] == 1 )
                {
                    ara[i+1] = 0;
                }
            }
        }
        int s = 0;
        for( int i = 0; i < l; i++ )
        {
            s += ara[i];
        }
        //what_is(s);
        if( s == m )
        {
            printf("tie\n");
        }
        else if( s > m )
        {
            printf("snakes\n");
        }
        else
        {
            printf("mongooses\n");
        }
    }
    return 0;
}




