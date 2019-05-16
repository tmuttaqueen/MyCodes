#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a = 10, b = 5;
    a = a^b;
    b = a^b;
    a = a^b;
    printf("%d %d\n", a, b);
    return 0;
}
