#include <bits/stdc++.h>

using namespace std;


#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define Mx 50007
#define inf 9999999999
struct t
{
    ll pre,sufix,ans,sum;
} tree[4*Mx];
ll num,arr[Mx],q,v1,v2;
void tree_build(ll node, ll b, ll e)
{

    if(b==e)
    {
        tree[node].ans=arr[b];
        tree[node].pre=arr[b];
        tree[node].sufix=arr[b];
        tree[node].sum=arr[b];
        return;
    }

    ll mid=(b+e)/2;

    tree_build(node*2,b,mid);
    tree_build(node*2+1,mid+1,e);
    tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum);
    tree[node].pre=max(tree[node*2].pre,(tree[node*2].sum+tree[node*2+1].pre));
    tree[node].sufix=max(tree[node*2+1].sufix,(tree[node*2+1].sum+tree[node*2].sufix));
    tree[node].ans=max(tree[node*2].ans,max(tree[node*2+1].ans,(tree[node*2].sufix+tree[node*2+1].pre)));
    return;
}
t query(ll node,ll b, ll e, ll i, ll j)
{

    if(i>e || b>j)
    {
        t xx;
        xx.pre=-inf;
        xx.sufix=-inf;
        xx.ans=-inf;
        xx.sum=-inf;
        return xx;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    ll mid=(b+e)/2;
    t val1=query(node*2,b,mid,i,j);
    t val2=query(node*2+1,mid+1,e,i,j);

    if(val1.ans==-inf)
        return val2;

    if(val2.ans==-inf)
        return val1;

    t vx;

    vx.sum=val1.sum+val2.sum;
    vx.pre=max(val1.pre,(val1.sum+val2.pre));
    vx.sufix=max(val2.sufix,(val2.sum+val1.sufix));
    vx.ans=max(val1.ans,max((val1.sufix+val2.pre),val2.ans));
//cout<<val1.sum<<" "<<val2.sum<<" "<<b<<" "<<e<<" "<<i<<" "<<j<<endl;
    return vx;

}

int main()
{
    //    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    //ios::sync_with_stdio(false);
scanf("%lld",&num);
    FOR(i,1,num+1)
    {

       // cin>>arr[i];
       scanf("%lld",&arr[i]);
    }
    tree_build(1,1,num);
 // cout<<inf<<endl;
//for(int i=1;i<=20;i++)cout<<tree[i].ans<<" ";
   // cin>>q;
   scanf("%lld",&q);
    FOR(i,0,q)
    {
      //  cin>>v1>>v2;
      scanf("%lld%lld",&v1,&v2);
        if(v1>v2)
            swap(v1,v2);

        t anss=query(1,1,num,v1,v2);
        //cout<<anss.ans<<endl;
        printf("%lld\n",anss.ans);
    }
}
/*
10
-1 9 2 6 -4 3 5 2 -6 1
1
4 7
*/
