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
const int SZ = 1000005, mod = 1000000007;

int ara[SZ];
map<int,int>mm;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int q, st = 300000, bc = 300001;
        scanf("%d", &q);
        cout << "Case " << caseno++ << ": \n";
        //what_is(q);
        while( q-- )
        {
            int type;
            scanf("%d", &type);
            //what_is(type);
            if( type == 1 )
            {
                char ch;
                int a;
                scanf(" %c %d", &ch, &a);
                //what_is(ch);
                //what_is(a);
                if( ch == 'B' )
                {
                    ara[bc] = a;
                    mm[a] = bc++;
                }
                else
                {
                    ara[st] = a;
                    mm[a] = st--;
                }
            }
            else if( type == 2 )
            {
                char ch;
                scanf(" %c", &ch);
                //what_is(ch);
                if( ch == 'B' )
                    bc--;
                else
                    st++;
            }
            else
            {
                char ch;
                int p;
                scanf(" %c %d", &ch, &p);
                //what_is(ch);
                //what_is(p);
                if( ch == 'D' )
                {
                    printf("%d\n", ara[st+p]);
                }
                else
                {
                    printf("%d\n", mm[p]-st );
                    //cout << ara[ mm[p] ] << endl;
                }
            }
        }
        mm.clear();
    }
    return 0;
}



