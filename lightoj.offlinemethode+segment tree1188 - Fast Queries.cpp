#include<bits/stdc++.h>
using namespace std;
#define mx 100001

 struct Qt{
    int a,b,value;
    };
       Qt q2[mx];
int arr[mx];
int tree[mx*3];
void init (int node,int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
           cout<<tree[node]<<" "<<arr[b]<<" "<<b<<endl;
        return;
    }
    int left = node*2;
    int right = node *2+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
           cout<<tree[node]<<" "<<endl;
}
 int query(int node, int b,int e,int i,int j)
{
    if (i > e || j < b)
        return 0;
    if (b >= i && e <= j){
                       cout<<tree[node]<<" "<<endl;
        return tree[node];
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
        return p1+p2;
        cout<<p1+p2<<endl;
}
void update( int node,  int b, int e,  int i,int newvalue)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i) {
        arr[node] = newvalue;
        cout<<node<<" "<< arr[node]<<" "<<newvalue<<endl;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];
               cout<<tree[node]<<" "<<endl;
}
bool comp(Qt num1, Qt num2)
{
    if(num1.b<=num2.b)
        return true;
    else
        return false;
}
int main()
{
    int cas=0,test, num, qurie,num1,num2,ans[mx],last[mx];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&num,&qurie);
        for(int i=1;i<=num;i++){
            scanf("%d",&arr[i]);
           // cout<<arr[i]<<" "<<i<<endl;
        }
        init(1,1,num);
        memset(last,0,num);
        for(int i=1;i<=qurie;i++)
        {
            scanf("%d%d",&num1,&num2);
            q2[i].a=num1;
            q2[i].b=num2;
            q2[i].value=i;
        }
        sort(q2,(q2+qurie+1),comp);
         for(int i=1;i<=qurie;i++)
        {
           // scanf("%d%d",&num1,&num2);
            cout<<q2[i].a<<" "<<q2[i].b<<" "<<q2[i].value<<endl;
        }
        for(int i=1;i<=qurie;i++)
        {
            int ma=max(q2[i].a,q2[i].b);
           int mn=min(q2[i].a,q2[i].b);
            for(int j=mn;j<=ma;j++)
            {
                if(last[arr[j]]==0){
                     //   cout<<arr[j]<<" "<<j<<endl;
                    last[arr[j]]=j;
                    update(1,1,num,arr[j],1);
                }
                else
                {
                    int  lst =last[arr[j]];
                    last[arr[j]]=j;
                    update(1,1,num,lst,0);
                    update(1,1,num,j,1);
                }
            }
           int ansr =q2[i].value;
           ans[ansr]=query(1,1,num,mn,ma);
           cout<<ansr<<" "<<ans[ansr]<<endl;
        }
       // sort(ans,ans+qurie+1);
            printf("Case %d:\n",++cas);
        for(int i=1;i<=qurie;i++)
        {
            printf("%d\n",ans[i]);
        }

    }
}
