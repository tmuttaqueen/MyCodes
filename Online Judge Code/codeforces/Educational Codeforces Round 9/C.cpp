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
#define pii         pair<string, string>
#define piii        pair<pii, int>

bool comp( string a, string b )
{
    return a+b < b+a;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    vector<string>vec(n);
    for( int i = 0; i < n; i++ )
    {
        cin >> vec[i];
    }
    sort( vec.begin(), vec.end(), comp );
    for( int i = 0; i < n; i++ ) cout << vec[i];
    cout <<  endl;

    return 0;
}


