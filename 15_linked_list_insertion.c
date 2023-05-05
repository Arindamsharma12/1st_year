#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linked_list_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// CASE 1:
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// CASE 2:
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index - 1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// CASE 3:
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;

    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

// CASE 4:
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;    

    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));
    third = (struct Node *)malloc(sizeof(struct Node *));
    fourth = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 28;
    third->next = fourth;

    fourth->data = 35;
    fourth->next = NULL;

    printf("Linked list before insertion:\n");
    linked_list_traversal(head);
    // head = insertAtFirst(head, 3);
    // head = insertAtIndex(head, 56, 4);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, second, 27);

    printf("Linked list after insertion:\n");
    linked_list_traversal(head);
    return 0;
}