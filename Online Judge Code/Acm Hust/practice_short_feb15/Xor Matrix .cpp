#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        for( int i = l; i <= r; i++ )
        {
            for( int j = l; j <= r; j++ )
            {
                cout << (i^j) << " ";
            }
            cout << endl;
        }
        cout << "new" << endl;
    }

    return 0;
}
