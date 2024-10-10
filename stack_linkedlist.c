#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *newNode=(struct node *)malloc(sizeof(struct node));
    if (newNode==NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

void display(){
    struct node *temp=top;
    if(top==NULL){
        printf("Stack is empty\n");
    } 
    else{
        printf("Stack elements:");
        while(temp!=NULL) {
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
    } 
    else{
        printf("Top element is %d\n",top->data);
    }
}

void pop(){
    if(top==NULL){
        printf("Stack is empty\n");
    } 
    else{
        struct node *temp=top;
        printf("Popped element:%d\n",top->data);
        top=top->next;
        free(temp);
    }
}

int main(){
    int choice;
    char ch;

    do{
        printf("1 for push, 2 for pop, 3 for peek, 4 for display\n");
        scanf("%d",&choice);
        
        if(choice==1){
            int value;
            printf("Enter value to push: ");
            scanf("%d",&value);
            push(value);
        } 
        else{
            switch (choice) {
                case 2: pop();
                 break;
                case 3: peek(); 
                break;
                case 4: display();
                 break;
                default: printf("Wrong input\n"); 
                break;
            }
        }

        printf("Press y to continue: ");
        getchar(); 
        scanf("%c",&ch);

    }while (ch == 'y'||ch == 'Y');

    return 0;
}