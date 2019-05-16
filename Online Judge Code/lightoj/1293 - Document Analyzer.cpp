#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

char str[105];
vector<int>vec;
int total = 0;
map<string, int>mm;
int flag[50005];

void nslice()
{
    int i = 0;
    string temp;

    if( str[0] >= 'a' && str[0] <= 'z' )
        temp += str[0];
    i++;
    while(str[i])
    {
        if( (str[i] >= 'a' && str[i] <= 'z') && (str[i-1] < 'a' || str[i-1] > 'z') )
        {
            if( !temp.empty() )
            {
                //cout << temp << endl;
                if( mm.count(temp) > 0 )
                {
                    flag[ mm[temp] ]++;
                }
                else
                {
                    mm[temp] = total++;
                    flag[ mm[temp] ]++;
                }
                vec.pb(mm[temp]);
            }
            temp.clear();
        }
        if( str[i] >= 'a' && str[i] <= 'z' )
            temp += str[i];
        i++;
    }
    if( !temp.empty() )
    {
        //cout << temp << endl;
        if( mm.count(temp) > 0 )
        {
            flag[ mm[temp] ]++;
        }
        else
        {
            mm[temp] = total++;
            flag[ mm[temp] ]++;
        }
        vec.pb(mm[temp]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        total = 0;
        memset( flag, 0 , sizeof(flag) );
        str[0] = '\0';
        while( strcmp(str, "END") )
        {
            gets(str);
            nslice();
        }
        /*for( int i = 0; i < vec.size(); i++ )
        {
            printf("%d ", vec[i]);
        }
        puts("");*/
        int sum = 0, l = 0, h = 0, x = 0, y = 1000000000;
        memset(flag, 0, sizeof(flag));


        for( int i = 0; i < vec.size(); i++ )
        {
            while( sum < total )
            {
                if( flag[ vec[h] ] == 0 )
                    sum++;
                flag[ vec[h] ]++;
                if( (h < vec.size() - 1) && sum != total )
                    h++;
                else
                    break;
                //what_is(sum);
                //what_is(h);
            }
            if( (y-x)>(h-i) && sum == total )
            {
                x = i;
                y = h;
            }
            if( flag[ vec[i] ] == 1 )
                sum--;
            flag[ vec[i] ]--;

            /*for( int i = 0; i < total; i++ )
            {
                printf("%d ", flag[i]);
            }
            puts("");*/
        }
        printf("Case %d: %d %d\n", caseno++, x+1, y+1);
        mm.clear();
        vec.clear();
    }

    return 0;
}



