#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

int tree[8*100000];
int lazy[8*100000];

void relax( int cn, int s, int e )
{
    lazy[cn] = 0;
    tree[cn] = 0;
    if( s != e )
    {
        tree[cn*2] = 0;
        tree[cn*2+1] = 0;
        lazy[2*cn] = lazy[2*cn+1] = 1;
    }
}

int query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)/2;
    int l1 = query( cn*2, s, m, x, y );
    int l2 = query( cn*2+1, m+1, e, x, y );
    return l1+l2;
}

void update( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] )
        relax( cn, s, e );
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        relax(cn, s, e);
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y );
    update( cn*2+1, m+1, e, x, y );
    tree[cn] = tree[cn*2] + tree[cn*2+1];
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        stack<pii>st;
        int n, ans = 0;
        pii a;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &a.xx, &a.yy );
            st.push(a);
        }
        memset( lazy, 0, sizeof(lazy) );
        for( int i = 0; i < 800000; i++ ) tree[i] = 1;
        while( !st.empty() )
        {
            a = st.top();
            //debug;
            if( query(1, 1, 2*n, a.xx, a.yy) )
            {
                //cout << a.xx << " " << a.yy << endl;
                ans++;
                update( 1, 1, 2*n, a.xx, a.yy );
            }
            st.pop();
        }
        printf("Case %d: %d\n", caseno++, ans);
        //for( int i = 1; i < 11; i++ ) cout << tree[i] << " ";
    }

    return 0;
}



