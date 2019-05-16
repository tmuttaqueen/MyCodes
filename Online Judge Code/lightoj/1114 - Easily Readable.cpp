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

const int mx = 100005;
struct node
{
    int x;
    int next[52];
};

node tree[mx];
int cur;
char ch[110];
char sen[10005];
char temp[10005];

void init( int n )
{
    tree[n].x = 0;
    for( int i = 0; i < 52; i++ )
        tree[n].next[i] = -1;
}

int index( char c )
{
    int ans;
    if( c >= 'a' && c <= 'z' )
        ans = 26 + c - 'a';
    else
        ans = c - 'A';
    return ans;
}

void add( char str[] )
{
    int i = 0, cn = 0;
    while(str[i])
    {
        int d = index(str[i]);
        if( tree[cn].next[d] == -1 )
        {
            init(cur);
            cn = tree[cn].next[d] = cur++;
        }
        else
        {
            cn = tree[cn].next[d];
        }
        i++;
    }
    tree[cn].x++;
}

int query( char str[] )
{
    int i = 0, cn = 0;
    while(str[i])
    {
        int d = index(str[i]);
        if( tree[cn].next[d] == -1 )
        {
            return 0;
        }
        else
        {
            cn = tree[cn].next[d];
        }
        i++;
    }
    //what_is(tree[cn].x);
    return tree[cn].x;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int q, m;
        cur = 0;
        init(cur++);
        scanf("%d\n", &q);
        while(q--)
        {
            gets(ch);
            int len = strlen(ch);
            if( len > 3 )
                sort( ch + 1, ch + len - 1 );
            //puts(ch);
            add(ch);
        }
        scanf("%d\n", &m);
        printf("Case %d:\n", caseno++);
        long long ans, ff;
        while(m--)
        {
            ans = 1;
            gets(sen);
            int i = 0, j = 0;
            while( sen[i] == ' ' )
            {
                i++;
            }
            temp[j++] = sen[i++];
            for( ; sen[i]; i++ )
            {
                if( sen[i-1] == ' ' && ( (sen[i] >= 'a' && sen[i] <= 'z') || (sen[i] >= 'A' && sen[i] <= 'Z') )  )
                {
                    temp[j] = '\0';
                    if( j > 3 )
                        sort( temp+1, temp+j-1 );
                    //what_is(j);
                    //puts(temp);
                    ff = query(temp);
                    ans *=ff;
                    j = 0;
                }
                if( (sen[i] >= 'a' && sen[i] <= 'z') || (sen[i] >= 'A' && sen[i] <= 'Z')  )
                    temp[j++] = sen[i];
            }
            if( j != 0 )
            {
                temp[j] = '\0';
                if( j > 3 )
                    sort( temp+1, temp+j-1 );
                //puts(temp);
                ff = query(temp);
                ans *=ff;
                j = 0;
            }

            printf("%lld\n", ans);
        }
    }

    return 0;
}



