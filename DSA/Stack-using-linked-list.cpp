#include<stdio.h>

struct Node
{
    int data;
    Node* next;
};
Node* top = NULL;

void push(int x)
{
    Node* newnode= new Node();
    newnode->data=x;
    newnode->next=0;
    if(top==0)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }

}
void display()
{
    Node* temp = top;
    if(top==NULL)
    {
        printf("The list is empty");
    }
    else
    {

       printf("The list is =");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }

    }
}
void pop()
{
    Node* temp = top;
    if(top==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("The popped out element is - %d",top->data);
        top=top->next;
        delete(temp);
    }
}
void peek()
{
    if(top==NULL)
    {
        printf("The list is empty!");

    }
    else
    {
        printf("The First element is %d ",top->data);
    }


}

int main ()
{
    int x;
    while(true)
    {
        printf("\n\n1.Push \n2.Pop \n3.Display \n4.peek \n5.Exit ");
        printf("\nEnter your choice : ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
        {
            printf("Enter a value- ");
            scanf("%d",&x);
            push(x);
            break;
        }
        case 2:
        {
            pop();
            break;

        }

        case 3:
        {
            display();
            break;
        }
        case 4:
            {
                peek();
                break;

            }
        case 5:
        {
            return 0;
        }
        default:
        {
            continue;
        }
        return 0;
        }




    }



}

