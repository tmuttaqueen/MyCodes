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
    bool word;
    int d;
    int next[52];
};

trie tr[100010];
int node;

void init( int cn )
{
    tr[cn].word = false;
    tr[cn].d = 0;
    memset( tr[cn].next, -1, sizeof( tr[cn].next ) );
    return;
}

void insertt( char s[] )
{
    int cn = 0;
    int l = strlen(s);
    for( int i = 0; i < l; i++ )
    {
        int id = (s[i] >= 'a')? 26 + s[i] - 'a': s[i] - 'A';
        if( tr[cn].next[id] == -1 )
        {
            cn = tr[cn].next[id] = node++;
            init(cn);
        }
        else
            cn = tr[cn].next[id];
    }
    tr[cn].word = true;
    tr[cn].d++;
    return;
}

int query( const string &s )
{
    int cn = 0;
    int l = s.size();
    for( int i = 0; i < l; i++ )
    {
        int id = (s[i] >= 'a')? 26 + s[i] - 'a': s[i] - 'A';
        if( tr[cn].next[id] == -1 )
            return 0;
        cn = tr[cn].next[id];
    }
    if( tr[cn].word == true )
        return tr[cn].d;
    else
        return 0;
}


int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    scanf("%d", &t);

    while(t--)
    {
        int n, m;
        node = 1;
        char s[105];
        scanf("%d\n", &n);
        init(0);


        for( int i = 0; i < n; i++ )
        {
            gets(s);
            int l = strlen(s);
            if( l > 2 )
                sort( s + 1, s + l - 1 );
            //debug;
            insertt(s);
        }

        scanf("%d\n", &m);
        cout << "Case " << caseno++ << ":\n";
        for( int i = 0; i < m; i++ )
        {
            char s[10005];
            long long ans = 1, d;
            gets(s);
            //puts(s);
            vector<string>vec;
            int l = strlen(s);
            string temp = "";
            for( int i = 0; i < l; i++ )
            {
                if( i > 0 && s[i] >= 'A' && s[i-1] == ' ' && temp != "" )
                {
                    if( temp.size() > 2 )
                        sort( temp.begin() + 1, temp.end() - 1 );
                    //what_is(i);
                    //what_is(temp);
                    vec.pb(temp);
                    temp = s[i];
                }
                else if( s[i] >= 'A' )
                {
                    temp += s[i];
                }
                //what_is(temp);
            }
            if( temp != "" )
            {
                if( temp.size() > 2 )
                    sort( temp.begin() + 1, temp.end() - 1 );
                vec.pb(temp);
            }
            for( int i = 0; i < vec.size(); i++ )
            {
                //cout << vec[i] << endl;
                /*if( s.size() > 2 )
                    sort( s.begin() + 1, s.end() - 1 );*/
                d = query(vec[i]);
                //what_is(d);
                ans *= d;
            }
            cout << ans << "\n";
        }
    }

    return 0;
}



