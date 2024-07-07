#include<stdio.h>

struct Node{

    int data;
    Node* next;
};
Node* front=NULL;
Node* rear = NULL;

void enqueue(int x){
    
    Node* newnode = new Node();
    newnode->data=x;
    newnode->next=NULL;

    if(front==NULL && rear == NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue (){

    Node* temp = front;
    if(front == 0 && rear == 0){

        printf("Underflow Condition");
    }
    else{
        
        front=temp->next;
        delete(temp);
    }
}

void display(){

    Node* temp=front;

    if(front ==0 && rear == 0){

        printf("\nThe list is empty!");
    }
    else{

        printf("\n The List is : ");
        while(temp!=NULL){

            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void peek(){

    if(front==0 && rear == 0){
        printf("The list is empty!");
    }
    else{
        printf("\n The first element is : %d",front->data);
    }
}

int main (){

    while(true){

        int x,ch;
        printf("\n\n1.Enqueue \n2.Dequeue \n3.Display \n4.Peek \n5.Exit");
        printf("Enter your choice : ");
        scanf("%d",&ch);

        switch(ch){

        case 1:
        {
            printf("Enter a value : ");
            scanf("%d",&x);
            enqueue(x);
            break;
        }
        case 2:
        {
            dequeue();
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
            printf("\nInvalid Input!");
            continue;
        }
        }
    }
    return 0;
}
