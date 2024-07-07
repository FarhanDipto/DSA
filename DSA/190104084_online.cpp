#include <stdio.h>
#include <bits/stdc++.h>

struct Node{

    int val;
    Node* next;
};

int maxPos(struct Node* h1)
{
    Node* temp = h1;
    int max, count = 0, pos;
    max = h1->val;

    do
    {
        count++;
        if(temp->val>max){
            max = temp->val;
            pos = count;
        }
        if(temp->next == NULL) break;
        temp = temp->next;
    } while (true);

    return pos;
    
}

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d ", n->val);
        n = n->next;
    }
}

int main(){

    Node* h1 = new Node();
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();


    h1->next = first;

    first->val = 5;
    first->next = second;

    second->val = 4;
    second->next = third;

    third->val = 7;
    third->next = fourth;

    fourth->val = 2;
    fourth->next = NULL;

    printList(first);
    printf("\nMax value pos: %d", maxPos(first));



}