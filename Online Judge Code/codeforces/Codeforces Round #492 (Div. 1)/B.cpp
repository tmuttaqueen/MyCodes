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

vector<pii>ara;
vector<int> X, Y;
int n, ans;

void find_max()
{
    int val, type, tot = 1e9, prev = 0;
    for( int i = 1; i <= n; i++ )
    {
        prev += abs(X[i]-Y[i]-1);
    }
    //what_is(prev);
    for( int i = 1; i <= n; i++ )
    {
        if( abs( X[i]-Y[i] ) <= 1 ) continue;
        int mov = abs(X[i]-Y[i])-1;
        vector<pii>vec =ara ;
        vector<int>x = X, y = Y;
        int ind = min( x[i], y[i] ), sor = max(x[i], y[i]);
        for( int i = ind; i < sor-1; i++ )
        {

            if( vec[i].yy == 1 )
                x[vec[i].xx] = i+1;
            else
                y[vec[i].xx] = i+1;
            if( vec[i+1].yy == 1 )
                x[vec[i+1].xx] = i;
            else
                y[vec[i+1].xx] = i;
            swap( vec[i], vec[i+1] );
        }
        int all = 0;
        for( int i = 1; i <= n; i++ )
        {
            all += abs(x[i]-y[i])-1;
        }
        int diff = prev - all;

        if( prev - diff < tot )
        {
            tot = prev - diff;
            val = i;
            type = 1;
        }
        else if( prev + diff < tot )
        {
            tot = prev + diff;
            val = i;
            type = 2;
        }
    }
    //cout << val << " " << type<< " " << X[val] << " " << Y[val] << endl;
    ans += abs( X[val] - Y[val])-1;
    if( type == 1 )
    {
        int i = val;
        int ind = min( X[i], Y[i] ), sor = max(X[i], Y[i]);
        for( int i = ind; i < sor-1; i++ )
        {

            if( ara[i].yy == 1 )
                X[ara[i].xx] = i+1;
            else
                Y[ara[i].xx] = i+1;
            if( ara[i+1].yy == 1 )
                X[ara[i+1].xx] = i;
            else
                Y[ara[i+1].xx] = i;
            swap( ara[i], ara[i+1] );
        }
    }
    else
    {
        int i = val;
        int ind = min( X[i], Y[i] ), sor = max(X[i], Y[i]);
        for( int i = sor; i > ind+1; i-- )
        {

            if( ara[i].yy == 1 )
                X[ara[i].xx] = i-1;
            else
                Y[ara[i].xx] = i-1;
            if( ara[i-1].yy == 1 )
                X[ara[i-1].xx] = i;
            else
                Y[ara[i-1].xx] = i;
            swap( ara[i], ara[i-1] );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    ara.resize(333);
    X.resize(102);
    Y.resize(102);
    cin >> n;
    for( int i = 1; i <= 2*n; i++ )
    {
        cin >> ara[i].xx;
        if( X[ ara[i].xx ] == 0 )
        {
            X[ ara[i].xx ] = i;
            ara[i].yy = 1;
        }
        else
        {
            ara[i].yy = 2;
            Y[ ara[i].xx ] = i;
        }

    }

    for( int i = 1; i <= n; i++ )
    {
        find_max();
    }
    cout << ans << endl;
    return 0;
}
