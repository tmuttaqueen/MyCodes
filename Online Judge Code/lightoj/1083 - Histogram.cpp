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


int ara[30005], sg[90015];
int n;

int maxx( int p, int q, int r )
{
    int ass = p;
    if( q > ass )
        ass = q;
    if( r > ass )
        ass = r;
    return ass;
}

void build_tree( int s, int e, int node  )
{
    if( s == e )
    {
        sg[node] = s;
        return;
    }
    int mid = (s+e)/2;
    build_tree( s, mid, node*2 );
    build_tree( mid+1, e, node*2+1 );
    if( ara[sg[node*2]] < ara[sg[node*2+1]] )
        sg[node] = sg[node*2];
    else
        sg[node] = sg[node*2+1];
    return;
}

int query( int s, int e, int i, int j, int node )
{
    //what_is(node);
    if( j < s || i > e )
        return -1;
    if( e <= j && s >= i )
        return sg[node];
    int mid = (s+e)/2;
    int a = query( s, mid, i, j, node*2 );
    int b = query( mid+1, e, i, j, node*2+1 );
    if( a == -1 )
        return b;
    if( b == -1 )
        return a;
    if( ara[a] < ara[b] )
        return a;
    else
        return b;
}

int func( int a, int b )
{
    //cout << "a " << a << "  b  " << b << endl;
    if( b < a )
        return -1;
    if( a == b )
        return ara[a];
    int ind = query( 1, n, a, b, 1 );
    int ans1 = (b-a+1)*ara[ind];
    //what_is(ans1);
    int ans2 = func(a, ind-1 );
    //what_is(ans2);
    int ans3 = func(ind+1, b );
    //what_is(ans3);
    //while(1);
    return maxx(ans1, ans2, ans3);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno =1;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i];
        }
        build_tree(1, n, 1);
        int ans = func(1,n);
        cout << "Case " << caseno++ << ": " << ans << endl;
    }

    return 0;
}



