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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
pii ara[M];
vector<int>v1, v2;
int n;

int solve( intl x1, intl x2 )
{
    v1.clear();
    v2.clear();
    int f = 0;
    for( int i = 0; i < n; i++ )
    {
        if( (i+1)*ara[i].xx >= x1 )
        {
            for( int j = 0; j <= i; j++ )
            {
                v1.pb(ara[j].yy);
            }
            f++;
            break;
        }

    }
    int d = v1.size();
    //what_is(d);
    for( int i = d; i < n; i++ )
    {
        if( ara[i].xx *( i - d + 1 ) >= x2 )
        {
            for( int j = d; j <= i; j++ )
            {
                v2.pb(ara[j].yy);
            }
            f++;
            break;
        }
    }
    return f;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl  x1, x2, a;
    cin >> n >> x1 >> x2;

    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        ara[i] = mp(a, i+1);
    }
    sort( ara, ara+n );
    reverse(ara, ara+n);
    int f = solve(x1, x2);
    if(f == 2)
    {
        cout << "Yes" << endl;
        cout<< v1.size() << " " << v2.size() << endl;
        for( int x: v1 )
            cout << x << " ";
        cout << endl;
        for( int x: v2 )
            cout << x << " ";
        cout << endl;
        return 0;
    }
    swap(x1, x2);
    f = solve(x1, x2);
    if(f == 2)
    {
        cout << "Yes" << endl;
        cout<< v2.size() << " " << v1.size() << endl;
        for( int x: v2 )
            cout << x << " ";
        cout << endl;
        for( int x: v1 )
            cout << x << " ";
        cout << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
