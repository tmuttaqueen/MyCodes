#include <bits/stdc++.h>

using namespace std;

int data[100005];
int tree[300015];

void build_tree( int node, int first, int last )
{
    if( first == last )
    {
        tree[node] = data[first];
        return;
    }
    int mid = (first+last)/2;
    build_tree( node<<1, first, mid );
    build_tree( node<<1|1, mid+1, last );
    tree[node] = min( tree[node<<1], tree[node<<1|1] );
    return;
}

int query( int node, int first, int last, int qs, int qe )
{
    if( last < qs || first > qe )
        return 100000000;
    if( first >= qs && last <= qe )
        return tree[node];
    int mid = (first + last)/2;
    return min( query( node<<1, first, mid, qs, qe ), query( node<<1|1, mid+1, last, qs, qe ) );
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    int caseno = 1;
    while(t--)
    {
        getchar();

        int n, q;
        scanf("%d %d", &n, &q);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &data[i]);
        }
        build_tree( 1, 1, n );
        printf("Case %d:\n", caseno++);
        while( q-- )
        {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", query( 1, 1, n, x, y ));
        }
    }
    return 0;
}
