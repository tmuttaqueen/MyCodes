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

struct node
{
    bool flag;
    int next[10];
};

int ans, head, num = 1;
node trie[100005];

void init( )
{
    for( int i = 0; i < 100005; i++ )
    {
        trie[i].flag = 0;
        for( int j = 0; j < 10; j++ )
            trie[i].next[j] = -1;
    }
}

void update( char str[] )
{
    int cn = 0, i = 0;
    while( str[i++] )
    {
        int id = str[i-1] - '0';
        if( trie[cn].next[id] == -1 )
            trie[cn].next[id] = num++;
        cn = trie[cn].next[id];
        if( trie[cn].flag )
            ans = 0;
    }
    trie[cn].flag = 1;
    for(i = 0; i < 10; i++ )
        if( trie[cn].next[i] != -1 )
            ans = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        ans = 1;
        num = 1;
        init();
        //debug;
        scanf("%d\n", &n);
        while(n--)
        {
            char str[12];
            gets(str);
            if( ans )
                update(str);
        }
        if(ans)
            printf("Case %d: YES\n", caseno++);
        else
            printf("Case %d: NO\n", caseno++);
    }

    return 0;
}



