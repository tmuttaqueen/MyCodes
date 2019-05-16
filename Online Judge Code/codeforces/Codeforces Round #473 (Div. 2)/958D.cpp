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
#define filein      freopen("output.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 1399828;//1299828;
int flag[M], used[M], in[M];
vector<int>pr[M];
set<int>ss;

void sieve()
{
    for( int i = 2; i < M; i++ )
    {
        ss.insert(i);
        in[i] = 1;
    }
    pr[2].pb(2);
    for( int i = 4; i < M; i+=2 )
    {
        pr[i].pb(2);
        flag[i] = 1;
    }
    for( int i = 3; i < M; i+=2 )
    {
        if( flag[i] == 0 )
        {

            pr[i].pb(i);
            for( int j = i+i; j < M; j += i )
            {
                pr[j].pb(i);
                flag[j] = 1;
            }
        }
    }

}

int ara[M], ans[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    //cout << "ok" << endl;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> ara[i];
    int f = 0;
    for( int i = 0; i < n; i++ )
    {
        int it;
        if( f == 0 )
        {
            it = *ss.lower_bound(ara[i]);
        }
        else
        {
            it = *ss.begin();
        }
        if( it > ara[i] )
            f = 1;
        ss.erase(it);
        in[it] = 0;
        ans[i] = it;
        for( int j = 0; j < pr[it].size(); j++)
        {
            int u = pr[it][j];
            if( used[u] == 0 )
            {
                used[u] =  1;
                for( int x = u; x < M; x += u )
                {
                    if( in[x] == 1 )
                    {
                        ss.erase(x);
                        in[x] = 0;
                    }
                }
            }
        }
    }
    for( int i = 0; i < n; i++ )
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
