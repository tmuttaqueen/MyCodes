#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pss pair<intl,string>
#define mp make_pair
#define xx first
#define yy second

struct data
{
    string name;
    intl vis;
    intl val;
    bool operator<( const data &a )
    {
        if( a.vis == vis )
        {
            return val>a.val;
        }
        return vis < a.vis;
    }
};

data ara[100];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("tourist.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n, k, v;
        cin >>  n >> k >> v;
        intl d = (v-1)*k/n, r = (v-1)*k%n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i].name;
            ara[i].val = n - i;
            ara[i].vis = d;
            if( i < r ) ara[i].vis++;
        }
        sort( ara, ara+n );

        vector<pss>ans;
        for( int i = 0; i < k; i++ )
        {
            ans.push_back( mp( ara[i].val, ara[i].name ) );
        }
        sort( ans.begin(), ans.end() );
        cout << "Case #" << caseno++ << ": ";
        for( int i = k-1; i >= 0; i-- )
        {
            cout << ans[i].yy << " ";
        }
        cout << endl;
    }

    return 0;
}
