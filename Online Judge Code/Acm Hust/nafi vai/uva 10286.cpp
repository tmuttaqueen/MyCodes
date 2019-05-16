#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a;
    const double PI = acos(-1.0);
    double b = sin( 108.0*PI/180.0 )/ sin( 63.0*PI/180.0 );
    while( scanf("%lf", &a)== 1 )
    {
        double x = a*b;
        printf("%.10f\n", x);
    }


    return 0;
}
