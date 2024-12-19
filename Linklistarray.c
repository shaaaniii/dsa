#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];   
    int next[MAX_SIZE];   
    int head;             
    int free;             
} LinkedList;
void initList(LinkedList *list) {
    list->head = -1;
    list->free = 0;  
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->next[i] = i + 1; 
    }
    list->next[MAX_SIZE - 1] = -1;
}
void insert(LinkedList *list, int value) {
    if (list->free == -1) {
        printf("List is full!\n");
        return;
    }
    int newIndex = list->free; 
    list->free = list->next[newIndex]; 
    list->data[newIndex] = value; 
    list->next[newIndex] = -1; 
    if (list->head == -1) {
        list->head = newIndex;
    } else {
        int current = list->head;
        while (list->next[current] != -1) {
            current = list->next[current];
        }
        list->next[current] = newIndex; }
}
void display(LinkedList *list) {
    int current = list->head;
    while (current != -1) {
        printf("%d -> ", list->data[current]);
        current = list->next[current];
    }
    printf("NULL\n");
}
void freeList(LinkedList *list) {
    initList(list);
}
int main() {
    LinkedList list;
    initList(&list);
    int value;
    char choice;
    do {
        printf("Enter a value to insert into the linked list: ");
        scanf("%d", &value);
        insert(&list, value);
        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice); 
    } while (choice == 'y' || choice == 'Y');
    printf("Linked List: ");
    display(&list);
    freeList(&list);
    return 0;
}