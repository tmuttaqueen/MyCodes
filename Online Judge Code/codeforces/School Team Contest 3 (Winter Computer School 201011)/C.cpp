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

class comp
{
public:
    operator()( piii a, piii b )
    {
        if( a.yy == b.yy )
        {
           if( a.xx.xx == b.xx.xx )
           {
               return a.xx.yy > b.xx.yy;
           }
           return a.xx.xx > b.xx.xx;

        }
        return a.yy > b.yy;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int n;
    cin >> n;
    string s;
    cin >> s;
    //what_is(s);
    int used[n+1]= {}, ara[n+1];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    priority_queue< piii, vector<piii>, comp >pq;

    for( int i = 1; i < n; i++ )
    {
        if( (s[i] == 'B' && s[i-1] == 'G') || (s[i] == 'G' && s[i-1] == 'B') )
        {
            pq.push( mp( mp(i-1, i), abs(ara[i]-ara[i-1]) ) );
        }
    }
    vector<pii>ans;
        while( !pq.empty() )
        {
            piii x = pq.top();
            pq.pop();
            int l = x.xx.xx, r = x.xx.yy;
            if( used[l] == 0 && used[r] == 0 )
            {
                used[l] = used[r] = 1;
                ans.pb( mp(l,r) );
                l--;
                r++;
                if( l >= 0 && r < n && used[l] == 0 && used[r] == 0 && (s[l] == 'B' && s[r] == 'G') || (s[l] == 'G' && s[r] == 'B'))
                {
                    pq.push( mp( mp(l, r), abs(ara[r]-ara[l]) ) );
                }
            }
        }


    cout << ans.size() << endl;
    for( int i = 0; i < ans.size(); i++ )
    {
        cout << ans[i].xx+1 << " " << ans[i].yy+1 << endl;
    }


    return 0;
}




