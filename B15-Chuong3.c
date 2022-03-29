#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct StackNode {
	int data;
	struct StackNode* next;
};
struct StackNode* newNode(int data){
	struct StackNode* stackNode =(struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}
int isEmpty(struct StackNode* root){//Trả về true nếu ngăn xếp trống, ngược lại là false.
	return !root;
}
void push(struct StackNode** root, int data){//Thêm một mục trong ngăn xếp
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}
int pop(struct StackNode** root){//Loại bỏ một mục khỏi ngăn xếp
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}
int peek(struct StackNode* root){//lay ptu dau tien nhung khong xoa
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}
void output(struct StackNode* root){
    struct StackNode* i;
    printf("so ptu trong mang:");
    for(i=root; i!=NULL; i=i->next){
        printf("%d ",i->data);
    }
    printf("\n");
    printf("\n");
}
int main(){
	struct StackNode* root = NULL;
	push(&root, 5);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);

	push(&root, 3);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 2);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 8);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 9);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
	push(&root, 1);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 7);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 6);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    push(&root, 4);
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
    printf("%d popped from stack\n", pop(&root));
    printf("vi tri dau ngan xep: %d\n",peek(root));
    output(root);
    
	return 0;
}

