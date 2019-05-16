#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    char str1[1000005], str2[1000005];
    int i = 0, s1, s2;
    gets(str1);
    gets(str2);
    int a = 0, b=0;
    while( str1[a] == '0')
        a++;
    while( str2[b] == '0' )
        b++;
    int len1 = strlen(str1), len2 = strlen(str2);
    int l1 = len1 - a;
    int l2 = len2 - b;
    if( l1 < l2 )
    {
        printf("<\n");
        return 0;
    }
    if( l1 > l2 )
    {
        printf(">\n");
        return 0;
    }
    for( int  i = 0; i < l1; i++ )
    {
        if( str1[a] < str2[b] )
        {
            printf("<\n");
            return 0;
        }
        else if( str1[a] > str2[b] )
        {
            printf(">\n");
            return 0;
        }
        a++;
        b++;
    }
    printf("=\n");
    return 0;
}
