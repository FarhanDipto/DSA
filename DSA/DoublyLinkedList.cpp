#include <stdio.h>
#include <bits/stdc++.h>

struct Node{

    int val;
    Node* prev;
    Node* next;

    Node(int x){

        prev = NULL;
        val = x;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void INSERT_F(int x){

    Node* node = new Node(x);
    node->next = head;
    if (head != NULL){
        
        head->prev = node;
    }
    head = node;
}

void INSERT_N(int x, int n)
{
    Node* node = new Node(x);
    Node* temp = head;
    int count = 1;

    while(temp != NULL)
    {
        if (count == n - 1)
        {
            node->next = temp->next;
            temp->next = node;
            node->prev = temp;
        }
        else
        {
            temp = temp->next;
        }
        count++;
    }
}

void INSERT_L(int x)
{
    Node* node = new Node(x);

    if (head == NULL)
    {
        head = node;
        return;
    }
    else
    {
        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void DELETE_F()
{
    Node* temp = head;

    if (head->next == NULL)
    {
        head = NULL;
        delete(head);
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }
}

void DELETE_N(int n)
{
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

void DELETE_L()
{
    Node* temp = head;

    if (head->next == NULL)
    {
        head = NULL;
        delete(head);
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete(temp);
    }
}

int SEARCH(int x)
{
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

void PRINT()
{
    Node* temp = head;
    while(temp != tail)
    {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void PRINT_REV()
{
    tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    while(tail != head)
    {
        printf("%d\n", tail->val);
        tail = tail->prev;
    }
    printf("%d\n", tail->val);
}

int main()
{
    int x,n;

    while(true)
    {
        printf("1. Insert First\n2. Insert N\n3. Insert Last\n");
        printf("4. Delete First\n5. Delete N\n6. Delete Last\n");
        printf("7. Print\n8. Reverse Print\n9. Search\n");
        printf("10. Exit\n");
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
            PRINT_REV();
            break;
        case 9:
            printf("\n Enter value: ");
            scanf("%d",&x);
            printf("Value found at position: %d",SEARCH(x));
            break;
        case 10:
            return 0;
            break;
        default:
            continue;
        }
    }

    return 0;
}
