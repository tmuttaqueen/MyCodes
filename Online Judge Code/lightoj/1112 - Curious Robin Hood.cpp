#include <bits/stdc++.h>

using namespace std;

int data[100005];
int tree[300005];

void build_segment_tree( int current_node, int first, int last )
{
    if( first == last )
    {
        tree[current_node] = data[first];
        //cout << first << endl;
        return;
    }
    int mid = (first+last)/2;
    build_segment_tree(  current_node<<1, first, mid );
    build_segment_tree( current_node<<1|1, mid+1, last );
    tree[current_node] = tree[current_node<<1] + tree[current_node<<1|1] ;
    return;
}

int query( int node, int first, int last, int qs, int qe )
{
    if( first > qe || last < qs )
        return 0;
    if( first >= qs && last <= qe )
        return tree[node];
    int mid = (first+last)/2;
    return query( node<<1, first, mid, qs, qe ) + query( node<<1|1 , mid+1, last, qs, qe );
}

void update( int node, int first, int last, int pos, int newvalue )
{
    if( pos < first || pos > last )
        return;
    if(first==last )
    {
        tree[node] = newvalue;
        return;
    }
    int mid = (first+last)/2;
    update( node<<1, first, mid, pos, newvalue );
    update( node<<1|1, mid+1, last, pos, newvalue );
    tree[node] = tree[node<<1] + tree[node<<1|1];
    return;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int n, q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", caseno++);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &data[i]);
        }
        build_segment_tree( 1, 1, n );
        while( q-- )
        {
            int x, y, z, sum;
            scanf("%d %d", &x, &y );
            y++;
            if( x == 1 )
            {
                //cout << "yes 1\n";
                printf("%d\n", data[y]);
                data[y] = 0;
                update( 1, 1, n, y, data[y] );
                //cout << "yes 1\n";
            }
            else if( x == 2 )
            {
                int v;
                //cout << "yes 2\n";
                scanf("%d", &v);
                data[y] += v;
                update( 1, 1, n, y, data[y] );
            }
            else
            {
                //cout << "yes 3\n";
                scanf("%d", &z);
                z++;
                sum = query(1, 1, n, y, z );
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
