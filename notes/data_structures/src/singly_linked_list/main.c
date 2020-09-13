#include <stdio.h>
#include <stdlib.h>
#define ELEMENT int
#define ELEMENT_NULL 0


/*
 * Singly Linked List
 */
struct LLS_Node {
    ELEMENT data;
    struct LLS_Node* next;
};
typedef struct {
    struct LLS_Node* first;
    struct LLS_Node* last;
} LLS; // LLS = Linked_List_Singly


LLS* lls_create() {
    LLS* lls = (LLS*)malloc(sizeof(LLS));
    lls->first = 0;
    lls->last = 0;
    return lls;
}
void lls_print(LLS* lls) {
    struct LLS_Node* p = lls->first;
    while(p) {
        printf("print: %d\n", p->data);
        p = p->next;
    }
}
void lls_drop(LLS* lls) {
    struct LLS_Node* p = lls->first;
    struct LLS_Node* t;
    while(p) {
        t = p; p = p->next;
        free(t);
    }
    free(lls);
}


void lls_append(LLS* lls, ELEMENT ele) {
    struct LLS_Node*
        lls_node = (struct LLS_Node*)malloc(sizeof(struct LLS_Node));
    lls_node->data = ele;
    lls_node->next = 0;

    if(0 == lls->first) {
        lls->first = lls_node;
        lls->last = lls_node;
    } else {
        lls->last->next = lls_node;
        lls->last = lls_node;
    }
}


int main() {
    LLS* lls = lls_create();
    printf("%d\n", lls->first);

    lls_append(lls, 123);
    lls_append(lls, 456);
    lls_append(lls, 789);
    lls_print(lls);

    lls_drop(lls);
    return 0;
}
