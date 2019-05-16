#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a , b, c, d;
    cin >> a >> b >> c >> d;
    if( a != d )
    {
        cout << 0 << endl;
    }
    else if( a == d && a == 0 && c != 0 )
    {
        cout << 0 << endl;
    }
    else
        cout << 1 << endl;

    return 0;
}

