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
    int d;
    int next[26];
};

trie tr[21*100000];
int node = 1;

void init(int cn)
{
    tr[cn].d = 0;
    memset( tr[cn].next, -1, sizeof( tr[cn].next ) );
    return;
}

void push( char s[] )
{
    int cn = 0, l = strlen(s);
    for( int i = 0; i < l; i++ )
    {
        int id = s[i] - 'a';
        if( tr[cn].next[id] == -1 )
        {
            cn = tr[cn].next[id] = node++;
            init(cn);
        }
        else
        {
            cn = tr[cn].next[id];
        }
        tr[cn].d++;
    }
}

int word( char s[] )
{
    int cn = 0, l = strlen(s);
    for( int i = 0; i < l; i++ )
    {
        int id = s[i] - 'a';
        if( tr[cn].next[id] == -1 )
        {
            return 0;
        }
        cn = tr[cn].next[id];
    }
    return tr[cn].d;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    init(0);
    int n;
    scanf("%d\n", &n);
    for( int i = 0; i < n; i++ )
    {
        char s1[10], s2[30];
        scanf("%s %s", s1, s2);
        if( strcmp( s1, "add" ) == 0 )
        {
            push(s2);
        }
        else
        {
            int ans = word(s2);
            printf("%d\n", ans);
        }
    }
    return 0;
}



