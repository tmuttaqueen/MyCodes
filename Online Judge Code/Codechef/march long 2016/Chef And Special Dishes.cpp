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
    int t;
    cin >> t;
    while(t--)
    {
        bool x = 1;
        string ss;
        cin >> ss;
        int len = ss.size(), l = len/2;
        if( len  == 1 )
        {
            cout << "NO\n";
            continue;
        }

        if(len%2==0 )
        {
            for( int i = 0, j = l; i < l; i++, j++ )
            {
                if( ss[i] != ss[j] )
                {
                    x = 0;
                    break;
                }
            }
        }
        else
        {
            bool a = 1, b = 1;
            int c = 0;
            for( int i = 0, j = l+1; i <= l; i++, j++)
            {
                if( ss[i] == ss[j] )
                    c++;
                else
                    j--;
            }
            if( c != l )
                a = 0;

            c = 0;
            for( int i = 0, j = l; j < len; i++, j++)
            {
                if( ss[i] == ss[j] )
                    c++;
                else
                    i--;
            }
            if( c != l )
                b = 0;
            x = a|b;
        }

        if( x )
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}



