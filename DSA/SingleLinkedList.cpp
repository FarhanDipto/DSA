#include <stdio.h>
#include <bits/stdc++.h>

struct Node{

    int val;
    Node* next;

    Node(int x){
        val = x;
        next = NULL;
    }
};

Node* head = NULL;

void INSERT_F(int x){

    Node* n = new Node(x);
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}

void INSERT_N(int x, int n){

    Node* m = new Node(x);
    Node* temp = head;
    int count = 1;

    while(temp != NULL)
    {
        if(count == n-1)
        {
            m->next = temp->next;
            temp->next = m;
        }
        else
        {
            temp = temp->next;
        }
        count++;
    }
}

void INSERT_L(int x){
     
    Node* n = new Node(x);
    Node* temp = head;

    if(head == NULL)
    {
        head = n;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void DELETE_F(){

    Node* temp = head;
    if(temp->next == NULL)
    {
        head = NULL;
        delete(temp);
    }
    else
    {
        head = temp->next;
        delete(temp);
    }
}

void DELETE_N(int n){

    Node* temp = head;
    if(n == 1)
    {
        head = temp->next;
        delete(temp);
        return;
    }
    for(int i = 1; i < n - 1; i++)
    {
        temp = temp->next;
    }

    Node* temp1 = temp->next;
    temp->next = temp1->next;
    delete(temp1);
}

void DELETE_L(){

    if(head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        Node* temp1 = head;
        Node* temp2;
        while(temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        delete(temp1);
    }
}

int SEARCH(int x){

    Node* temp = head;
    int count = 1;
    while(temp->next != NULL)
    {
        if(temp->val == x)
        {
            return count;
        }
        temp = temp->next;
        count++;
    }
}
   
void PRINT(){

    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int x,n;

    while(true)
    {
        printf("1. Insert First\n2. Insert N\n3. Insert Last\n");
        printf("4. Delete First\n5. Delete N\n6. Delete Last\n");
        printf("7. Print\n8. Search\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("\n Enter value: ");
            scanf("%d",&x);
            INSERT_F(x);
            break;
        case 2:
            printf("\n Enter value, position: ");
            scanf("%d%d",&x,&n);
            INSERT_N(x,n);
            break;
        case 3:
            printf("\n Enter value: ");
            scanf("%d",&x);
            INSERT_L(x);
            break;
        case 4:
            DELETE_F();
            break;
        case 5:
            printf("\n Enter position: ");
            scanf("%d",&n);
            DELETE_N(n);
            break;
        case 6:
            DELETE_L();
            break;
        case 7:
            PRINT();
            break;
        case 8:
            printf("\n Enter value: ");
            scanf("%d",&x);
            printf("Value found at position: %d\n",SEARCH(x));
            break;
        case 9:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
}
