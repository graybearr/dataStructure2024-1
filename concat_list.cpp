#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다.
    element data;
    struct ListNode* link;
} ListNode;

// 맨 앞에 노드 삽입
ListNode* insert_first(ListNode* head, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode* head, ListNode* pre, element value){
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

// 맨 앞의 노드를 삭제
ListNode* remove_first(ListNode* head){
    ListNode* removed;
    if (head == NULL)
        return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* remove(ListNode* head, ListNode* pre){
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode* concat_list(ListNode* head1, ListNode* head2){
    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head2;
    else {
        ListNode* p;
        p = head1;
        while (p -> link != NULL)
            p = p->link;
        p -> link = head2;
        return head1;
    }
}

void print_list(ListNode* head){
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

int main(){
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    ListNode* head3 = NULL;

    for (int i = 3; i >= 1; i--) {
        head1 = insert_first(head1, i * 10);
    }
    print_list(head1);
    for (int i = 6; i >= 4; i--) {
        head2 = insert_first(head2, i * 10);
    }
    print_list(head2);
    head3 = concat_list(head1,head2);
    print_list(head3);
    return 0;
}