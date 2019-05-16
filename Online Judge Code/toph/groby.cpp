#include<bits/stdc++.h>

using namespace std;

int ara[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> ara[0] >> ara[1];
        ara[2] = 360 - ara[0] - ara[1];
        ara[0] = 180 - ara[0];
        ara[1] = 180 - ara[1];
        ara[2] = 180 - ara[2];
        sort( ara, ara+3 );
        cout << ara[0] << " " << ara[1] << " " << ara[2] << endl;
    }

    return 0;
}
