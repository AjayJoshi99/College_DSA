#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;
void insert()
{
    int num;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element : ");
    scanf("%d", &num);
    if (head == NULL)
    {
        head = new_node;
        head->data = num;
        tail = head;
        tail->next = NULL;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
        tail->data = num;
        tail->next = NULL;
    }
    printf("Node is inserted!!!\n\n");
}

void display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        printf("Elements of LinkedList is :  \n");
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            if (ptr->next != NULL)
            {
                printf(" --> ");
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
}
void add_begining()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter an element : ");
        scanf("%d", &new_node->data);
        new_node->next = head;
        head = new_node;
        printf("Node is inserted!!!\n\n");
    }
}
void add_end()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter an element : ");
        scanf("%d", &new_node->data);
        tail->next = new_node;
        tail = tail->next;
        tail->next = NULL;
        printf("Node is inserted!!!\n\n");
    }
}
void add_pos()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        int pos;
        printf("\nEnter position  : ");
        scanf("%d", &pos);
        int count = 1, flag = 0;
        struct node *ptr = head;
        if (pos == 1)
        {
            add_begining();
        }
        else
        {
            while (count != pos - 1)
            {
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    printf("Index out of bound ");
                    flag = 1;
                    break;
                }
                count++;
            }
            if (flag == 0 && ptr->next == NULL)
            {
                add_end();
            }
            else if (flag == 0)
            {
                struct node *new_node = (struct node *)malloc(sizeof(struct node));
                printf("\nEnter an element : ");
                scanf("%d", &new_node->data);
                struct node *temp;
                temp = ptr->next;
                ptr->next = new_node;
                new_node->next = temp;
                printf("Node is inserted!!!\n\n");
            }
        }
    }
}
void del_last()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        tail = ptr;
        tail->next = NULL;
        printf("Element is deleted!!!\n");
    }
}
void del_first()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        struct node *temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        printf("Element is deleted!!!\n");
    }
}
void del_pos()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        int pos, flag = 0;
        printf("Enter element position  to delete :");
        scanf("%d", &pos);
        if (pos == 1)
        {
            del_first();
        }
        else
        {
            pos-=2;
            struct node *ptr = head;
            while (pos--)
            {
                ptr = ptr->next;
                if (ptr->next ==  NULL)
                {
                    printf("Index out of bound ");
                    flag = 1;
                    break;
                }
            }
            if (flag != 1 )
            {
                ptr->next = ptr->next->next;
                printf("Element is deleted!!!\n");
            }
        }
    }
}
void del_all()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        int x;
        printf("Enter an Element :");
        scanf("%d", &x);
       while(head != NULL && head->data==x){
        head=head->next;
       }
       struct node *pre, *curr;
       curr = head;
       pre = NULL;
       while(curr->next != NULL){
        if(curr->data == x){
            pre->next = curr->next;
        }
        else{
            pre = curr;
        }
        curr= curr->next; 
       }
       if(tail->data == x){
        del_last();
       }
       
    }
}
void sort()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        struct node *i = head;
        while (i->next != NULL)
        {
            struct node *j = i->next;
            while (j != NULL)
            {
                if (i->data > j->data)
                {
                    int temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
        printf("LinkedList is sorted!!!\n");
    }
}
void ins_srt()
{
    if (head == NULL)
    {
        printf("LinkedList is  Empty\n");
    }
    else
    {
        int num;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter an element : ");
        scanf("%d", &num);
        new_node->data = num;
        if (num < head->data)
        {
            new_node->next = head;
            head = new_node;
        }
        else if (num > tail->data)
        {
            tail->next = new_node;
            tail = tail->next;
            tail->next = NULL;
            
        }
        else
        {
            struct node *ptr = head;
            while (ptr->next != NULL)
            {
                if (ptr->next->data > num)
                {
                    struct node *temp;
                    temp = ptr->next;
                    ptr->next = new_node;
                    new_node->next = temp;
                    break;
                }
                ptr = ptr->next;
            }
        }
        printf("Node is inserted!!!\n\n");
    }
}

int main()
{
    printf("\nName  : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    int choice;
    printf("..................................Singly linkedlist............................. \n");
     printf("\n\nEnter 1 for insertion in exsisting/new LinkedList  : \n");
        printf("Enter 2 for Display  LinkedList  : \n");
        printf("Enter 3 for insert at begining of LinkedList  : \n");
        printf("Enter 4 for insert at end of LinkedList  : \n");
        printf("Enter 5 for insert at given position of LinkedList  : \n");
        printf("Enter 6 for delete last node of LinkedList  : \n");
        printf("Enter 7 for delete first node of LinkedList  : \n");
        printf("Enter 8 for delete node of given position of LinkedList  : \n");
        printf("Enter 9 for delete all occurence of element :\n");
        printf("Enter 10 for sorting :\n");
        printf("Enter 11 for insert element in sorted LinkedList :\n");
        printf("Enter 12 for  exit : \n");
        
    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            add_begining();
            break;
        case 4:
            add_end();
            break;
        case 5:
            add_pos();
            break;
        case 6:
            del_last();
            break;
        case 7:
            del_first();
            break;
        case 8:
            del_pos();
            break;
        case 9:
            del_all();
            break;
        case 10:
            sort();
            break;
        case 11:
            ins_srt();
            break;
        case 12:
            printf("\n\nThank you !!!\n");
            break;
        default:
            printf("Invalid choice !!!!!\n");
        }
    } while (choice != 12);
}