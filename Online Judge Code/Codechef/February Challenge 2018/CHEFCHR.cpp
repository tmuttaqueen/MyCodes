#include<bits/stdc++.h>

using namespace std;
string s;

int ara[27];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset( ara, 0, sizeof ara );
        cin >> s;
        int c = 0;
        for( int i = 0; i < 3 && i < s.length(); i++ )
            ara[ s[i]-'a' ]++;
        for( int i = 3; i < s.length(); i++ )
        {
            ara[ s[i]-'a' ]++;
            if( ara[ 'c' - 'a' ] >= 1 && ara[ 'h'-'a' ] >= 1 && ara[ 'e'-'a' ] >= 1 && ara[ 'f'-'a' ] >= 1 )
            {
                c++;
                //cout << i << endl;
            }
            ara[ s[i-3] -'a' ]--;
        }
        if(c)
        {
            cout << "lovely " << c << endl;
        }
        else
            cout << "normal" << endl;
    }

    return 0;
}
