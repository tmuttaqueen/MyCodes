#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int suffix_array[100005], pos[100005];

bool comp( pair<pii, int> a, pair<pii, int> b )
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
        pos[ ara[i].yy ] = i;
        cout << suffix_array[i] << " ";
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    string s;
    cin >> s;
    cin >> n;
    buildarray(s, suffix_array );

    return 0;
}




