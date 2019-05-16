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


const int mx = 100000;
struct data
{
    int a, b, c;
};

data tree[4*mx];
int lazy[4*mx];

void relax( int cn, int s, int e )
{
    lazy[cn] %=3;
    if( lazy[cn] == 1 )
    {
        int t = tree[cn].b;
        tree[cn].b = tree[cn].a;
        tree[cn].a = tree[cn].c;
        tree[cn].c = t;
    }
    else if( lazy[cn] == 2 )
    {
        int t = tree[cn].a;
        tree[cn].a = tree[cn].b;
        tree[cn].b = tree[cn].c;
        tree[cn].c = t;
    }
    if(s!=e)
    {
        lazy[cn*2] += lazy[cn];
        lazy[cn*2+1] += lazy[cn];
    }
    lazy[cn] = 0;
}

void init(int cn, int s, int e)
{
    //cout << " cn " << cn << "  " << s << "  " << e << endl;
    if(s==e)
    {
        tree[cn].a = 1;
        tree[cn].b = tree[cn].c = 0;
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1, e );
    tree[cn].a = tree[cn*2].a + tree[cn*2+1].a;
    tree[cn].b = 0;
    tree[cn].c = 0;
    return;
}

void update( int cn, int s, int e, int x, int y )
{
    relax( cn, s, e );
    if( s > y || e < x )
        return;
    if( s >= x && e <=y )
    {
        lazy[cn]++;
        lazy[cn]%=3;
        relax(cn, s, e);
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y );
    update( cn*2+1, m+1, e, x, y );
    tree[cn].a = tree[cn*2].a + tree[cn*2+1].a;
    tree[cn].b = tree[cn*2].b + tree[cn*2+1].b;
    tree[cn].c = tree[cn*2].c + tree[cn*2+1].c;
    return;
}

int query( int cn, int s, int e, int x, int y)
{
    lazy[cn]%=3;
    if( lazy[cn])
    {
        relax( cn, s, e );
    }

    if( s > y || e < x )
    {
        return 0;
    }
    if( s >= x && e <= y )
    {
        //cout << s << ' ' << e << endl;
        relax( cn, s, e );
        return tree[cn].a;
    }
    int m = (s+e)/2;
    int l = query( cn*2, s, m, x, y );
    int r = query( cn*2+1, m+1, e, x, y );
    return l+r;

}
int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        scanf("%d %d",&n, &q);
        printf("Case %d:\n", caseno++);
        init(1, 1, n);
        memset(lazy, 0, sizeof(lazy));
        while(q--)
        {
            int a, x, y;
            scanf("%d %d %d", &a, &x, &y);
            x++;
            y++;
            if( a == 0 )
            {
                update( 1, 1, n, x, y );
            }
            else
            {
                int ans = query( 1, 1, n, x, y );
                printf("%d\n", ans);
                //debug;
            }
        }
    }

    return 0;
}



