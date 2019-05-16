/*
    -------------------------------> SUFFIX ARRAY + LONGEST COMMON PREFIX (LCP) <-------------------------------------------
    suffix array in O(nlogn)
    lcp from suffix_array via kasai algo in O(n)
*/

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


const int MAXN = 100005;
int pos[MAXN], suffix_array[MAXN], lcp[MAXN];
int id[18][MAXN];
int N;
pii arr[111111];
int tree[444444];

//suffix started at suffix_array[i] has rank i
//pos[i] is the position of i'th suffix
//lcp[i] is the common subtring lenth of suffix_array[i] and suffix_array[i+1]

struct cmp
{
    int p;
    cmp(int _p) : p(_p) {}
    bool operator () (const int &a, const int &b)
    {
        if(id[p][a] != id[p][b]) return id[p][a] < id[p][b];
        if(p == 0) return 0;
        int na = a + (1 << p - 1), nb = b + (1 << p - 1);
        if(na >= N || nb >= N) return a > b;
        return id[p][na] < id[p][nb];
    }
};

void buildArray( string &s, int suffix_array[] )
{
    N = s.length();
    for(int i = 0; i < N; ++i)
        suffix_array[i] = i;

    for(int i = 0; i < N; ++i)
        id[0][i] = s[i] - '0';

    cmp C(0);

    sort(suffix_array, suffix_array + N, C);

    int curr = 0;

    for(int p = 1; p <= 17; ++p)
    {
        for(int i = 0; i < N; ++i)
        {
            if(i != 0 && C(suffix_array[i - 1], suffix_array[i])) ++curr;
            id[p][suffix_array[i]] = curr;
        }
        C.p = p;
        sort(suffix_array, suffix_array + N, C);
    }
    /*for( int i = 0; i < len; i++ )
    {
        cout << suffix_array[i] << " ";
    }*/
    for(int i = 0; i < N; ++i) pos[suffix_array[i]] = i;
}

void buildLcp( string &s, int suffix_array[] )
{
    int len = s.size();
    //declare lcp array
    //int lcp[len];
    lcp[len-1] = 0;
    int temp[len];
    for( int i = 0; i < len; i++ )
        temp[suffix_array[i]] = i;
    int k = 0;
    for( int i = 0; i < len; i++ )
    {
        int cur = temp[i];
        if( cur == len-1 )
        {
            k = 0;
            continue;
        }
        int next = suffix_array[cur+1];
        while( i+k < len && next + k < len && s[i+k] == s[next+k] )
            k++;
        lcp[cur] = k;
        if( k > 0 )
            k--;
    }
    //show lcp array
    //for( int i = 0; i < len; i++ ) cout << lcp[i] << " ";
    //cout << endl;
}

void init( int cn, int s, int e )
{
    if( s == e )
    {
        tree[cn] = lcp[s-1];
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init(cn*2+1, m+1, e);
    tree[cn] = min( tree[cn*2], tree[cn*2+1] );
    return ;
}

int query( int cn, int s, int e, int x, int y )
{
    if( s >= x && e <= y )
        return tree[cn];
    if( y < s || x > e )
        return 10000000;
    int m = (s+e)/2;
    int a = query( cn*2, s, m, x, y );
    int b = query( cn*2+1, m+1, e, x, y );
    return min(a,b);
}


int main()
{
    string s;
    cin >> s;
    buildArray(s, suffix_array);
    buildLcp(s, suffix_array);
    int len = s.length();
    /*for( int i = 0; i < len; i++ )
    {
        cout << suffix_array[i] << " ";
    }
    cout << "\n pos \n";
    for( int i = 0; i < len; i++ )
    {
        cout << pos[i] << " ";
    }
    cout << "\n lcp \n";
    for( int i = 0; i < len; i++ )
    {
        cout << lcp[i] << " ";
    }*/
    init(1,1,len);
    int c = 0;
    for( int i = 0; i < len ; i++ )
    {
        int x = pos[0], y = pos[len-1-i];
        if( x == y )
        {
            arr[c++] = mp(len,1);
            continue;
        }
        int mn = query( 1,1,len, min(x,y)+1, max(x,y) );
        if( mn >= i+1 )
        {
            int l = y, h = len-1, ans = y;
            while( l <= h )
            {
                int m = (l+h)/2;
                int q = query( 1,1,len, l+1, m+1 );
                if( q >= i+1 )
                {
                    l = m+1;
                }
                else
                {
                    h = m-1;
                    ans = m;
                }
            }
            arr[c++] = mp(  i+1, ans-y+1 );
        }

    }

    cout << c << endl;
    for( int i = 0; i < c; i++ )
    {
        cout << arr[i].xx << " " << arr[i].yy << endl;
    }
    return 0;

}












