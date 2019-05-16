#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long s, a ,b, c, ans = 0;
        cin >> s >> a >> b >> c;
        long long bar = s/c;
        ans += bar;
        ans += (bar/a)*b;
        cout << ans << endl;
    }
    return 0;
}
