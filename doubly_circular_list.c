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
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        head->prev = newNode;
        newNode->next = head;
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
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        head->prev = newNode;
        newNode->next = head;
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
    else if (head->next == head)
    {
        head = 0;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = head->next;
        head->next->prev = ptr;
        free(head);
        head = ptr->next;
    }
}
void deleteAtEnd()
{
    struct node *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else if (head->next == head)
    {
        head = 0;
        free(ptr);
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
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
                        head=head->next;
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=1;i<position;i++) { 
                            temp=ptr; ptr=ptr->next;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next;
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
    newNode->next = head;
    if (head == 0)
    {
        head = newNode;
        newNode->prev = head;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void display_list()
{
    struct node *ptr;
    ptr = head;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else
    {
        printf("Our List Is...\n");
        while (ptr->next != head)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\t", ptr->data);
    }
}
void copy_list()
{
    struct c_node *newNode, *temp1, *temp2;
    newNode = (struct c_node *)malloc(sizeof(struct c_node));
    temp = newNode;
    newNode->data = head->data;
    printf("\nCopied linkedlist is..\n%d", newNode->data);
    temp1 = head->next;
    while (temp1 != head)
    {
        temp2 = newNode;
        temp2->next = newNode;
        newNode->data = temp1->data;
        printf("\t%d", temp1->data);
        temp1 = temp1->next;
    }
    newNode->next = NULL;
    printf("\nCopied Successfully\n");
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