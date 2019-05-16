#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define double      long double

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const intl mx = 7007;

intl rick[mx], mor[mx];
intl sr[mx], mr[mx];
intl vr[mx], vm[mx];
stack<intl>st;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    intl r, m;
    cin >> r;
    memset( rick, -1, sizeof rick );
    memset( mor, -1, sizeof mor );
    for( int i = 0; i < r; i++ )
    {
        cin >> vr[i];
        rick[ n - vr[i] ] = 1;
        st.push( n - vr[i] );
    }
    sort( vr, vr + r );
    cin >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> vm[i];
        mor[ n - vm[i] ] = 1;
    }
    sort( vm, vm+m );
    rick[0] = mor[0] = 1;
    while( !st.empty() )
    {
        intl d = st.top();
        //what_is(d);
        st.pop();
        for( int i = 0; i < m; i++ )
        {
            intl a = ( d+vm[i] )%n;
            //cout << d << " " << a << endl;
            sr[a]++;
            if( a != 0 && rick[a] != 1 && sr[a] == m )
            {
                rick[a] = 1;
                st.push(a);
            }
            /*a = (d-vm[i]+n+n)%n;
            sr[a]++;
            if( rick[a] != 1 && sr[a] == m )
            {
                rick[a] = 1;
                st.push(a);
            }*/
        }
    }



    for( int i = 1; i < n; i++  )
    {
        intl p = 0;
        if( mor[i] == 1 )
            continue;
        for( intl j = 0; j < m; j++ )
        {
            intl a = (i + vm[j])%n;
            if( rick[a] == 1 )
                p++;
        }
        if( p == m )
            mor[i] = 0;
    }

    for( int i = 1; i < n; i++ )
    {
        if( rick[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < r; j++ )
            {
                intl a = (i + vr[j])%n;
                if( mor[a] == 0 )
                    rick[i] = 1;
                else if( mor[a] == 1 )
                    p++;
            }
            if( p == r )
                rick[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( mor[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < m; j++ )
            {
                intl a = (i + vm[j])%n;
                if( rick[a] == 0 )
                    mor[i] = 1;
                else if( rick[a] == 1 )
                    p++;
            }
            if( p == m )
                mor[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( rick[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < r; j++ )
            {
                intl a = (i + vr[j])%n;
                if( mor[a] == 0 )
                    rick[i] = 1;
                else if( mor[a] == 1 )
                    p++;
            }
            if( p == r )
                rick[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( mor[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < m; j++ )
            {
                intl a = (i + vm[j])%n;
                if( rick[a] == 0 )
                    mor[i] = 1;
                else if( rick[a] == 1 )
                    p++;
            }
            if( p == m )
                mor[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( rick[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < r; j++ )
            {
                intl a = (i + vr[j])%n;
                if( mor[a] == 0 )
                    rick[i] = 1;
                else if( mor[a] == 1 )
                    p++;
            }
            if( p == r )
                rick[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( mor[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < m; j++ )
            {
                intl a = (i + vm[j])%n;
                if( rick[a] == 0 )
                    mor[i] = 1;
                else if( rick[a] == 1 )
                    p++;
            }
            if( p == m )
                mor[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( rick[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < r; j++ )
            {
                intl a = (i + vr[j])%n;
                if( mor[a] == 0 )
                    rick[i] = 1;
                else if( mor[a] == 1 )
                    p++;
            }
            if( p == r )
                rick[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( mor[i] == -1 )
        {
            int p = 0;
            for( intl j = 0; j < m; j++ )
            {
                intl a = (i + vm[j])%n;
                if( rick[a] == 0 )
                    mor[i] = 1;
                else if( rick[a] == 1 )
                    p++;
            }
            if( p == m )
                mor[i] = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( rick[i] == 1 )
        {
            cout << "Win ";
        }
        else if( rick[i] == 0 )
        {
            cout << "Lose ";
        }
        else
            cout << "Loop ";
    }
    cout << endl;
    for( int i = 1; i < n; i++ )
    {
        if( mor[i] == 1 )
        {
            cout << "Win ";
        }
        else if( mor[i] == 0 )
        {
            cout << "Lose ";
        }
        else
            cout << "Loop ";
    }
    cout << endl;
    return 0;
}






