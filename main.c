#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
void append();
void display();
void add_begin();
void add_between();
void delete_begin();
void delete_between();
void delete_end();
void modify();
void search();
struct node* root=NULL;
int length=0;

void main()
{
    int ch;
    while(1)
    {
        printf("\n1. Append \n2. Add at the beginning \n3. Add at location \n4. Display \n5. Delete at begin \n6. Delete at location \n7. Delete at end \n8. Modify \n9. Search\n10. Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:length++;
                append();

                break;

            case 2:length++;
                add_begin();

                break;
            case 3:length++;
                add_between();

                break;
            case 4: display();
                break;
            case 5:length--;
                delete_begin();

                break;
            case 6:length--;
                delete_between();

                break;
            case 7:
                length--;
                delete_end();

                break;
            case 8: modify();
                break;
            case 9: search();
                break;
            case 10: exit(0);
        }
    }
}

void append(){
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    // temp->data=0;
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root == NULL)
    {
        root=temp;
    }

    else
    {
        struct node *p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

void add_begin()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    // temp->data=0;
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    temp->link=root;
    root=temp;
}

void add_between()
{
    struct node* temp;
    struct node* p;
    p=root;
    int loc,i=2;
    temp=(struct node*)malloc(sizeof(struct node));
    // temp->data=0;
    printf("Enter the data\n");
    scanf("%d",&temp->data);

    printf("Enter Location\n");
    scanf("%d",&loc);
    temp->link=NULL;
    while(i<loc)
    {
        p=p->link;
        i++;
    }
    temp->link=p->link;
    p->link=temp;


}

void delete_begin()
{
    root=root->link;
}

void delete_between()
{
    int loc,i=1;
    struct node* p;
    struct node* q;
    p=root;
    q=root;
    printf("Enter the location where you want to delete\n");
    scanf("%d",&loc);
    while(i<loc-1)
    {
        p=p->link;
        i++;
    }
    q=p->link;
    p->link=q->link;
    q->link=NULL;
    free(q);

}

void delete_end()
{
    int loc,i=1;
    struct node* p;
    p=root;
    loc=length;
    while(i<loc)
    {
        p=p->link;
        i++;
    }

    p->link=NULL;
}

void modify()
{
    int loc,i=1;
    struct node* p;
    struct node* q;
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));

    printf("Enter the location where you want to modify\n");
    scanf("%d",&loc);
    printf("Enter the data\n");
    scanf("%d",&temp->data);
    p=root;
    while(i<loc-1)
    {
        p=p->link;
        i++;
    }
    q=p->link;
    p->link=temp;
    temp->link=q->link;
    free(q);

}
void display()
{
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty\n");
    }
    else {
        printf("%d->", temp->data);
        while (temp->link != NULL) {
            temp = temp->link;
            printf("%d-> ", temp->data);
        }
    }
    printf("length= %d",length);

}

void search()
{
    struct node* p;
    int val;
    int i,flag=0;
    p=root;
    printf("Enter the value you want to search\n");
    scanf("%d",&val);
    for(i=0;i<length-1;i++) {
        p = p->link;
        if (p->data == val) {
            printf("Searched value is found at location %d", i + 1);
            flag = 1;
        }
    }
    if(flag==0)
        printf("Key element not found\n");

}
