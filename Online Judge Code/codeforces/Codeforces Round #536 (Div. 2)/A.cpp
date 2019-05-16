#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s[1000];
    int n;
    cin >> n;
    int ans = 0;
    for( int i = 0; i < n; i++ ) cin >> s[i];
    for( int i = 1; i < n-1; i++ )
    {
        for( int j = 1; j < n-1; j++ )
        {
            if( s[i][j] == s[i+1][j-1] &&  s[i][j] == s[i+1][j+1] && s[i][j] == s[i-1][j-1] && s[i][j] == s[i-1][j+1] && s[i][j] == 'X' )
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

