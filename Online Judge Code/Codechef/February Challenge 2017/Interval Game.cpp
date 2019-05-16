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
#define gc getchar_unlocked
int ara[300005];
intl sum[300005];
int qu[205];
intl dp[205][300005];
intl mxset[300005];

int n, m;
intl dq[600200];

void doit( int d, int id )
{
    intl low, high;
    low = high = 8;
    for( int i = 0; i <= n-d; i++ )
        mxset[i] = -1;
    for( int i = 0; i < d; i++ )
    {
        while( high -low > 0 && dp[id][i] > dp[id][dq[high-1]]  )
            high--;
        dq[high++] = i;
        //dq.push_front(i);
    }
    mxset[0] = dp[id][dq[low]];
    for( int i = d; i < n; i++ )
    {
        while( high -low > 0 && dp[id][i] > dp[id][dq[high-1]]  )
            high--;
        while( high -low  > 0 && dq[low] <= (i-d)  )
            low++;
        dq[high++] = i;
        //dq.push_front(i);
        mxset[i-d+1] = dp[id][dq[low]];
    }
}


void readInt(int &x){
    register char c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        //for( int i = 0; i <= m; i++ )
        //for( int j = 0; j <= n; j++ )
        //dp[i][j] = -1;

        for( int i = 0; i < n; i++ )
            readInt(ara[i]);
            //scanf("%d", &ara[i]);
        for( int i = 0; i < m; i++ )
            readInt(qu[i]);
            //scanf("%d", &qu[i]);
        sum[0] = ara[0];
        int k = qu[m-1];

        for( int i = 1; i < n; i++ )
            sum[i] = sum[i-1] + ara[i];



        dp[0][0] = sum[k-1];
        for( int i = k; i < n; i++ )
        {
            dp[0][i-k+1] = sum[i] - sum[i-k];
        }

        //for( int i = 0; i < n; i++ ) cout << dp[0][i] << " ";

        for( int i = m-2; i >= 0; i-- )
        {
            int ind = m - i - 1;

            doit(qu[i] - qu[i+1] - 1, ind-1);
            /*int d = qu[i] - qu[i+1] - 1, id = ind - 1;
            dq.clear();
            for( int i = 0; i <= n-d; i++ )
                mxset[i] = -1;
            for( int i = 0; i < d; i++ )
            {
                while( dq.size() > 0 && dp[id][i] > dp[id][dq.front()]  )
                    dq.pop_front();
                dq.push_front(i);
            }
            mxset[0] = dp[id][dq.back()];
            for( int i = d; i < n; i++ )
            {
                while( dq.size() > 0 && dp[id][i] > dp[id][dq.front()]  )
                    dq.pop_front();
                while( dq.size() > 0 && dq.back() <= (i-d)  )
                    dq.pop_back();
                dq.push_front(i);
                mxset[i-d+1] = dp[id][dq.back()];
            }*/



            k = qu[i];
            dp[ind][0] = sum[k-1] - mxset[1];
            for( int j = 1; j <= n - k; j++ )
            {
                dp[ind][j] = sum[j+k-1] - sum[j-1] - mxset[j+1];
            }
        }
        intl ans = -1;
        for( int i = 0; i <= n - k; i++ ) ans = max(ans,dp[m-1][i]);
        printf("%lld\n", ans);


    }

    return 0;
}




