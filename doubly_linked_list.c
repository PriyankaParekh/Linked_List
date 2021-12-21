#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct c_node
{
    int data;
    struct c_node *next;
    struct c_node *prev;
};
struct c_node *begin = 0;
struct node *head = 0, *temp;

void insertAtBegin()
{
    int ele;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value...\n");
    scanf("%d", &ele);
    newNode->data = ele;
    if (head == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        newNode->data = ele;
        head = newNode;
    }
    else
    {
        newNode->data = ele;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertAtEnd()
{
    int ele;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value...\n");
    scanf("%d", &ele);
    newNode->data = ele;
    newNode->next = 0;
    temp = head;
    if (head == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}
void insertAtPos()
{
int ele, pos, i = 2;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value...\n");
    scanf("%d", &ele);
    newNode->data = ele;
    if (head == 0)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        temp = head;
        printf("Enter The Position...\n");
        scanf("%d", &pos);
        while (i < pos)
        {
            temp = temp->next;
            if (temp == 0)
            {
                printf("There Are Less Than %d Element", pos);
                return;
            }
            i++;
        }
        newNode->data = ele;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        temp->next->prev = newNode;
    }
}
void deleteAtBegin()
{
    struct node *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else if (head->next == 0)
    {
        head = 0;
        free(head);
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
}
void deleteAtEnd()
{
    struct node *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else if (head->next == 0)
    {
        head = 0;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != 0)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
}
void deleteAtPos()
{
        struct node *temp,*ptr;
        int i,position;
        if(head==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("Enter the Position..\n");
                scanf("%d",&position);
                if(position==1)
                {
                        ptr=head;
                        head=head->next ;
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=1;i<position;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        free(ptr);
                }
        }



    }


void create_list()
{
    int ele;
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Ente ther Value...\n");
    scanf("%d", &ele);
    newNode->data = ele;
    if (head == 0)
    {
        head = temp = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
        temp->next = 0;
    }
}
void display_list()
{
    struct node *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    ptr = head;
    printf("Our List Is...\n");
    while (ptr != 0)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}
void copy_list()
{
    struct c_node *newNode, *temp1, *temp2;
    newNode = (struct c_node *)malloc(sizeof(struct c_node));
    temp = newNode;
    newNode->data = head->data;
    printf("\nCopied linkedlist is..\n%d\n", newNode->data);
    temp1 = head->next;
    while (temp1 != NULL)
    {
        temp2 = newNode;
        temp2->next = newNode;
        newNode->data = temp1->data;
        printf("\t%d", temp1->data);
        temp1 = temp1->next;
    }
    newNode->next = NULL;
}

int main()
{
    int ch;

start:

    printf("\n");
    printf("Enter 1 For Create List\n");
    printf("Enter 2 For Display List\n");
    printf("Enter 3 For Insert At Begin\n");
    printf("Enter 4 For Insert At End\n");
    printf("Enter 5 For Insert At Position\n");
    printf("Enter 6 For Delete At Begin\n");
    printf("Enter 7 For Delete At End\n");
    printf("Enter 8 For Delete At Position\n");
    printf("Enter 9 For Copy List\n");
    printf("*****************\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        create_list();
        goto start;
        break;
    case 2:
        display_list();
        goto start;
        break;
    case 3:
        insertAtBegin();
        goto start;
        break;
    case 4:
        insertAtEnd();
        goto start;
        break;
    case 5:
        insertAtPos();
        goto start;
        break;
    case 6:
        deleteAtBegin();
        goto start;
        break;
    case 7:
        deleteAtEnd();
        goto start;
        break;
    case 8:
        deleteAtPos();
        goto start;
        break;
    case 9:
        copy_list();
        goto start;
        break;
    default:
        printf("You Entered Wrong Choice...\n");
        exit(1);
        break;
    }
    return 0;
}