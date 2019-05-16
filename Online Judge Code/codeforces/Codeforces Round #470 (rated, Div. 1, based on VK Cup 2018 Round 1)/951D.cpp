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

char s[M], t[M];
char ans[M];
int sa[M], sb[M], ta[M], tb[M];

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    scanf("%s", s+1);
    scanf("%s", t+1);
    int sl = strlen(s+1);
    int tl = strlen(t+1);
    for( int i = 1; s[i]; i++ )
    {
        if( s[i] == 'C' ) s[i] = 'B';
        if( s[i] == 'A' )
        {
            sa[i] = 1 + sa[i-1];
        }
        else
            sa[i] = sa[i-1];
        if( s[i] == 'B' )
        {
            sb[i] = 1 + sb[i-1];
        }
        else
            sb[i] = sb[i-1];
    }
    for( int i = 1; t[i]; i++ )
    {
        if( t[i] == 'C' ) t[i] = 'B';
        if( t[i] == 'A' )
        {
            ta[i] = 1 + ta[i-1];
        }
        else
            ta[i] = ta[i-1];
        if( t[i] == 'B' )
        {
            tb[i] = 1 + tb[i-1];
        }
        else
            tb[i] = tb[i-1];
    }
    int q;
    scanf("%d", &q);
    //cout << s+1 << " " << t+1 << endl;
    for( int i = 0; i < q; i++ )
    {
        int a, b, c, d;
        //cin >> a >> b >> c >> d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int as = sa[b] - sa[a-1];
        int bs = sb[b] - sb[a-1];
        int at = ta[d] - ta[c-1];
        int bt = tb[d] - tb[c-1];
        if( bs == 0 && ((as%3 != at%3) || (as < at)) )
        {
            ans[i] = '0';
        }
        else if( s[b] == 'B' && t[d] == 'A' )
            ans[i] = '0';
        else if( bs%2 != bt%2 || bs > bt )
            ans[i]= '0';
        else
            ans[i] = '1';
        //what_is(i);
    }
    //while(1);
    ans[q] = '\0';
    printf("%s\n", ans);

    return 0;
}

