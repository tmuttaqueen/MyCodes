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

char str[100];
char ara[100], temp[100];
vector<int>vec;
intl fact[100];
int l;


intl perm(int st)
{
    sort( temp + st, temp + l );
    vec.clear();
    int c = 0;
    for( int i = st ; i < l; i++ )
    {
        c++;
        if( i+1 == l || temp[i+1] != temp[i] )
        {
            vec.pb(c);
            c = 0;
        }
    }
    intl tot = fact[l-st];
    for( int i = 0; i < vec.size(); i++ ) tot/= fact[ vec[i] ];
    return tot;
}

void swap( int i, int j )
{
    char t = temp[i];
    temp[i] = temp[j];
    temp[j] = t;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    fact[0] = 1;
    for( int i = 1; i <= 20; i++ ) fact[i] = fact[i-1]*i;
    while(t--)
    {
        intl n;
        scanf("%s %lld", str, &n );
        //what_is(str);
        l = strlen(str);
        sort( str, str+l );
        vec.clear();
        int c = 0;
        //what_is(l);
        for( int i =0 ; i < l; i++ )
        {
            c++;
            //what_is(i);
            if( i+1 == l || str[i+1] != str[i] )
            {
                vec.pb(c);
                c = 0;
            }
        }
        intl tot = fact[l];
        for( int i = 0; i < vec.size(); i++ ) tot/= fact[ vec[i] ];
        //what_is(tot);
        if( tot < n )
        {
            printf("Case %d: Impossible\n", caseno++ );
            continue;
        }
        int cnt = 0;
        for( int i = 0; i < l; i++ )
        {
            sort( str + i, str+l );
            for( int j = i; j < l; j++ )
            {
                if( j > i && str[j-1] == str[j] ) continue;
                //cout << str << endl;
                strcpy(temp, str);
                swap(i, j);
                intl f = perm( i+1 );
                //cout << j << " " << f << endl;
                if( f >= n )
                {
                    //what_is(j);
                    char te = str[i];
                    str[i] = str[j];
                    str[j] = te;
                    break;
                }
                else
                {
                    n -= f;
                }
            }
        }
        printf("Case %d: %s\n", caseno++, str );
    }
    return 0;
}
