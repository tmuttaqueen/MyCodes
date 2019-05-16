#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

char s1[200005], s2[200005];
int ara[200005];
int temp[200005];
char ss[200005];

bool isSubSequence(char str1[], char str2[], int m, int n)
{
   int j = 0;
   for (int i=0; i<n&&j<m; i++)
       if (str1[j] == str2[i])
         j++;
   return (j==m);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    scanf("%s %s", s1, s2);
    int l2 = strlen(s2);
    int len = strlen(s1);
    for( int i = 0; i < len ;i++ )
    {
        scanf("%d", &ara[i]);
    }
    int ans;
    int low = 0, high = len - 1;
    while( low <= high )
    {
        int mid = (low+high)/2;
        //what_is(mid);
        int c = 0;
        for( int i = mid; i < len ;i++ )
        {
            temp[c++] = ara[i];
        }
        sort( temp, temp + c );
        for( int i = 0; i < c; i++ )
        {
            ss[i] = s1[ temp[i] - 1 ];
        }
        if( isSubSequence( s2, ss, l2, c ) )
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }

    cout << ans << endl;
    return 0;
}



