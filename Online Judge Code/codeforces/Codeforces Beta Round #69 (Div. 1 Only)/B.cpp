/*
“Perhaps this is why lunatics have a harder time dating, not because they are off the wall
but because it is hard to find someone who is willing to date so many people in one person.”
— Elif Safak, The Bastard of Istanbul
*/
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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int aa, bb;
        cin >> aa >> bb;
        double a = aa, b = bb;
        if( bb == 0 )
        {
            cout << 1 << endl;
        }
        else if( aa == 0 )
        {
            cout << 0.5 << endl;
        }
        else if( aa <= 4*bb )
        {
            cout << setprecision(10) << fixed << (a*b+a*a/8)/(2*a*b) << endl;
        }
        else
        {
            cout << setprecision(10) << fixed << (a - b)/a<< endl;
        }
    }
    return 0;
}




