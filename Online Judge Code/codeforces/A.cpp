#include<bits/stdc++.h>

using namespace std;




char ara[100005];
string s;
int cur, len;

void pp()
{
    for( int i = 1; i <= len; i++ )
    {
        cout << ara[i];
    }
    cout << endl;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n >> s;
    for( int i = 1; i <= s.length(); i++ )
        ara[i] = s[i-1];
    cur =  s.length()+1; len = s.length();
   // pp();
    while(n--)
    {
        int a;
        cin >> a;
        if( a == 1)
        {
            cin >> s;
            if( s.length()== 1 )
            {
                char ccc = s[0];
                if( cur <= len )
                {
                    char prev = ara[cur];
                    for( int i = cur+1; i <= len+1 ;i++ )
                    {
                        char cc = ara[i];
                        ara[i] = prev;
                        prev = cc;
                    }
                }
                ara[cur++] = ccc;
                len++;
            }
            else
            {
                if( cur > 1 )
                {
                    for( int i = cur-1; i < len; i++ )
                    {
                        ara[i] = ara[i+1];
                    }
                    cur--;
                    len--;
                }
                else
                    cur = 1;
            }
            //pp();
        }
        if( a == 2 )
        {
            cin >> cur;
            cur++;
        }
    }
    pp();

    return 0;
}
