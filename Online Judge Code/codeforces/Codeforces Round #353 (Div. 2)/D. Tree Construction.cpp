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

struct data
{
    int l, r;
};

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, a;
    cin >> n;
    data vis[n+1];
    for( int i = 0; i < n; i++ )
        vis[i].l = vis[i].r = 1;
    int ara[n+1];
    int ans[n+1];
    set<int>ss;
    map<int, int>mm;
    cin >> a;
    ara[0] = a;
    ss.insert(a);
    mm[a] = 0;
    int l, r;
    for( int i = 1; i < n; i++ )
    {
        l = r = -1;
        cin >> a;
        ara[i] = a;
        mm[a] = i;
        ss.insert(a);
        auto it = ss.find(a);
        if( it != ss.begin() )
        {
            it--;
            l = mm[*it];
            //cout << '1' << ' ' << *it << endl;
            it++;
        }
        if( it != ss.end() )
        {
            it++;
            r = mm[*it];
            //cout << "2 " << *it << endl;
        }
        //what_is(l);
        //what_is(r);
        //debug;
        if( l != -1 && vis[l].r == 1 )
        {
            ans[i] = ara[l];
            vis[l].r = 0;
        }
        else
        {
            ans[i] = ara[r];
            vis[r].l = 0;
        }
    }

    for( int i = 1; i < n; i++ )
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}



