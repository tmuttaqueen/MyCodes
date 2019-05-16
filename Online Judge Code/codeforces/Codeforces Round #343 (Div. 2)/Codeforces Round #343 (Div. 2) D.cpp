#include <bits/stdc++.h>

using namespace std;

double pi = 2*acos(0.0);


unsigned long long maxx( unsigned long long a, unsigned long long b )
{
    if( a > b )
        return a;
    else
        return b;
}

unsigned long long tree[300015], sum[100005];
unsigned long long r, h, n;
unsigned long long mark[100005];
pair<unsigned long long, int> temp[100005];
map<unsigned long long, unsigned long long> mm;
unsigned long long ara[100005];

unsigned long long query( unsigned long long s , unsigned long long e , unsigned long long k, unsigned long long l, int cur  )
{
    if( e < k || s > l )
        return 0;
    if( s >= k && e <= l )
        return tree[cur];
    unsigned long long mid = (e+s)/2;
    return maxx(query(s, mid, k, l, cur*2 ), query( mid+1, e, k, l, cur*2+1 )) ;
}

void update( unsigned long long s, unsigned long long e, int cur, int node, unsigned long long val )
{
    if( node < s || node > e  )
        return;
    if( s == e )
    {
        tree[cur] = val;
        return;
    }
    unsigned long long mid = (e+s)/2;
    update( s, mid, cur*2, node, val );
    update( mid+1, e, cur*2+1, node, val );
    tree[cur] = maxx(tree[cur*2], tree[cur*2+1]);
    return;
}

bool comp( pair<unsigned long long, int> a, pair<unsigned long long, int> b )
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> r >> h;
        ara[i] = r*r*h;
        temp[i].first = ara[i];
        temp[i].second = i;
    }
    sort( temp+1, temp+n+1 );
    for( int i = 1; i <= n; i++ )
    {
        unsigned long long a = temp[i].first;
        int f = temp[i].second;
        if( mm.count(a) == 0 )
            mm[a] = i;
        mark[f] = mm[a];
    }
    for( int i = 1; i <= n; i++ )
    {
        unsigned long long a = ara[i], b = mark[i];
        //cout << " a " << a << " b " <<  b << endl;
        unsigned long long q = query( 1, n, 1, (int)b - 1, 1 );
        update( 1, n, 1, b, a + q );
        //cout << a + q << endl;
        sum[i] = a+q;
    }
    unsigned long long ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        //cout << "sum[" << i << "] is: " << sum[i] << endl;
        if( sum[i] > ans )
            ans = sum[i];
    }
    double d = pi*(double)ans;
    cout << fixed << setprecision(10) << d << endl;
    return 0;
}


