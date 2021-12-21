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


//#################/////////////////////// singly_list 


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
    }
    else
    {
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
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertAtPos()
{
    int ele, Pos, i = 1;
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Value...\n");
    scanf("%d", &ele);
    newNode->data = ele;
    if (head == 0)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        printf("Enter The Position...\n");
        scanf("%d", &Pos);
        while (i < Pos)
        {
            ptr = temp;
            temp = temp->next;
            i++;
        }
        newNode->next = temp;
        ptr->next = newNode;
    }
}
void deleteAtBegin()
{
    struct node *temp;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void deleteAtEnd()
{
    struct node *temp, *ptr;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else if (head->next == 0)
    {
        temp = head->next;
        head = 0;
        free(temp);
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = 0;
    }
}
void deleteAtPos()
{
    struct node *temp, *ptr;
    int Pos, i = 1;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    else
    {
        temp = head;
        printf("Enter The Position...\n");
        scanf("%d", &Pos);
        while (i < Pos - 1)
        {
            temp = temp->next;
            i++;
        }
        ptr = temp->next;
        temp->next = ptr->next;
        free(ptr);
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
    if (head == 0)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = temp->next;
    }
}
void display_list()
{
    struct node *temp;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    temp = head;
    printf("Our List Is...\n");
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
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

int singly_list()
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
    printf("Enter 10 For Exit This List\n");
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
    case 10:
        printf("Exit\n");
        exit(1);
        break;
    }
    return 0;
}
int main(){
     int ch;

start:

    printf("\n");
    printf("Enter 1 For Singly List\n");
    printf("Enter 2 For Circular List\n");
    printf("Enter 3 For Doubly List\n");
    printf("Enter 4 For Circular Doubly List\n");
    printf("*****************\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        singly_list();
        goto start;
        break;
    case 2:
        circular_list();
        goto start;
        break;
    case 3:
        doubly_list();
        goto start;
        break;
    case 4:
        circular_doubly_list();
        goto start;
        break;
    case 10:
        printf("Exit\n");
        exit(1);
        break;
    return 0;
}}


//#################/////////////////////// Circular_list 


void insertAtBegin1()
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
void insertAtEnd1()
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
void insertAtPos1()
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
            i++;
        }
        NewNode->next = temp;
        PreNode->next = NewNode;
    }
}
void deleteAtBegin1()
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
void deleteAtEnd1()
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
void deleteAtPos1()
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

void create_list1()
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

void display_list1()
{
    struct node *ptr;
    ptr = head;
    if (head == 0)
    {
        printf("No Elements In The List...\n");
    }
    printf("Our List Is...\n");
    while (ptr->next != head)
    {

        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
}

void copy_list1()
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
    printf("Our Copied List Is...\n");
    ptr = head;

    while (ptr->next != head)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\t", ptr->data);
}

circular_list(){

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
    printf("Enter 10 For Exit This List\n");
    printf("*****************\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        create_list1();
        goto start;
        break;
    case 2:
        display_list1();
        goto start;
        break;
    case 3:
        insertAtBegin1();
        goto start;
        break;
    case 4:
        insertAtEnd1();
        goto start;
        break;
    case 5:
        insertAtPos1();
        goto start;
        break;
    case 6:
        deleteAtBegin1();
        goto start;
        break;
    case 7:
        deleteAtEnd1();
        goto start;
        break;
    case 8:
        deleteAtPos1();
        goto start;
        break;
    case 9:
        copy_list1();
        goto start;
        break;
    case 10:
        printf("Exit\n");
        exit(1);
        break;
    }
    return 0;
}


//#################/////////////////////// doubly_list 


void insertAtBegin2()
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
void insertAtEnd2()
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
void insertAtPos2()
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
        printf("Enter The Position..\n");
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
void deleteAtBegin2()
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
void deleteAtEnd2()
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
void deleteAtPos2()
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

void create_list2()
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
void display_list2()
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
void copy_list2()
{
    struct c_node *newNode, *temp1, *temp2;
    newNode = (struct c_node *)malloc(sizeof(struct c_node));
    temp = newNode;
    newNode->data = head->data;
    printf("\nCopied linkedlist is..\n%d", newNode->data);
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

int doubly_list(){
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
    printf("Enter 10 For Exit This List\n");
    printf("*****************\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        create_list2();
        goto start;
        break;
    case 2:
        display_list2();
        goto start;
        break;
    case 3:
        insertAtBegin2();
        goto start;
        break;
    case 4:
        insertAtEnd2();
        goto start;
        break;
    case 5:
        insertAtPos2();
        goto start;
        break;
    case 6:
        deleteAtBegin2();
        goto start;
        break;
    case 7:
        deleteAtEnd2();
        goto start;
        break;
    case 8:
        deleteAtPos2();
        goto start;
        break;
    case 9:
        copy_list2();
        goto start;
        break;
    case 10:
        printf("Exit\n");
        exit(1);
        break;
    }
    return 0;
}

//#################/////////////////////// circular_doubly_list 

void insertAtBegin3()
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
void insertAtEnd3()
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
void insertAtPos3()
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
void deleteAtBegin3()
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
void deleteAtEnd3()
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
void deleteAtPos3()
{
    struct node *temp,*ptr;
        int i,position;
        if(head==NULL)
        {
                printf("No Element In The List\n");
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
                                        printf("\nPosition not Found.\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next;
                        free(ptr);
                }
        }
}

void create_list3()
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
void display_list3()
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
void copy_list3()
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
}

int circular_doubly_list(){
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
    printf("Enter 10 For Exit This List\n");
    printf("*****************\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        create_list3();
        goto start;
        break;
    case 2:
        display_list3();
        goto start;
        break;
    case 3:
        insertAtBegin3();
        goto start;
        break;
    case 4:
        insertAtEnd3();
        goto start;
        break;
    case 5:
        insertAtPos3();
        goto start;
        break;
    case 6:
        deleteAtBegin3();
        goto start;
        break;
    case 7:
        deleteAtEnd3();
        goto start;
        break;
    case 8:
        deleteAtPos3();
        goto start;
        break;
    case 9:
        copy_list3();
        goto start;
        break;
    case 10:
        printf("Exit\n");
        exit(1);
        break;
    }
    return 0;
}

