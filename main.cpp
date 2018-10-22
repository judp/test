#inlcude<cstdio>

struct Node
{
    bool black;
    Node* n1,n2,n3,n4;
};

Node nodes1[341],nodes2[341];
int cur;
Node* build(Node*p)
{
    char c;
    c=getchar();
    Node*pn=p+cur;
    if(c=='p')
    {
        pn->n1=build(p);
        pn->n2=build(p);
        pn->n3=build(p);
        pn->n4=build(p);
    }
    else
    {
        pn->black=(c=='e'?0:1);
        pn->n1=nullptr;
    }
    return pn;
}
int cnt;

void solve(Node root1,Node,root2,int n)
{
    if(root1->n1!=nullptr&&root2->n1!=nullptr)
    {
        solve(root1->n1,root2->n1);
        solve(root1->n2,root2->n2);
        solve(root1->n3,root2->n3);
        solve(root1->n4,root2->n4);
    }
    else if()
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        Node root1,root2;
        cur=0;
        root1=build(nodes1);
        getchar();
        cur=0;
        root2=build(nodes2);

        cnt=0;
        solve(root1,root2,0);
        printf("There are %d black pixels.\n",cnt);
    }
}
