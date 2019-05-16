#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int isvo( char c )
{
    if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    if( s.length() != t.length() )
    {
        cout << "No" << endl;
        return 0;
    }
    for( int i = 0; i < s.length(); i++ )
    {
        if( isvo( s[i] ) != isvo( t[i] ) )
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

