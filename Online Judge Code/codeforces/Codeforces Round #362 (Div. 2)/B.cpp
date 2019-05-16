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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb         long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int a,b, d, l, c = 0, in = 0;
    string s;
    char ans[100000];
    cin >> s;
    for( int i = 0; i < s.size(); i++ )
    {
        if( s[i] == 'e' )
        {
            l = i+1;
            break;
        }
        ans[in++] = s[i];
    }

    char str[10];
    for( int i = l; i < s.size(); i++ )
    {
        str[c++] = s[i];
    }
    str[c] = '\0';
    int p = atoi(str);
    l = in;
    for( int i = 1; i <= p; i++ )
    {
        if( i >= l-1 )
        {
            ans[in++] = '0';
        }
        else
        {
            ans[i] = ans[i+1];
            ans[i+1] = '.';
            if( i == l-2 )
                in--;
        }
    }
    int i = 0;
    while( ans[i] == '0' && i < in )
    {
        i++;
    }
    if( ans[i] == '.' && ans[i-1] == '0' )
        i--;
    if( ans[in-1] == '0' && ans[in-2] =='.' )
        in-=2;
    for( ; i < in; i++ )
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
