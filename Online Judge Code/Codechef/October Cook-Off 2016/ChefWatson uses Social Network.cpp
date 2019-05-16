#include <bits/stdc++.h>

using namespace std;

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

int special[100005];

vector< pair< pair<int, int>, string > >vec(1005);

bool comp( pair< pair<int, int>, string > &a, pair< pair<int, int>, string > &b )
{
    if( special[a.xx.xx] == special[b.xx.xx] )
    {
        return a.xx.yy > b.xx.yy;
    }

    else if( special[a.xx.xx] == 1 && special[b.xx.xx] == 0 )
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, a;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        cin >> a ;
        special[a] = 1;
    }

    for( int i = 0; i < m; i++ )
    {
        cin >> vec[i].xx.xx >> vec[i].xx.yy >> vec[i].yy;
    }
    sort( vec.begin(), vec.begin() + m, comp );
    for( int i = 0; i < m; i++ )
    {
        cout << vec[i].yy << endl;
    }
    return 0;
}




