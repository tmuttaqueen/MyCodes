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
#define what_is(x)  cout << #x << " is " << x << "\n"
#define pb          push_back
#define eb          emplace_back
#define pii         pair<string, int>
#define piii        pair<pii, int>

string s1 = "insert", s2 = "getMin", s3 = "removeMin";
int inf = -1100000000;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, a, b;
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<pii>vec;
    string s;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> s;
        if( s == s1 )
        {
            cin >> a;
            cin.ignore();
            pq.push(a);
            vec.pb( mp(s,a) );
        }
        else if( s == s2 )
        {
            cin >> a;
            cin.ignore();
            while( !pq.empty() && pq.top() < a )
            {
                pq.pop();
                vec.pb(mp(s3,inf));
            }
            if( pq.empty() )
            {
                pq.push(a);
                vec.pb( mp(s1,a) );
            }
            if( pq.top() != a )
            {
                pq.push(a);
                vec.pb( mp(s1,a) );
            }
            vec.pb( mp(s2,a) );
        }
        else
        {
            if( pq.empty() )
            {
                pq.push(1);
                vec.pb(mp(s1,1));
            }
            pq.pop();
            vec.pb(mp(s3,inf));
        }
    }

    cout << vec.size() << endl;
    for( int i = 0; i < vec.size(); i++ )
    {
        if( vec[i].xx == s3 )
        {
            cout << vec[i].xx << "\n";
        }
        else
        {
            cout << vec[i].xx << " " << vec[i].yy << "\n";
        }
    }
    return 0;
}



