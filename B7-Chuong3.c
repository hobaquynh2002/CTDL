#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int info;
    struct Node *next;
}Node;
Node * insertEnd(struct Node * head,int data){
    Node * temp=head,*ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->info=data;
    ptr->next=NULL;
    if(temp==NULL){
        head=ptr;
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
    return head;
}
//2 3 4 5
void removeDupes(Node *head){
	Node *p1, *p2, *dup;
    p1 = head;
    while (p1 != NULL && p1->next != NULL) {
        p2 = p1;
        while (p2->next != NULL) {
            if (p1->info == p2->next->info) {
                dup = p2->next;
                p2->next = p2->next->next;
                free(dup);
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
}
display(Node *head){
    Node *i;
    for(i=head; i!= NULL; i=i->next){
        printf("%d\n",i->info);
    }  
}
int main(){
    Node * head=NULL;
    int n,data,arr[100],k=0;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&data);
        head=insertEnd(head,data);//chèn vào cuối
    }
    removeDupes(head);
    printf("sau khi xoa cac ptu trung:\n");
    display(head);
    return 0;
}

