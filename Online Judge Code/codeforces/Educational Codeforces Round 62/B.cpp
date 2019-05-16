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
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        int l = 0, r = s.length() - 1;
        for( int i = 0; i < s.length(); i++ )
        {
            if( s[i] == '>' )
            {
                l = i;
                break;
            }
        }

        for( int i = s.length() - 1; i >= 0 ; i-- )
        {
            if( s[i] == '<' )
            {
                r = i;
                break;
            }
        }

        int ans = min(l, (int)s.length()-1 - r);
        cout << ans << endl;
    }

    return 0;
}
