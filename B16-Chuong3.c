#include <stdio.h>
#include <stdlib.h>
struct QNode {
	int key;
	struct QNode* next;
};
struct Queue {
	struct QNode *front, *rear;
};
struct QNode* newNode(int k){
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}
struct Queue* createQueue(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}
void enQueue(struct Queue* q, int k){
	struct QNode* temp = newNode(k);
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}
void deQueue(struct Queue* q){
	if (q->front == NULL)
		return;
	struct QNode* temp = q->front;
	q->front = q->front->next;
	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
}
int frontelement(struct Queue* q){
   return q->front->key;
}
int rearelement(struct Queue* q){
    return q->rear->key;
}
void display(struct Queue* q){
    if (q->front == NULL){
        printf("Queue is empty");

    }else{
        while (q->front != NULL){
            printf("%d ", q->front->key);
            q->front = q->front->next;
        }  
    }
}
void menu(){
    printf("---------------------------\n");
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Front element");
    printf("\n 4 - Rear element");
    printf("\n 5 - Display");
    printf("\n 6 - Exit");
    printf("\n--------------------------\n");
}
int main(){
	struct Queue* q = createQueue();
    int data,ch,e=0;
    while (1){
        system("cls");
        menu();
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch){
        case 1:
            printf("Enter data : ");
            scanf("%d", &data);
            enQueue(q,data);
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            e = frontelement(q);
            if (e != 0)
                printf("Queue Front : %d \n", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            e = rearelement(q);
            if (e != 0)
                printf("Queue Rear : %d \n", e);
            else
                printf("\n No rear element in Queue as queue is empty");
            break;
        case 5:
            display(q);
            break;
        case 6:
            exit(0);
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
        system("pause");
    }
	return 0;
}



