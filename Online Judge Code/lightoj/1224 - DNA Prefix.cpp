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

char str[50005][60];
int cur;

struct node
{
    int dd;
    int next[4];
};

node tree[50000*51];

void init( int cn )
{
    tree[cn].dd = 0;
    for( int i = 0; i < 4; i++ )
        tree[cn].next[i] = -1;
}

int id( char c )
{
    if( c == 'A' ) return 0;
    else if( c == 'C' ) return 1;
    else if( c == 'G' ) return 2;
    else return 3;
}

void update( char str[] )
{
    int i = 0, node = 0;
    while( str[i] )
    {
        int d = id( str[i] );
        if( tree[node].next[d] == -1 )
        {
            init(cur);
            node = tree[node].next[d] = cur++;
            tree[node].dd++;
        }
        else
        {
            node = tree[node].next[d];
            tree[node].dd++;
        }

        i++;
    }
}

intl query( char str[] )
{
    intl i = 0, node = 0, ans = 0;
    while( str[i] )
    {
        int d = id( str[i] );
        node = tree[node].next[d];
        ans = max( ans, (long long)tree[node].dd*(i+1) );
        i++;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        cur = 0;
        init(cur++);
        int n;
        scanf("%d\n", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", str[i]);
            update( str[i] );
        }
        intl ans = 0;
        for( int i = 0; i < n; i++ )
        {
            ans = max( ans, query(str[i]) );
        }
        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}



