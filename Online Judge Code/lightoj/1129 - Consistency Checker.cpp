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
    int next[10];
};

trie tr[500000];
int node = 1;
vector<string>vec(10001*2);

void init( )
{
    for( int i = 0; i < 500000; i++ )
    {
        tr[i].d = 0;
        memset( tr[i].next, -1, sizeof( tr[i].next ) );
    }
    return;
}

void push( string &s )
{
    int cn = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        int id = s[i] - '0';
        if( tr[cn].next[id] == -1 )
        {
            tr[cn].next[id] = node;
            node++;
        }
        cn = tr[cn].next[id];
        tr[cn].d++;
    }
    return;
}

bool isprefix( string &s )
{
    int cn = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        int id = s[i] - '0';
        cn = tr[cn].next[id];
    }
    if( tr[cn].d > 1 )
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, ans = 0, node = 1;
        init();
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> vec[i];
            push(vec[i]);
        }
        for( int i = 0; i < n && ans == 0; i++ )
        {
            if( isprefix(vec[i]) )
            {
                //what_is(i);
                ans = 1;
            }
        }
        if(!ans)
            cout << "Case " << caseno++ << ": YES\n";
        else
            cout << "Case " << caseno++ << ": NO\n";
    }

    return 0;
}



