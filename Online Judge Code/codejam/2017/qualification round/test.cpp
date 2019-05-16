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

/*bool comp( pair<pii, int> a, pair<pii, int> b )
{
    if( a.xx.xx == b.xx.xx )
        return a.xx.yy < b.xx.yy;
    else
        return a.xx.xx < b.xx.xx;
}

void buildarray( string &s, int suffix_array[] )
{
    int len = s.size();
    int temp[20][len];
    for( int i = 0; i < len; i++ )
        temp[0][i] = s[i] - 'a';
    pair<pii, int> ara[len];
    for( int i = 0, j = 1; j < len; i++, j*=2 )
    {
        for( int c = 0; c < len ; c++ )
        {
            ara[c].xx.xx = temp[i][c];
            ara[c].xx.yy = (c+j < len)? temp[i][c+j]: -1;
            ara[c].yy = c;
        }
        sort( ara, ara+len, comp );
        int r = 0;
        temp[i+1][ara[0].yy] = r;
        for( int c = 1; c < len; c++ )
        {
            if( ara[c].xx.xx != ara[c-1].xx.xx || ara[c].xx.yy != ara[c-1].xx.yy )
                r++;
            temp[i+1][ara[c].yy] = r;
        }
    }
    //get suffix array from 'ara' and show suffix array
    for( int i = 0; i < len; i++ )
    {
        suffix_array[i] = ara[i].yy;
        //cout << suffix_array[i] << " ";
    }
}*/

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

	//for(int i = 0; i < N; ++i) pos[suffix_array[i]] = i;
}


void buildlcp( string &s, int suffix_array[] )
{
    int len = s.size();
    int lcp[len];
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
    for( int i = 0; i < len; i++ ) cout << lcp[i] << " ";
    cout << endl;
}


int main()
{
    string s = "1111";
    int suffix_array[100];
    buildarray( s, suffix_array );

    for( int i = 0; i < s.length(); i++ )
    {
        int ind = suffix_array[i];
        cout << i << " " << ind << " ";
        for( int j = ind; j < s.length(); j++ )
        {
            cout << s[j];
        }
        cout << endl;
    }

    return 0;
}






