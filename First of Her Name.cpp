#include<bits/stdc++.h>

using namespace std;

#define xx first
#define yy second

const int MAXN = 1e6+5;

int par[MAXN];
char top[MAXN];
int n, k;
int rmq[MAXN][20];

void init()
{
    for( int i = 0; i <= n; i++ )
    {
        rmq[i][0] = par[i];
        //cout << i << " " << 0 << " " << rmq[i][0] << endl;
    }

    for( int i = 1; i < 20; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            int ind = rmq[j][i-1];
            rmq[j][i] = rmq[ind][i-1];
            //cout << j << " " << i << " " << ind << " " << rmq[j][i] << endl;
        }
    }

}

char character(int n, int ind)
{
    for(int i = 19; i >= 0; i--)
    {
        if(ind >= (1<<i) )
        {
            //cout << "in " << n << " " << i << endl;
            n = rmq[n][i];
            ind -= (1<<i);
            if(ind == 0)
                return top[n];
        }
    }
    //cout << "qf " << n << endl;
    return top[n];
}

int Rank[MAXN], ans[MAXN];
pair<pair<int,int>, int> sf[MAXN], temp[MAXN];
vector<pair<string, int>> query;
int cnt[MAXN];

bool Less(string &s, int name)
{
    //cout << "Name " << name  << endl;
    for( int j = 0; j < s.size(); j++ )
    {
        //cout << name << " " << j << endl;
        char ch = character( name, j);
        //if( ch != 'E' ) cout << "xx " << (int)ch << " " << name << " " << j << endl;
        if( ch > s[j] || ( j == s.size() - 1 && ch == s[j] ) )
        {
            return 1;
        }
        if( ch < s[j] )
            return 0;
    }
    cout << name << endl;
    return 0;
}
int main()
{
    freopen("secret-010_ONE_LETTER__RANDOM.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin>>n>>k;

    for(int i = 1; i <= n; i++)
    {
        char c; int p;
        cin.ignore();
        cin >> c >> p;
        top[i] = c;
        par[i] = p;
        //cout << i << " " << c << " " << p << endl;
    }

    init();


    //cout << "jjfdfdf " << endl;
    //cout << rmq[3][0] << endl;
    //cout << "ok" << endl;
    //cout << character(3,1) << endl;

    for(int i = 1; i <= n; i++ )
    {
        sf[i].xx.xx = top[i];
        sf[i].yy = i;
    }
    Rank[0] = 0;
    sort(sf + 1, sf + n + 1);
    for(int i = 0; i < 20; i++)
    {
        int st = 1;
        for(int j = 1; j <= n; j++)
        {
            if( j > 1 && sf[j].xx != sf[j-1].xx )
                st++;
            Rank[ sf[j].yy ] = st;
        }
        if(st == n )
            break;
        for(int j = 1; j <= n; j++)
        {
            sf[j].yy = j;
            sf[j].xx.xx = Rank[j];
            sf[j].xx.yy = Rank[ rmq[j][i] ];
            //cout << sf[j].yy << " " << sf[j].xx.xx << " " << sf[j].xx.yy << endl;
        }
        //sort(sf+1, sf + n + 1, comp);
        memset(cnt, 0, sizeof cnt);
        for(int j = 1; j <= n; j++)
            cnt[ sf[j].xx.yy]++;
        for(int j = 1; j <= n; j++)
            cnt[j] += cnt[j-1];
        for(int j = n; j >= 1; j--)
            temp[ cnt[sf[j].xx.yy] ] = sf[j], cnt[sf[j].xx.yy]--;

        memset(cnt, 0, sizeof cnt);
        for(int j = 1; j <= n; j++)
            cnt[ temp[j].xx.xx]++;
        for(int j = 1; j <= n; j++)
            cnt[j] += cnt[j-1];
        for(int j = n; j >= 1; j--)
            sf[ cnt[temp[j].xx.xx] ] = temp[j], cnt[temp[j].xx.xx]--;
        //cout << "ok" << endl;

    }
    for(int i = 1; i <= n; i++)
    {
        Rank[ sf[i].yy ] = i;
    }
//    cout << "kk " << endl;
//    for (int i = 1; i <= n; i++ )
//    {
//        cout << i << " " << Rank[i] << endl;
//        /* code */
//    }
    //return 0;

    for(int i = 1; i <= k; i++)
    {
        string s;
        cin >> s;
        //cout << s.size() << endl;
        query.push_back( make_pair(s, i) );
        query.push_back( make_pair(s+"a",i) );
    }
    sort(query.begin(), query.end());

    int cur = 1, prev = 1;
    for(int i = 0; i < query.size(); i++ )
    {

        int ind = query[i].yy;
        int l = prev, r = n, pos = n+1;
        while(l <= r)
        {
            int m = (l+r)/2;
            //cout << "m " << m << endl;
            if( Less(query[i].xx , sf[m].yy ) )
            {
                pos = m;
                r = m-1;
            }
            else
                l = m + 1;
        }
        //cout << pos << endl;
        if( query[i].xx[ query[i].xx.size() - 1 ] != 'a' )
            ans[ind] = pos;
        else
            ans[ind] = pos - ans[ind];
    }

    for( int i = 1; i <= k; i++)
    {
        cout <<  ans[i] << "\n";
    }


    return 0;
}





