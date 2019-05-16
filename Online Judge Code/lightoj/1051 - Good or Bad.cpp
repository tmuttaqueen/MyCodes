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

char str[100], temp1[100], temp2[100];
int dpc[100][2], dpv[100][2];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        for( int i = 0; str[i]; i++ )
        {
            if( str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' )
                str[i] = 'A';
            else if( str[i] != '?' )
                str[i] = 'C';

            if( str[i] == '?' )
            {
                temp1[i] = 'C';
                temp2[i] = 'A';
            }
            else temp1[i]= temp2[i] = str[i];
        }
        //cout << str << endl;
        int f = 1; //1 - mixed
        int l = strlen(str);
        temp1[l] = temp2[l] = '\0';
        int f1 = 0, f2 = 0, mc = 0, mv = 0,c  = 0, v = 0;
        for( int i = 0; i < l; i++ )
        {
            if( str[i] == 'A' )
            {
                v++;
                c = 0;
            }
            else if( str[i] == 'C' )
            {
                c++;
                v = 0;
            }
            else
            {
                c = 0;
                v = 0;
            }
            if( c >= 5 || v >= 3 ) f = 0;
            if( temp1[i] == 'C' )
                mc++;
            else
                mc = 0;
            if( mc >= 5 )
                f1 = 1;

            if( temp2[i] == 'A' )
                mv++;
            else
                mv = 0;
            if( mv >= 3 )
                f2 = 1;
        }
        if( f1 == 0 && f2 == 0 )
        {
            printf("Case %d: GOOD\n", caseno++);
            continue;
        }

        //memset( dpc, 120, sizeof dpc );
        //memset( dpv, 120, sizeof dpv );
        //dpc[l][0] = dpc[l][1] = dpv[l][0] = dpv[l][1] = 0;

        for( int i = 0; i < l; i++ )
        {
            dpv[i][0] = dpc[i][0] = 0;
            int c = 1, v = 1;
            for( int j = i-1; j >= 0; j-- )
            {
                if( str[j] == '?' )
                {
                    break;
                }
                else if( v == 1 && str[j] == 'A'  )
                {
                    dpv[i][0]++;
                    c = 0;
                }
                else if( c == 1 && str[j] == 'C' )
                {
                    dpc[i][0]++;
                    v = 0;
                }
                else
                    break;
            }
            c = 1;
            v = 1;
            dpv[i][1] = dpc[i][1] = 0;
            for( int j = i+1; j < l; j++ )
            {
                if( str[j] == '?' )
                {
                    break;
                }
                else if( v == 1 && str[j] == 'A'  )
                {
                    dpv[i][1]++;
                    c = 0;
                }
                else if( c == 1 && str[j] == 'C' )
                {
                    dpc[i][1]++;
                    v = 0;
                }
                else
                    break;
            }
            if( (dpv[i][0] == 2 && dpc[i][1] == 4) ||  (dpv[i][1] == 2 && dpc[i][0] == 4) )
            {
                f = 0;
                break;
            }
            else if( dpv[i][0] == 2 || dpv[i][1] == 2 )
            {
                str[i] = 'C';
            }
            else if( dpc[i][0] == 4 || dpc[i][1] == 4 )
            {
                str[i] = 'A';
            }
        }
        if(f)
        {
            printf("Case %d: MIXED\n", caseno++);
        }
        else
        {
            printf("Case %d: BAD\n", caseno++);
        }
    }
    return 0;
}
