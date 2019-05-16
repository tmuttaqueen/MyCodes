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
//#define double      long double

//find_by_order(int) and order_of_key(int)
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
        long double r;
        cin >> r;
        long double s1, s2, s3, s4;
        //s1 = 2*r/sqrt(3.0) ;
        //s2 = sqrt(3.0)*r;
        //s3 = r/tan(pi/10.0);
        //s4 = r/tan(pi/14.0);
        //long double R1 = (s1+s2+s3)/2.0, R2 = (s1+s2+s4)/2.0;
        cout << setprecision(12) << fixed << r*3.00 << " " << r*3.71 << endl;
    }
    return 0;
}
