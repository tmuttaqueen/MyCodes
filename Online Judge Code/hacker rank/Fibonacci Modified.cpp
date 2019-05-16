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

string addition( string &a, string &b )
{
    int rem = 0;
    string ans;
    int i = 0, mxlen = max( a.size(), b.size() );
    for( int i = 0; i < mxlen; i++ )
    {
        int c1 = (i<a.size())?a[i]-'0':0;
        int c2 = (i<b.size())?b[i]-'0':0;
        int x = c1+c2+rem;
        rem = x/10;
        x %= 10;
        char c = '0'+x;
        ans+=c;
    }
    char c = rem + '0';
    ans+=c;
    return ans;

}

string multiply( string a, string b)
{
    string ans;
    ans.insert(ans.begin(), 1000, '0');
    for( int i = 0; i < b.size(); i++ )
    {
        string temp;
        temp.insert( temp.begin(), i, '0' );
        int rem = 0;
        for( int j = 0; j < a.size(); j++ )
        {
            int x = ( a[j] - '0' )*( b[i] - '0' );
            x += rem;
            rem = x/10;
            x %=10;
            char c = '0'+x;
            temp += c;
        }
        char c = rem + '0';
        temp += c;
        ans = addition( ans, temp);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl a, b, t;
    vector<string>ara(30);
    cin >> ara[1] >> ara[2] >> t;
    for( int i = 3; i <= t; i++ )
    {
        ara[i] = multiply( ara[i-1], ara[i-1] );
        ara[i] = addition( ara[i], ara[i-2] );
    }
    int c = ara[t].size()-1;
    while( c >= 0 )
    {
        if( ara[t][c] != '0' )
            break;
        c--;
    }
    for( int i = c; i >= 0; i-- )
    {
        cout << ara[t][i];
    }
    cout << endl;
    return 0;
}



