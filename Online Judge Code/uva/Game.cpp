#include<bits/stdc++.h>

using namespace std;

int ara[1234][1234];

int main()
{
    int n;
    while( cin >> n )
    {
        for( int i =1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                cin >> ara[i][j];
            }
        }
    }
}
