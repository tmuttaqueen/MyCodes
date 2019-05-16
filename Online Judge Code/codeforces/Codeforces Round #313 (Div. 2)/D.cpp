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
#define ldb        long double

string str;
int l1,l2, len;

bool comp( int s1, int e1, int s2, int e2 )
{
    while( s1 < e1 && s2 < e2 )
    {
        if( str[s1] != str[s2] )
            return 0;
        s1++;
        s2++;
    }
    return 1;
}

bool isequal( int s1, int e1, int s2, int e2 )
{
    if( (e1-s1)%2 == 1 && (e2-s2)%2==1 )
        return comp(s1, e1, s2, e2);
    int m1 = (s1+e1)/2, m2 = (s2+e2)/2;
    return ( (isequal(s1,m1,s2, m2) && isequal(m1, e1, m2, e2)) || (isequal(s1,m1,m2,e2) && isequal(m1, e1, s2, m2)) );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s1, s2;
    cin >> s1 >> s2;
    str = s1 + s2;
    len = str.size();
    bool ans = isequal( 0, len/2, len/2, len );
    if(ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}




