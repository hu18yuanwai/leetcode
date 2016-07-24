#include <iostream>
using namespace std;
typedef struct node {
        char data;
        struct node *lchild;
        struct node *rchild;
        }BiNode,*BiTree;
typedef struct node1{
        BiTree data[30];     //默认30个元素 ，这里需要一个辅助堆栈！！！
        int top;
        }Stack;

void createTree(BiTree &T)   //先序递归创建树，这里注意参数的类型，T的类型是 "*&" ,如果是 "**" 代码稍加改动就OK...
{
     char ch;
     cin.get(ch).get();      //过滤输入流中每次回车产生的回车符
     if (ch==' ') T=NULL;    //这里首先判断是不是空格，如果是，则为该节点赋NULL
     else{
            T=(BiTree)malloc(sizeof(BiNode));
            T->data=ch;
            createTree(T->lchild);
            createTree(T->rchild);
          }
}
void initstack(Stack *&st)
{
     st=(Stack *)malloc(sizeof(Stack));
     st->top=-1;
}
bool isempty(Stack *st)
{
    return st->top==-1;
}
bool isfull(Stack *st)
{
    return st->top==19;
}
void push(Stack *st,BiTree T)
{
     if (!isfull(st))
     	st->data[++st->top]=T;     //栈顶指针始终指向堆栈最上面可用的一个元素，因此入栈时候，先要将指针加1,然后再执行入栈操作！
     else cout<<"已满"<<endl;
}
BiTree pop(Stack *st)
{
     if (!isempty(st)) return st->data[st->top--];
}
BiTree gettop(Stack *st)
{
       if (!isempty(st)) return st->data[st->top];  //出栈时，先取出栈顶指针指向的元素，然后再将指针减1，使其指向栈中下一个可用元素！
}


void preOrderNoRe(BiTree T)          // 前序遍历
{
   Stack *st;
   initstack(st);
   BiTree p;
   p=T;
     while (p!=NULL||!isempty(st))
     {
           while (p!=NULL)
           {
                 cout<<p->data<<"  ";
                 push(st,p);
                 p=p->lchild;
           }
           if (!isempty(st))
           {
                       p=pop(st);
                       p=p->rchild;
           }

     }
}

void inOrderNoRe(BiTree T)       //中序遍历
{
   Stack *st;
   initstack(st);
   BiTree p;
   p=T;
     while (p!=NULL||!isempty(st))
     {
           while (p!=NULL)
           {
                 push(st,p);
                 p=p->lchild;
           }
           if (!isempty(st))
           {
                       p=pop(st);
                       cout<<p->data<<"  ";
                       p=p->rchild;
           }

     }
}
void postOrderNoRe(BiTree T)          //后序遍历
{
     BiTree p;
     Stack *st;
     initstack(st);
     p=T;
     int Tag[20];      //栈，用于标识从左（0）或右（1）返回
     while (p!=NULL || !isempty(st))
     {
           while (p!=NULL)
           {
                 push(st,p);
                 Tag[st->top]=0;
                 p=p->lchild;
           }
           while (!isempty(st)&&Tag[st->top]==1)
           {
                 p=pop(st);
                 cout<<p->data<<"  ";
           }
           if (!isempty(st))
           {
                            Tag[st->top]=1;   //设置标记右子树已经访问
                            p=gettop(st);
                            p=p->rchild;
           }
           else break;
     }
}

int main()
{
    cout<<"Enter char one by one                      hicjiajia"<<endl;
    BiNode *T;
    createTree(T);
    cout<<endl;

    cout<<"preOrderNoRe:  ";preOrderNoRe(T);cout<<endl;
    cout<<"inOrderNoRe:   ";inOrderNoRe(T);cout<<endl;
    cout<<"postOrderNoRe: ";postOrderNoRe(T);cout<<endl;
    system("pause");
    return 0;
}
