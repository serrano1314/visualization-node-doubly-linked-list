#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void add_last(int);
void add_first(int);
void insert(int, int);
void delete(int);
void reverse(void);
int length(void);
void display(void);
void resetColor(){
	printf("\033[0m");
}
void setColor(int txColor,int bgColor){
	printf("\033[%d;%dm",bgColor+40,txColor+30);
}
void clrscr(void){
    system("cls");
}
struct node {
    int data;
    struct node *llink;
    struct node *rlink;
};
struct node *root = NULL;
int main(void){
    int nodes_count;
    int i=1;
    int data,loc;
    printf("\n\t THIS PROGRAM IS VISUALIZATION OF NODES USING DOUBLY LINKEDLIST\n");
    printf("ENTER THE NUMBER OF NODES YOU WANT: ");
    scanf("%d",&nodes_count);
    printf("ENTER DATA FOR %d NODES... \n",nodes_count);
    while(nodes_count--){
        printf("NODE[%d]: ",i++);
        scanf("%d",&data);
        add_last(data);
    }
    while(1){
        clrscr();
        display();
        printf("\n[1]ADD NODE AT THE LAST\n[2]ADD NODE AT THE FIRST \n[3]INSERT NODE\n[4]DELETE NODE \n[5]REVERSE LIST\n[X]EXIT\n");
        switch (getch())
        {
        case '1':
            printf("(ADDING AT THE LAST)ENTER DATA: ");
            scanf("%d",&data);
            add_last(data);
            break;
        case '2':
            printf("(ADDING AT THE FIRST)ENTER DATA: ");
            scanf("%d",&data);
            add_first(data);
            break;
        case '3':
            printf("(INSERTING)ENTER LOCATION: ");
            scanf("%d",&loc);
            printf("(INSERTING)ENTER DATA: ");
            scanf("%d",&data);
            insert(loc-1,data);
            break;
        case '4':
            printf("(DELETING NODE)ENTER LOCATION: ");
            scanf("%d",&loc);
            delete(loc);
            break;
        case '5':
            printf("REVERSING... Press any key...");
            reverse();
            getch();
            break;
        case 'x':
        case 'X':
            exit(0);
        default:
            printf("INVALID CHOICE\n");
            getch();
            break;
        }        
    }
    return 0;
}
/*user-define functions*/
void add_last(int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = NULL;
    if(root == NULL){
        root = temp;
    }else{
        struct node *p;
        p = root;
        while(p->rlink!=NULL){
            p=p->rlink;
        }
        temp->llink = p;
        p->rlink = temp;
    }

}
void add_first(int data){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->llink = NULL;
    temp->rlink = root;
    root->llink;
    root->llink = temp;
    root = temp;

}
void insert(int loc, int data){
    struct node *temp;
    int i=1, len = length();
    if(loc>len){
        printf("INVALID LOCATION");
        getch();
    }
    else if(loc == 0){
        add_first(data);
    }
    else if(loc == len){
        add_last(data);
    }else{
        struct node *p = root;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->llink = NULL;
        temp->rlink = NULL;
        while(i<loc){
            p=p->rlink;
            i++;
        }
        temp->rlink=p->rlink;
        p->rlink->llink=temp;
        temp->llink=p;
        p->rlink=temp;
    }
}
void reverse(){
    struct node *p, *q;
    int i=0,len=length(),temp;
    p = root;
    q = root;
    while(q->rlink!=NULL){
        q=q->rlink;
    }
    while(i<len/2){
        temp = p->data;
        p->data = q->data;
        q->data  = temp;
        p = p->rlink;
        q = q->llink;
        i++;
    }
}
void display(void){
    struct node *p;
    p = root;
    if(p==NULL){
        printf("[EMPTY LIST]\n");
    }else{
        printf("\t\tDOUBLE LINKED LIST NODES VISUALIZATION\n\t");
        while(p!=NULL){
            setColor(8,4);
            printf("[ %d ]",p->data);
            resetColor();
            p=p->rlink;
            if(p!=NULL)
                printf(" <--> ");
        }
        printf("\n");
    }
}
int length(void){
    struct node *p;
    p = root;
    int cnt=0;
    while(p!=NULL){
        cnt++;
        p=p->rlink;
    }
    return cnt;
}
