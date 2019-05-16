#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAX ((ll)(1e18))
#define pi (2*acos(0))
#define mp make_pair
#define M ((ll)(998244353))
#define xx first
#define yy second
#define NN ((ll)(305))
#define N ((ll)(1e5 + 5))
#define pq priority_queue
///#define Q queue
#define eps 0
#define log 20
#define pb push_back
#define MOD 998244353


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long lu;


typedef tree < ll,  null_type,  less < ll >,  rb_tree_tag,  tree_order_statistics_node_update > o_set;

char s[N];

int main()
{
    ll x[3], y[3];
    for(int i = 0; i<2; i++) scanf("%lld %lld",&x[i],&y[i]);
    ll n;
    scanf("%lld",&n);
    scanf("%s",s);
    ll disy = 0, disx = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='D') disy--;
        if(s[i]=='U') disy++;
        if(s[i]=='L') disx--;
        if(s[i]=='R') disx++;
    }
    ll r = 20, l = 0;
    ll up = y[1]-y[0], lef = x[1]-x[0];
    while(l<r){
        ll m = (r+l)/2;
        ll keep = m;
        ll tmpup = (m/n)*disy, tmplef = (m/n)*disx;
        m = m%n;
        for(int i = 0; i<m; i++){
            if(s[i]=='D') tmpup--;
            if(s[i]=='U') tmpup++;
            if(s[i]=='L') tmplef--;
            if(s[i]=='R') tmplef++;
        }

        tmpup -= up;
        tmplef -= lef;
        tmpup = -tmpup;
        tmplef = -tmplef;
        if(abs(tmpup) + abs(tmplef)<=keep) r = keep;
        else{
            ///cout<<tmpup<<" "<<tmplef<<endl;
            l = keep+1;
        }
    }

    if(r==((ll)(1e18))) l = -1;

    printf("%lld\n",l);
    return 0;
}
