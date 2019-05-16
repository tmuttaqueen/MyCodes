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
    set<string>ans;
    string s;
    cin >> s;
    if( s.size() <= 6 )
    {
        cout << 0 << endl;
        return 0;
    }
    s.erase( s.begin(), s.begin() + 5 );
    int len = s.size();
    what_is(s);
    //what_is(len);
    vector<int>flag(len+10, 0);
    flag[len] = 1;
    flag[len-1] = 0;
    for( int i = len-2; i>=0; i-- )
    {
        if( flag[i+2] == 1 )
        {
            int x = 1;
            string t1 = "";
            t1 += s[i];
            t1 += s[i+1];
            if( (i + 3) < len )
            {
                int k = 0;
                for( int j = 0; j < 2; j++ )
                {
                    if( s[i+2+j] == t1[j] ) k++;
                }
                if( k == 2 )
                    x = 0;
            }
            if( x )
            {
                ans.insert(t1);
                flag[i] = 1;
            }
        }
        if( flag[i+3] == 1 )
        {
            int x = 1;
            string t1 = "";
            t1 += s[i];
            t1 += s[i+1];
            t1 += s[i+2];
            if( (i + 5) < len )
            {
                int k = 0;
                for( int j = 0; j < 3; j++ )
                {
                    if( s[i+3+j] == t1[j] ) k++;
                }
                if( k == 3 )
                    x = 0;
            }
            if( x )
            {
                ans.insert(t1);
                flag[i] = 1;
            }
        }
        cout << i << " " << flag[i] << endl;
    }

    cout << ans.size() << endl;
    for( auto i = ans.begin(); i != ans.end(); i++ )
    {
        cout << *i << "\n";
    }
    return 0;
}


