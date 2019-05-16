#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, a, b;
    cin >> n >> p;
    double ara[n], s = 0;
    for( int i = 0; i < n; i++ )
    {
        scanf("%d %d", &a, &b);
        ara[i] = b/p - (a-1)/p;
        ara[i] = ara[i]/(double)(b-a+1);
        //cout << ara[i] << endl;
    }
    double x = ara[0];
    for( int i = 0; i < (n-1); i++ )
    {
        ara[i] = ara[i] + ara[i+1] - ara[i]*ara[i+1];
        //cout << ara[i] << endl;
        s += 2000*ara[i];
    }
    ara[n-1] = ara[n-1] + x - ara[n-1]*x;
   //cout << ara[n-1] << endl;
    s += 2000*ara[n-1];
    printf("%.8lf\n", s);
    return 0;
}
