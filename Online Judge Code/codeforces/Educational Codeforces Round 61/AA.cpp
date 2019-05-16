#include<bits/stdc++.h>

using namespace std;

int n = 100000;
int d[100005], dd[100005];

void a()
{
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j <= n; j+= i )
            d[j]++;
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j <= n; j+= i )
            dd[j] += d[i];
    }
    int m = 10;
    for( int i =1; i <= n; i++ )
    {
        m = max( dd[i],  m);
    }



    cout << m << endl;

}



int main()
{
    a();
}
