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

string s;
const int MAXN = 200005;
int pos[MAXN], suffix_array[MAXN], lcp[MAXN];
int id[18][MAXN];
int N;
char str[MAXN];


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

int main()
{
    /*string s;
    cin >> s;
    buildArray(s, suffix_array);
    buildLcp(s, suffix_array);
    int len = s.length();
    for( int i = 0; i < len; i++ )
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
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(id, 0, sizeof id);
        int n;
        scanf("%d %s", &n, str );
        s = str;
        s = s+s;
        //what_is(s);
        buildArray(s, suffix_array );
        buildLcp(s, suffix_array );


    }
}
