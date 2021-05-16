#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *lchild;
    node *rchild;
    node()
    {
        lchild=NULL;
        rchild=NULL;
    }
}*root=NULL;

class que
{
    public:
    int front,rear,size;
    node **q;
    que()
    {
        front=rear=-1;
        size=20;
        q=new node*[size];
    }
    void enque(node *p)
    {
        if(rear==size-1)
        {
            cout<<"que IS FULL\n";
            return;
        }
        rear++;
      q[rear]=p;
    }
    node* deque()
    {
        if(front==rear)
        {
            cout<<"QUEUE IS EMPTY\n";
            return NULL;
        }
        node * tem=q[front+1];
        front++;
        return tem;
    }
    void display()
    {
        if(front==-1 || front==rear) return;
        else{
            int temp = front;
        while(temp!=rear+1)
        {
            cout<<q[temp]<<" ";
        }
        }
    }
     
}obj,q1,q2;

void create()
{
    char ans='y';
    int x;
    node *p=NULL;
    if(root==NULL)
    {
        root=new node;
        cout<<"Enter root data ";
        cin>>root->data;
        obj.enque(root);
    }
    while(ans=='y')
    {
       
        p=obj.deque();
        if(p==NULL)
        break;
        cout<<"Enter lchild of"<<p->data;
        cin>>x;
        if(x!=-1)
        {
            node *t=new node;
            t->data=x;
            p->lchild=t;
            obj.enque(t);
            t=NULL;
        }
        cout<<"Enter right child of"<<p->data;
        cin>>x;
         if(x!=-1)
        {
            node *t=new node;
            t->data=x;
            p->rchild=t;
            obj.enque(t);
            t=NULL;
        }
        cout<<"\nDo you want to enter more ";
        cin>>ans;
    }
}
void traversal(node *curr)
{
 if(curr==root)
 {
     cout<<curr->data<<" ";
     q2.enque(curr->lchild);
     q2.enque(curr->rchild);
 }
 if(q2.front==q2.rear && q1.front==q1.rear)
 {
     return;
 }
 while(q2.front!=q2.rear)
 {
     curr=q2.deque();
     if(curr->lchild!=NULL)
     q1.enque(curr->lchild);
     if(curr->rchild!=NULL)
     q1.enque(curr->rchild);
     cout<<curr->data<<" ";
 }
  while(q1.front!=q1.rear)
 {
     curr=q1.deque();
     if(curr->lchild!=NULL)
     q2.enque(curr->lchild);
     if(curr->rchild!=NULL)
     q2.enque(curr->rchild);
     cout<<curr->data<<" ";
 }
 traversal(curr);
}
void preorder(node *p)
{
    if(p==NULL)
    {
        return;
    }
    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
}
void postorder(node *p)
{
    if(p==NULL)
    {
        return;
    }
    postorder(p->lchild);
    postorder(p->rchild);
    cout<<p->data<<" ";
}
void inorder(node *p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
}
int main()
{
    create();
    cout<<"LEVEL:";
    traversal(root);
    cout<<"\nPREORDER:";
    preorder(root);
    cout<<"\nPOSTORDER:";
    postorder(root);
    cout<<"\nINORDER:";
    inorder(root);
    return 0;

}