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

intl ara[M], sum[M];

vector<int>vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, n;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i];
            sum[i] = sum[i-1] + ara[i];
        }
        vec.clear();
        vec.resize(n+2);
        for( int i = 1; i <= n; i++ )
        {
            int l = 1, r = i-1, ans = -1;
            while( l <= r )
            {
                int m = (l+r)/2;
                if( sum[i-1] - sum[m] <= ara[i] )
                {
                    r = m - 1;
                    ans = m;
                }
                else
                    l = m + 1;
            }
            //what_is(ans);
            if( ans != -1 )
            {
                vec[ans]++;
                vec[i]--;
            }

            l = i+1; r = n; ans = -1;
            while( l <= r )
            {
                int m = (l+r)/2;
                if( sum[m-1] - sum[i] <= ara[i] )
                {
                    l = m + 1;
                    ans = m;
                }
                else
                    r = m - 1;
            }
            //what_is(ans);
            if( ans != -1 )
            {
                vec[ans+1]--;
                vec[i+1]++;
            }
        }
        for( int i = 1; i <= n; i++ )
            vec[i] += vec[i-1];
        for( int i = 1; i <= n; i++ )
            cout << vec[i] << " ";
        cout << endl;
    }
    return 0;
}
