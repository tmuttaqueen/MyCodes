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
string s1, s2;

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

void buildArray( string &s )
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

void buildLcp( string &s )
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

intl h1 = 29, h2 = 37, mod1 = 1e9+7, mod2 = 1e9+9, a1[54321], a2[54321];
vector<int>vec;

int main()
{
    int t, caseno = 1;
    cin >> t;
    intl x1 = 1, x2 = 1;
    for( int i = 0; i <= 50005; i++ )
    {
        a1[i] = x1;
        a2[i] = x2;
        x1 = (x1*h1)%mod1;
        x2 = (x2*h2)%mod2;
    }
    while(t--)
    {
        cin >> s1;
        cin >> s2;
        vec.clear();
        intl v1 = 0, v2 = 0;
        for( int i = 0; i < s2.length(); i++ )
        {
            v1 = (v1+ s2[i]*a1[i] )%mod1;
            v2 = (v2+ s2[i]*a2[i] )%mod2;
        }
        int l = s1.length(), x1 = 0, x2 = 0, c = 0;
        for( int i = l-1; i >= 0; i--)
        {
            x1 = ( x1*h1 + s1[i] )%mod1;
            x2 = ( x2*h2 + s1[i] )%mod2;
            if( l - i > s2.length() )
            {
                x1 = (( x1 - s1[ i+ s2.length()]*a1[ s2.length() ] )%mod1 + mod1)%mod1;
                x2 = (( x2 - s1[ i+ s2.length()]*a2[ s2.length() ] )%mod2 + mod2)%mod2;
            }
            if( l - i >= s2.length() )
            {
                if( x1 == v1 && x2 == v2 )
                {
                    vec.pb( i );
                }
            }
        }
        reverse( vec.begin(), vec.end() );
        //for( int x: vec) cout << x << endl;
        buildArray(s1);
        buildLcp(s1);
        intl ans = 0;
        for( int i = 0; i < s1.length(); i++ )
        {
            //cout << suffix_array[i] << " " << lcp[i] << endl;
            int x = lower_bound( vec.begin(), vec.end(), suffix_array[i] ) - vec.begin();
            if( x == vec.size() )
            {
                x = s1.length();
            }
            else
            {
                x = vec[x] + s2.length() - 1;
            }
            //what_is(x);
            ans += max( 0, x - suffix_array[i] - lcp[i] );
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
}
