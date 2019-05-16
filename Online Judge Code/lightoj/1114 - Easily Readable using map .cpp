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

vector<string> vec;

void sliice( string &s )
{
    string temp = "";
    for( int i = 0; i < s.size(); i++ )
    {
        if( i > 0 && s[i] == ' ' && s[i-1] == ' ' )
            continue;
        if( s[i] == ' ' && temp != "")
        {
            vec.pb(temp);
            temp = "";
        }
        else if( s[i] >= 'A'  )
            temp += s[i];
    }

    if( temp != "" && temp != " " )
        vec.pb(temp);
    for( int i = 0; i < vec.size(); i++ )
    {
        if( vec[i].size() > 1 )
        {
            char c = vec[i][1];
            vec[i][1] = vec[i][vec[i].size()-1];
            vec[i][vec[i].size()-1] = c;
        }
        if( vec[i].size() > 1 )
            sort( vec[i].begin() + 2, vec[i].end() );
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n;
        map<string,int>mm;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            string s;
            cin >> s;
            if( s.size() > 1 )
            {
                char c = s[1];
                s[1] = s[s.size()-1];
                s[s.size()-1] = c;
            }
            if( s.size() > 1 )
                sort( s.begin() + 2, s.end() );
            mm[s]++;

        }
        int m;
        cin >> m;
        cin.ignore();
        cout << "Case " << caseno++ << ":\n";
        for( int i = 0; i < m; i++ )
        {
            long long ans = 1;
            string s;
            getline( cin, s );
            sliice(s);
            for( int i = 0; i < vec.size(); i++ )
            {
                int ss = mm[vec[i]];
                ans *= ss;
            }

            cout << ans << "\n";
            vec.clear();
        }
    }

    return 0;
}
