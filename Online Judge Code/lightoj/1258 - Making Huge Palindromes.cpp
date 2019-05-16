#include <bits/stdc++.h>

using namespace std;

const int ss = 1000005;
const int mod = 1000000007;
const int b1 = 149;
const int b2 = 151;
long long rem1[ss], rem2[ss];

void aaa()
{
    rem1[0] = 1;
    rem2[0] = 1;
    for( int  i = 1; i < 1000001; i++ )
    {
        rem1[i] = rem1[i-1]*b1;
        rem1[i] %= mod;
        rem2[i] = rem2[i-1]*b2;
        rem2[i] %= mod;
    }
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d\n", &t);
    aaa();
    while(t--)
    {
        char str1[ss], str2[ss];
        gets(str1);

        int len = strlen(str1);
        for( int i = 0; i < len; i++ )
        {
            str2[len-i-1] = str1[i];
        }
        str2[len] = '\0';
        //puts(str1);
        //puts(str2);
        long long val1 = 0, val2 = 0, n1 = 0, n2 = 0, j = 0, mm = 0;
        for( int i = len -1; i >= 0; i--, j++ )
        {
            val1 = (val1*b1)%mod + ((int)str1[i]*rem1[0])%mod;
            val1 %= mod;
            val2 = (val2*b2)%mod + ((int)str1[i]*rem2[0])%mod;
            val2 %= mod;
            n1 = n1 + ((int)str2[j]*rem1[j])%mod;
            n1 %= mod;
            n2 = n2 + ((int)str2[j]*rem2[j])%mod;
            n2 %= mod;
            if( val1 == n1 && val2 == n2 )
            {
                mm = j+1;
                //cout << "mm " << mm << endl;
            }
        }
        mm = 2*len - mm;
        printf("Case %d: %lld\n", caseno++,mm);
    }
    return 0;
}
