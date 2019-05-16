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

struct trie
{
    int next[2];
};

trie tree[50005*32];
intl ara[50005], low, high, cur;
char str[40];

void init( intl cn )
{
    tree[cn].next[0] = -1;
    tree[cn].next[1] = -1;
}

void nslice( intl a )
{
    str[32] = '\0';
    for( int i = 31; i >= 0; i-- )
    {
        str[i] = '0' + (a&1);
        a /= 2;
    }
}

void update()
{
    int i = 0, node = 0;
    while( str[i] )
    {
        int d = str[i] - '0';
        if( tree[node].next[d] == -1 )
        {
            init(cur);
            node = tree[node].next[d] = cur++;
        }
        else
            node = tree[node].next[d];
        i++;
    }
}

intl maxquery()
{
    int i = 0, node = 0;
    intl ans = 0;
    high = 0;
    while( str[i] )
    {
        int d = str[i] - '0';
        if( d == 0 )
        {
            if( tree[node].next[1] != -1 )
            {
                node = tree[node].next[1];
                ans += (1<<(31-i));
            }
            else
            {
                node = tree[node].next[0];
            }
        }
        else
        {
            if( tree[node].next[0] != -1 )
            {
                node = tree[node].next[0];
                ans += (1<<(31-i));
            }
            else
            {
                node = tree[node].next[1];
            }
        }
        i++;
    }
    return high=ans;
}

intl minquery()
{
    int i = 0, node = 0;
    intl ans = 0;
    while( str[i] )
    {
        int d = str[i] - '0';
        if( d == 0 )
        {
            if( tree[node].next[0] != -1 )
            {
                node = tree[node].next[0];
            }
            else
            {
                node = tree[node].next[1];
                ans += (1<<(31-i));
            }
        }
        else
        {
            if( tree[node].next[1] != -1 )
            {
                node = tree[node].next[1];
            }
            else
            {
                node = tree[node].next[0];
                ans += (1<<(31-i));
            }
        }
        i++;
    }
    return low = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n, mi, mx;
        init(0);
        cur = 1;
        scanf("%lld", &n);
        scanf("%lld", &ara[0]);
        for( int i = 1; i < n; i++ )
        {
            scanf("%lld", &ara[i]);
        }

        for( int i = 1; i < n; i++ )
            ara[i] = ara[i-1]^ara[i];
        nslice(0);
        mi = 10000000000000;
        mx = 0;
        //printf("%s\n", str);
        update();
        for( int i = 0; i < n; i++ )
        {
            nslice( ara[i] );
            //printf("%s\n", str);
            minquery();
            maxquery();
            update();
            mi = min(mi, low);
            mx = max( mx, high );
        }

        printf("Case %d: %lld %lld\n", caseno++, mx, mi);
    }

    return 0;
}



