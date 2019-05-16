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

int ara[4][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n = 0;
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            cin >> ara[i][j];
        }
    }

    for( int i = 0; i < 4; i++ )
    {
        if( ara[i][3] == 1 )
        {
            for( int j = 0; j < 3; j++ )
            {
                if( ara[i][j] == 1 )
                    n = 1;
            }
        }

    }
    if( ara[0][3] == 1 && ( ara[2][1] == 1 || ara[1][0] == 1 || ara[3][2] == 1)  ) n = 1;
    if( ara[1][3] == 1 && ( ara[3][1] == 1 || ara[0][2] == 1 || ara[2][0] == 1)  ) n = 1;
    if( ara[2][3] == 1 && ( ara[0][1] == 1 || ara[1][2] == 1 || ara[3][0] == 1)  ) n = 1;
    if( ara[3][3] == 1 && ( ara[1][1] == 1 || ara[0][0] == 1 || ara[2][2] == 1)  ) n = 1;

    if(n)
        cout << "YES\n";
    else
        cout << "NO\n";


    return 0;
}



