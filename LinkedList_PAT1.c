#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

struct node{
    int data;
    struct node* next;
};

struct node* head = NULL;


void insertbegin(int value){
    struct node* newnode= (struct node*)(malloc(sizeof(struct node)));
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}

void insertend(int value){
    struct node* newnode=(struct node*)(malloc(sizeof(struct node)));
    newnode->data=value;
    newnode->next=0; //since the last next is always 0

    if (head==NULL){
        head=newnode;
        return;
    }
                // temp=head → [10 | next] → [20 | next] → [30 | NULL]
    struct node* temp=head;
    while(temp->next !=NULL){
        temp=temp->next;
    }

    temp->next=newnode;     
    
                // head → [10 | next] → [20 | next] → [30 | next] → [40 | NULL]

}
void insertmiddle(int value, int pos){
    struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
    newnode->data=value;

    struct node* temp=head;

    for (int i=1; i<pos && temp !=0;i++){
        temp=temp->next;
    }

    if (head==NULL || temp==NULL){
        printf("element not found laude!");
        free(newnode);
        return;
    }

    newnode->next = temp->next;   // next of the newnode is shifting to the next node of temp
    temp->next = newnode;  // make the next of temp point to newnode 


}

void deletebegin(){
    if (head==NULL){
        printf("empty list laude");
    }

    struct node* temp=head;
    head=head->next; // moves or cs, points the head to the next of head
    free(temp);
}

void deleteend(){
    if (head==NULL){
        printf("empty list laude");
    }

    if (head->next==NULL){
        free(head);
        head=NULL;
        return;
    }

    struct node* temp=head;
    while(temp->next->next !=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}
void deletemiddle(int pos){

    //if list is empty
    if (head==NULL){
        printf("list is empty laude");
        return;
    }

    struct node* temp=head;

    // if head is the only element
    if (pos==1){
        head=head->next;
        free(temp);
        return;
    }
    //if position is invalid
    if (temp==NULL && temp->next==NULL){
        printf("position not found laude!");
        return;
    }
    // list traversal to the node before insertion pos
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
}

int search(int value){

    struct node* temp=head;
    int pos=1;

    while(temp !=NULL){
        if (temp->data==value){
            return pos;
        }

        temp=temp->next;
        pos++;

    }

    return -1;
}

void display(){
    

    if (head==NULL){
        printf("list is empty laude");
    }

    struct node* temp= head;

    while (temp!= NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL \n");


}
int main(){
    insertbegin(10);
    insertbegin(20);
    insertend(40);
    insertmiddle(69,1);

    

    display();

    deletebegin();
    deleteend();
    deletemiddle(2);

    printf("list after deletion: ");
    display();

    int pos=40;
    if (pos != -1){
        printf("element is found at %d position", pos);
    } else printf ("no element found lol");
    return 0;

}




