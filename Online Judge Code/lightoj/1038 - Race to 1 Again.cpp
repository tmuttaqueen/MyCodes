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

const int mx = 1e5;

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    vector<int>vec[mx+5];
    for( int i = 1; i <= mx; i++ )
    {
        for( int j = i; j <= mx; j+=i  )
        {
            vec[j].pb(i);
        }
    }
    /*for( int i = 0 ; i < vec[77357].size(); i++ )
    {
        cout << vec[77357][i] << endl;
    }
    for( int i= 1; i < 77357; i++ )
    {
        if( 77357%i == 0  ) what_is(i);
    }*/
    vector<double>ans(mx+5);
    ans[1] = 0;
    for( int i = 2; i <= mx; i++ )
    {
        double temp = 1, ll = vec[i].size();
        //ll++;
        for( int j = 0; j < vec[i].size(); j++ )
        {
            temp += ans[vec[i][j]]/ll;
        }
        temp = temp*ll/(ll-1);
        ans[i] = temp;
    }
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        cout << "Case " << caseno++ << ": " << setprecision(6) << fixed << ans[a] << endl;
    }

    return 0;
}



