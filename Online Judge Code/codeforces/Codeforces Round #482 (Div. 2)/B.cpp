#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
string s1, s2, s3;
intl cnt[140][3], mx[3], mxx[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, l;
    cin >> n;
    for( int i = 0; i < 3; i++ )
    {
        cin >> s1;
        l = s1.length();
        for( int j = 0; j < s1.length(); j++ )
        {
            cnt[ s1[j] ][i]++;
        }
        for( int j = 0; j < 126; j++ )
        {
            mxx[i] = max( mxx[i], cnt[j][i] );

        }
    }
    for( int i = 0; i < 3; i++ )
    {
        //mx[i] = max( mx[i], (n-l)%2==1?l-1:l );
        if( mxx[i] == l && n == 1 )
        {
            mx[i] = l-1;
            continue;
        }
        for( int j = 0; j < 126; j++ )
        {
            if( (j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z') )
            {
                if( cnt[j][i] + n <= l )
                {
                    mx[i] = max( mx[i], cnt[j][i] + n );
                }
                else
                {
                    mx[i] = l;
                    /*intl d = n - l + cnt[j][i];
                    if(d==1)
                    {
                        mx[i] = max( mx[i], l-1 );
                    }
                    else
                        mx[i] = l;*/
                }
            }

        }
        //cout << mx[i] << endl;

    }

    if( mx[0] > mx[1] && mx[0] > mx[2] )
    {
        cout << "Kuro" << endl;
    }
    else if( mx[1] > mx[0] && mx[1] > mx[2] )
    {
        cout << "Shiro" << endl;
    }
    else if( mx[2] > mx[0] && mx[2] > mx[1] )
        cout << "Katie" << endl;
    else
        cout << "Draw" << endl;
    return 0;
}
