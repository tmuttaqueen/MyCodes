#include <bits/stdc++.h>
#define inf 1000000000000000ll
#define ll long long int
#define M_PIl 3.141592653589793238462643383279502884L
using namespace std;
//string s = ".";
ifstream cinn(".in");
//ofstream g(s+"out");

set<pair<ll,ll> > s;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    ll maxi=0;
    cin>>n;
    s.insert({0,0});
    ll a,b,c;
    while(n--)
    {
        cin>>a>>b;
        a=a*a*b;

        auto it=s.lower_bound({a,0});
        --it;
        c=a+it->second;

        if (maxi<a+it->second)
            maxi=a+it->second;

        s.insert({a,a+it->second});
        it=s.lower_bound({a,0});++it;
        while(it!=s.end()&&it->second<c)
            s.erase(it++);
    }
    cout<<fixed<<setprecision(16)<<1.0*maxi*M_PIl;
    return 0;
}
