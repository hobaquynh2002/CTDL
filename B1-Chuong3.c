#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int Inf;
    struct Node *next;
}Node;
Node * insertEnd(struct Node * head,int data){
    Node * temp=head,*ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->Inf=data;
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
void delete(Node **head,int data){
    struct Node *temp = *head, *prev;
	if (temp != NULL && temp->Inf == data) {
		*head = temp->next; // Changed head
		free(temp); // free old head
		return;
	}
	while (temp != NULL && temp->Inf != data) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	prev->next = temp->next;
	free(temp); 
}
display(Node *head){
    Node *i;
    for(i=head; i!= NULL; i=i->next){
        printf("%d\n",i->Inf);
    }  
}
int main(){
    Node * head=NULL,*i;
    int n,data,arr[100],k=0;
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&data);
        head=insertEnd(head,data);//chèn vào cuối
    }
    for(i=head; i!= NULL; i=i->next){//duyệt qua các phần tử ,dùng 1 mảng phụ để lưu các số chắn
        if (i->Inf%2==0){
            arr[k]=i->Inf;
            k++;
        }
    }
    int j;
    for(j=0; j<k;j++){
        delete(&head,arr[j]);//duyệt qua mảng phụ và xóa các giá trị chắn
    }
    printf("sau khi xoa:\n");
    display(head);
    return 0;
}

