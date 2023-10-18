#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct Node* insertAtPos(struct Node* head, int data, int pos) {
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;

    while(i != pos) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    
    //Dynamic allocation
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    //Link
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("Linked List before traversal:\n");    
    linkedListTraversal(head);
    
    printf("Linked List after traversal:\n");
    head = insertAtPos(head, 100, 2);
    linkedListTraversal(head);
    return 0;
}