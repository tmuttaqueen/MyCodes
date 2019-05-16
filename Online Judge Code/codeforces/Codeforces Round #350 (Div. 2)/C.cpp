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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n;
    map<int, int>mm;
    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        mm[a]++;
    }
    cin >> m;
    int ans = 1, s1 = 0, s2 = 0;
    pii ara[m+1];
    for( int i = 1; i <= m; i++ )
    {
        cin >> ara[i].xx;
    }
    for( int i = 1; i <= m; i++ )
    {
        cin >> ara[i].yy;
    }
    for( int i = 1; i <= m; i++ )
    {
        int n1 = mm[ara[i].xx];
        int n2 = mm[ara[i].yy];
        //what_is(n1);
        //what_is(n2);
        if( n1 > s1 )
        {
            ans = i;
            s1 = n1;
            s2 = n2;
        }
        else if( n1 == s1 )
        {
            if( n2 > s2 )
            {
                ans = i;
                s1 = n1;
                s2 = n2;
            }
        }
    }
    cout << ans << endl;
    return 0;

}


