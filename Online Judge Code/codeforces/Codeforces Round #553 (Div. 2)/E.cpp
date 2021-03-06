#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

vector<int> val[MAXN];

intl ara[MAXN], tree[3*MAXN], lazy[3*MAXN];

void propagate( int cn, int s, int e )
{
    tree[cn] += lazy[cn]*(e-s+1);
    if( s != e )
    {
        lazy[cn*2] += lazy[cn];
        lazy[cn*2+1] += lazy[cn];
    }
    lazy[cn] = 0;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    if( lazy[cn] )
        propagate(cn, s, e);
    if( e < x || s > y )
        return ;
    if( s >= x && e <= y )
    {
        lazy[cn] += v;
        propagate(cn, s, e);
        return ;
    }

    int m = (s+e)/2, l = cn*2;
    update( l, s, m, x, y, v );
    update(l+1, m+1, e, x, y, v);
    tree[cn] = tree[l] + tree[l+1];

}

intl query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] )
        propagate(cn, s, e);
    if( e < x || s > y )
        return 0;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }

    int m = (s+e)/2, l = cn*2;
    intl a = query( l, s, m, x, y );
    intl b = query(l+1, m+1, e, x, y);
    return a + b;
}

int flag[MAXN], aa[MAXN];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        flag[i] = 1;
        int a;
        cin >> a;
        aa[i] = a;

        val[a].push_back(i);
    }
    aa[n+1] = -1;
    aa[0] = -1;
    if( n == 1 )
    {
        cout << 1 << endl;
        return 0;
    }
    int node = n, edge = n - 1;
    for( int i = 1; i <= n; i++ )
    {
        update(1, 1, n, i, i, node - edge);
        node -= val[i].size();
        for( int v: val[i] )
        {
            if( aa[v-1] >= i )
                edge--;
            if(aa[v+1] > i )
                edge--;
        }
        //update(1,1,n,i,i, node - edge);
    }
    intl ans = 0;
    for( int i = n; i >= 1; i-- )
    {
//        cout << i << endl;
//        for( int j = 1; j <= i; j++ )
//        {
//            cout << query(1,1,n,j,j) << " ";
//        }
//        cout << endl;
        ans += query( 1, 1, n, 1, i );
        update(1, 1, n, 1, n, -val[i].size());
        for( int v: val[i] )
        {
            if( v == n && aa[v-1] <= i )
            {
                update(1, 1, n, 1,aa[v-1], 1 );
            }

            else if( v == 0 && aa[v+1] < i )
            {
                update(1, 1, n, 1,aa[v+1], 1 );
            }
            else
            {
                if( aa[v-1] <= i )
                {
                    update(1, 1, n, 1, aa[v-1], 1 );
                }
                if( aa[v+1] < i )
                {
                    update(1, 1, n, 1, aa[v+1], 1 );
                }
            }
        }
    }

    cout << ans << endl;





    return 0;
}
