#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl sum(intl n) {
	return n ? sum(n-1) + n: 0LL;
}

int main()
{
    intl a =  10000, d;
    //cout << sum(a) << endl;
    for( int i = 0; i < 1000000; i++ )
    {
        d = sum(a);
    }
    cout << d << endl;
    return 0;
}
