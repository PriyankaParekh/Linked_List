#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct c_node
{
    int data;
    struct c_node *next;
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
        head = temp = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
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
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAtPos()
{
    int ele, pos, i = 1;
    struct node *NewNode, *PreNode;
    NewNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value...\n");
    scanf("%d", &ele);
    NewNode->data = ele;
    if (head == 0)
    {
        head = NewNode;
    }
    else
    {
        temp = head;
        printf("Enter The Position...\n");
        scanf("%d", &pos);
        while (i < pos)
        {
            PreNode = temp;
            temp = temp->next;
            if (temp == 0)
            {
                printf("There Are Less Than %d Element", pos);
                return;
            }
            i++;
        }
        NewNode->next = temp;
        PreNode->next = NewNode;
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
        head = NULL;
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
        free(head);
        head = ptr->next;
    }
}
void deleteAtEnd()
{
    struct node *temp, *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else if (head->next == head)
    {
        head = 0;
        free(temp);
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = temp->next;
        free(temp);
    }
}
void deleteAtPos()
{
    struct node *temp, *nextNode;
    int pos, i = 1;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else
    {
        temp = head;
        printf("Enter The Position...\n");
        scanf("%d", &pos);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextNode = temp->next;
        temp->next = nextNode->next;
        free(nextNode);
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
    newNode->next = 0;
    if (temp == 0)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
}

void display_list()
{
    struct node *ptr;
    ptr = head;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    while (ptr->next != head)
    {

        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void copy_list()
{
    struct c_node *newNode, *ptr;

    temp = head;
    while (temp->next != head)
    {
        if (temp == head)
        {
            newNode = (struct c_node *)malloc(sizeof(struct c_node));
            newNode->data = temp->data;
            begin = ptr = newNode;
        }
        else
        {
            newNode = (struct c_node *)malloc(sizeof(struct c_node));
            newNode->data = temp->data;
            ptr->next = newNode;
            ptr = newNode;
        }
        temp = temp->next;
    }
    ptr->next = 0;
    printf("Enter To Show Copied List...\n");
    getch();
    ptr = head;

    while (ptr->next != head)
    {
        printf("\n");
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t%d", ptr->data);
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