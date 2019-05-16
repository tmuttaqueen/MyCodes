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
    int n;
    cin >> n;
    int two = 0, one = 0;

    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        if(a==2) two++;
        else one++;
    }

    if( one == 0 || two == 0 )
    {
        int x = 2;
        if( two == 0 ) x = 1;
        for( int i = 0; i < n; i++ ) cout << x << " ";
    }
    else
    {
        cout << "2 1 ";
        one--;
        two--;
        while(two)
        {
            cout << "2 ";
            two--;
        }
        while(one)
        {
            cout << "1 ";
            one--;
        }
    }

    cout << endl;

    return 0;
}
