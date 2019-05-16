#include <bits/stdc++.h>

using namespace std;

struct data
{
    long long sum;
    long long prop;
};

data tree[300015];

void build_tree( int node, int first, int last )
{
    if( first == last )
    {
        tree[node].sum = 0;
        tree[node].prop = 0;
        return;
    }
    int mid = (first+last)>>1;
    build_tree( node*2, first, mid );
    build_tree( node*2 + 1, mid + 1, last );
    tree[node].sum = tree[node*2].sum + tree[node*2 + 1].sum;
    tree[node].prop = 0;
    return;
}
void update( int node, int first, int last, int i, int j, int x )
{
    if( last < i || first > j )
        return;
    if( first >= i && last <= j )
    {
        tree[node].sum += (last-first+1)*x;
        tree[node].prop += x;
        return;
    }
    int mid = ( first + last )>>1;
    update( node*2, first, mid, i, j, x  );
    update( node*2 + 1, mid+1, last, i, j, x );
    tree[node].sum = tree[node*2].sum + tree[node*2 + 1].sum + (last-first+1)*tree[node].prop;
    return;
}

/*void view_tree( )
{
    int i = 1, j = 1, k = 1;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    while( i < 7 )
    {
        cout << ">>>>>" << endl;
        while( j <= k )
        {
            cout << "s " << tree[j].sum << " p " << tree[j].prop << "--";
            j++;
        }
        k = k*2+1;
        i++;
        cout << endl;
    }
}*/

long long query( int node, int first, int last, int i, int j, long long carry = 0 )
{
    //cout << " f " << first << " l " << last << " cr " <<  carry << endl;
    if( last < i || first > j )
        return 0;
    if( first >= i && last <= j )
    {

        return tree[node].sum+(last-first+1)*carry;
    }
    int mid = (first+last)>>1;
    long long p1 = query( node*2, first, mid, i, j, carry+tree[node].prop ) ;
    long long p2 =  query( node*2 + 1, mid+1, last, i, j, carry+tree[node].prop );
    return p1+p2;
}

int main()
{
    //freopen("input.txt", "r",stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int a, x, y, q, qq, n;
        scanf("%d %d",&n, &qq);
        //for( int i = 0; i <= n; i++ ) ara[i] = 0;
        build_tree( 1, 1, n );
        printf("Case %d:\n", caseno++);
        while( qq-- )
        {
            scanf("%d %d %d", &a, &x, &y);
            if(a==1)
            {
                printf("%lld\n", query( 1, 1, n, x+1, y+1));
            }
            else
            {
                scanf("%d", &q);
                update( 1, 1, n, x+1, y+1, q );
            }
            //view_tree();
        }
    }

    return 0;
}
