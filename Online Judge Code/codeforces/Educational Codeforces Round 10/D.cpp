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

bool comp( pair<pii, int> a, pair<pii, int> b )
{
    return a.xx.xx < b.xx.xx;
}

vector<int>sum(400005), tree(4*400005);

void init( int cn, int s, int e )
{
    if( s == e )
    {
        //what_is(cn);
        tree[cn] = sum[s];
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1, e );
    tree[cn] = tree[cn*2]+tree[cn*2+1];
    return;
}

int query( int cn, int s, int e, int i, int j )
{
    if( s > j || e < i ) return 0;
    if( s >= i && e <= j ) return tree[cn];
    int m = (s+e)/2;
    int q1 = query( cn*2, s, m, i, j );
    int q2 = query( cn*2+1, m+1, e, i, j );
    return q1+q2;
}

void update( int cn, int s, int e, int x )
{
    if( e < x || s > x ) return;
    if( e == s && e == x )
    {
        tree[cn] = 0;
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x );
    update( cn*2+1, m+1, e, x );
    tree[cn] = tree[cn*2] + tree[cn*2+1];
    return;
}



int main()
{
    ios::sync_with_stdio(0);
    //filein;
    int n, a, b;
    cin >> n;
    vector<int>v2;
    vector<pair<pii,int>>v1;
    for( int i = 0; i < n; i++ )
    {
        cin >> a >> b;
        v1.pb({{a,b}, i});
        v2.pb(a);
        v2.pb(b);
    }
    map<int, int>mm;
    sort( v2.begin(), v2.end() );
    int j = 1;
    for( int i = 1; i <= 2*n; i++ )
    {
        mm[v2[i-1]] = i;
    }
    sort( v1.begin(), v1.end(), comp );
    for( int i = 0; i < n; i++ )
    {
        v1[i].xx.xx = mm[v1[i].xx.xx];
        v1[i].xx.yy = mm[v1[i].xx.yy];
        sum[v1[i].xx.yy] = 1;
    }
    //debug;
    init( 1, 1, 2*n );
    //debug;
    int ans[n+10];
    for( int i = 0; i < n; i++ )
    {
        a = query( 1, 1, 2*n, v1[i].xx.xx+1, v1[i].xx.yy - 1 );
        update( 1, 1, 2*n, v1[i].xx.yy );
        //what_is(v1[i].xx.yy);
        ans[ v1[i].yy ] = a;
    }
    for( int i = 0; i < n; i++ ) cout << ans[i] << "\n";
    return 0;
}
