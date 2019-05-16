#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("B-large.in", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

char str[100];

int isperfect( int n )
{
    int l = 9;
    while(n)
    {
        int d = n%10;
        n /= 10;
        if( d > l ) return 0;
        l = d;
    }
    return 1;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    filein;
    fileout;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%s", str);
        //cout << str << endl;
        if( strlen(str) <= 4 )
        {
            int d = 0;
            for( int i = 0; str[i]; i++ )
            {
                d = d*10 + ( str[i] - '0' );
            }
            //what_is(d);
            for( int j = d; j >= 1; j-- )
            {
                //what_is(j);
                if( isperfect(j) )
                {
                    printf("Case #%d: %d\n", caseno++, j );
                    break;
                }
            }
        }
        else
        {
            printf("Case #%d: ", caseno++);
            int f = 0, one = 0;
            for( int i = 0; str[i]; i++ )
            {
                if( str[i] > '1' )
                {
                    f = 1;
                    break;
                }
                if( str[i] == '1' ) one++;
            }

            if( f == 1 )
            {
                int d = -1;
                for( int i = 0; i < strlen(str) - 1 ; i++ )
                {
                    if( str[i] > str[i+1] )
                    {
                        int j = i;
                        while( j -1>= 0 && str[j] == str[j-1] )
                            j--;
                        d = j;
                        break;
                    }

                }
                if( d == -1 )
                {
                    printf("%s\n",str);
                }
                else
                {

                    for( int i = 0; i < d; i++ )
                        printf("%c", str[i]);
                    printf("%c", str[d] - 1 );
                    for( int i = d+1; str[i]; i++ )
                    {
                        printf("9");
                    }
                    printf("\n");

                }
            }
            else
            {
                if( one == strlen(str) )
                {
                    printf("%s", str);
                }
                else
                {
                    for( int i =1; i < strlen(str); i++ )
                    {
                        printf("9");
                    }
                    printf("\n");
                }
            }

        }
    }
    return 0;
}




