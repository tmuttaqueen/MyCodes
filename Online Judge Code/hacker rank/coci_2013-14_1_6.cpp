#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int suffix_array[100005], pos[100005];
vector<pii>rng[50005];
vector<pii>seq;
int tree[400000];
int result[100005];

void init( int cn, int s, int e )
{
    if( s == e )
    {
        tree[cn] = suffix_array[e-1];
        //cout << s << " " << tree[cn] << endl;
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1, e );
    tree[cn] = min( tree[cn*2], tree[cn*2+1] );
    return ;
}

int query( int cn, int s, int e, int x, int y )
{
    if( e < x || s > y )
        return 10000000;
    if( s >= x && e <= y )
        return tree[cn];
    int m = (s+e)/2;
    return min( query(cn*2, s, m, x, y), query( cn*2+1, m+1, e, x, y )  );
}


const int MAXN = 100005;
int id[18][MAXN];
int N;

struct cmp {
	int p;
	cmp(int _p) : p(_p) {}
	bool operator () (const int &a, const int &b) {
		if(id[p][a] != id[p][b]) return id[p][a] < id[p][b];
		if(p == 0) return 0;
		int na = a + (1 << p - 1), nb = b + (1 << p - 1);
		if(na >= N || nb >= N) return a > b;
		return id[p][na] < id[p][nb];
	}
};

void buildarray( string &s, int suffix_array[] )
{
	N = s.length();
	for(int i = 0; i < N; ++i)
		suffix_array[i] = i;

	for(int i = 0; i < N; ++i)
		id[0][i] = s[i] - '0';

	cmp C(0);

	sort(suffix_array, suffix_array + N, C);

	int curr = 0;

	for(int p = 1; p <= 17; ++p) {
		for(int i = 0; i < N; ++i) {
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


const int mx = 100005;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    string s;
    cin >> n;
    cin >> s;
    cin >> m;
    string str;
    buildarray(s, suffix_array );
    /*for( int i = 0; i < n; i++ )
    {
        cout << suffix_array[i] << " ";
        for( int j = suffix_array[i]; j < n; j++ )
        {
            cout << s[j];
        }
        cout << endl << endl;
    }*/
    init( 1, 1, n );

    for( int i = 0; i < m; i++ )
    {
        int ans;
        cin >> str;
        int left = 0, right = n-1;
        for( int j = 0; j < str.length(); j++ )
        {
            int h = right, l = left, cl, cr;
            ans = -1;
            while( h >= l )
            {
                int m = (h+l)/2;
                if( suffix_array[m] + j < n && s[ suffix_array[m] + j ] >= str[j] )
                {
                    if( s[ suffix_array[m] + j ] == str[j] )
                        ans = m;
                    h = m-1;
                }
                else
                    l = m+1;
            }
            //what_is(ans);
            if( ans != -1 ) cl = ans;
            else cl = n-1;
            h = right;
            l = left;
            ans = -1;
            while( h >= l )
            {
                int m = (h+l)/2;
                if( suffix_array[m] + j > n || s[ suffix_array[m] + j ] <= str[j] )
                {
                    if( s[ suffix_array[m] + j ] == str[j] )
                        ans = m;
                    l = m+1;
                }
                else
                    h = m-1;
            }
            //what_is(ans);
            if( ans != -1 ) cr = ans;
            else cr = n-1;
            if( ans == -1) //cl == cr && cl == n-1 )
            {
                cl = n-1;
                cr = n-2;
            }
            left = cl;
            right = cr;
            rng[i].pb( mp(cl, cr) );
            //cout << " " << cl << " " << cr << endl;
            //cout << cr - cl + 1 << endl;
        }
        if( ans != -1 )
            left = query( 1, 1, n, left+1, right+1 );
        //cout << left << " " << i << endl;
        seq.pb( mp(left, i) );
        //what_is(left);
    }

    sort( seq.begin(), seq.end() );
    int st = 0;
    for( int i = 0; i < seq.size(); i++ )
    {
        intl ans = 0;
        int ind = seq[i].yy;
        int p = seq[i].xx;
        //what_is(ind);

        if(p==n-1) p++;
        ans += p;
        //what_is(p);
        while( st < n && st <= p )
        {
            //cout << " " << pos[st] + 1 << endl;
            update( pos[st]+1, 1);
            st++;
        }
        //what_is(ind);
        for( int j = 0; j < rng[ind].size(); j++ )
        {
            //cout << rng[ind][j].xx << " " << rng[ind][j].yy << endl;
            ans += query( rng[ind][j].yy + 1 ) - query( rng[ind][j].xx );
        }
        result[ind] = ans;
    }

    for( int i = 0; i < m; i++ )
    {
        cout << result[i] << endl;
    }
    //while(1);
    //getchar();
    //cin >> n ;
    return 0;
}





