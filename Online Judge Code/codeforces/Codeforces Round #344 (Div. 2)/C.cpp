#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x) cout << #x << " is " << x << " "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define lldb        long double



struct data
{
    int ind, type, to;
};

bool comp( int a, int b )
{
    return a>b;
}
bool cmp( data a, data b )
{
    return a.to < b.to;
}

int ara[200005];
data vec[200005];
int vis[200005];
int temp[200005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, q;
    cin >> n >> q;

    for( int i = 0; i < n; i++ ) cin >> ara[i];
    for( int i = 0; i < q; i++ )
    {
        cin >> vec[i].type >> vec[i].to;
        vec[i].ind = i;
    }
    memset( vis, 0, sizeof(vis) );

    sort( vec, vec+q, cmp );
    int mx = vec[q-1].ind;
    for( int i = q-2; i >= 0; i-- )
    {
        if( mx >= vec[i].ind )
            vis[i] = 1;
        mx = max( mx, vec[i].ind );
    }
    vector<int>to, type;
    int l = 0;
    for( int i = q-1; i >= 0; i-- )
    {
        if(!vis[i])
        {
            to.pb( vec[i].to );
            type.pb(vec[i].type);
            //cout << to[l] << " " << type[l] << endl;
            l++;
        }
    }
    to.pb(0);
    type.pb(1);
    l++;
    int len = to[0];
    for( int i = 0; i < len; i++ )
    {
        temp[i] = ara[i];
    }
    sort( temp, temp + len );
    int left = 0, right = len-1, rr = len-1;
    for( int i = 0; i < l-1; i++ )
    {
        int num = to[i] - to[i+1];
        if( type[i] == 1 )
        {
            for( int j = 0; j < num; j++ )
            {
                ara[rr--] = temp[right--];
            }
        }
        else
        {
            for( int j = 0; j < num; j++ )
            {
                ara[rr--] = temp[left++];
            }
        }
    }

    for( int i = 0; i < n; i++ ) cout << ara[i] << " ";
    cout << endl;
    return 0;
}



