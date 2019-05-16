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

int x1, y11, x2, y2, w;

double tot = 0;

double intersect( int a, int f )
{
    double area = 0;
    if( f == 1 && (x1-y11+a) >= 0 && (x1-y2+a) >= 0 && (x2-y11+a) >= 0 && (x2-y2+a) >= 0 )
    {
        area = tot;
    }
    if( f == 2 && (x1-y11+a) >= 0 && (x1-y2+a) >= 0 && (x2-y11+a) >= 0 && (x2-y2+a) >= 0 )
    {
        area = tot;
    }
    if( (y2-a) >= x1 && (y2-a) <= x2 && (y11-a) >= x1 && (y11-a) ) //1,3
    {
        int x = x2 - (y2-a), y = x2 - (y11-a);
        double d = y2-y11;
        area = 0.5*d*(x+y);
    }
    else if( (y2-a) >= x1 && (y2-a) <= x2 && (x1+a) >= y11 && (x1+a) <= y2 ) //1,4
    {
        int x = (y2-a) - x1, y = y2 - (x1+a);
        area = 0.5*x*y;
        area = tot - area;
    }
    else if( (x2+a) >= y11 && (x2+a) <= y2 && (y11-a) >= x1 && (y11-a) <= x2  ) //2,3
    {
        int x = (x2+a) - y11, y = x2 - (y11-a);
        area = 0.5*x*y;
    }
    else if( (x1+a) >= y11 && (x1+a) <= y2 && (x2+a) >= y11 && (x2+a) <= y2 )
    {
        int x = (x1+a)-y11, y = (x2+a)-y11;
        double d = (x2-x1);
        area = 0.5*d*(x+y);
    }
    return area;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        cin >> x1 >> x2 >> y11 >> y2 >> w;
        tot = (x2-x1)*(y2-y11);
        double a = w, b = -w;

        a = intersect(a, 1); //up
        b = intersect(b, 2); //down
        //what_is(a);
        //what_is(b);
        a = tot - a;
        double non = max( 0.0, tot - (a+b));
        cout << "Case #" << caseno++ << ": " << setprecision(8) << fixed << non/tot << endl;

    }

    return 0;
}
