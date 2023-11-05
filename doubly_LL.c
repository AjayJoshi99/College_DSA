#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *head = NULL, *tail = NULL;

void insert_end()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int n;
    printf("Enter element  : ");
    scanf("%d", &n);
    new_node->data = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (new_node == NULL)
    {
        printf("Memory overflow\n");
    }
    else if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

void insert_begin()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    int n;
    printf("Enter element  : ");
    scanf("%d", &n);
    new_node->data = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (new_node == NULL)
        printf("Memory overflow!!!!!\n\n");
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void delete_last()
{
    if (head == NULL)
    {
        printf("List underflow!!\n\n");
    }
    else
    {
        struct node *ptr = head;
        if (ptr->next == NULL)
        {
            printf("Deleted element is : %d\n\n", ptr->data);
            head = NULL;
            ptr = NULL;
        }
        else
        {
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            printf("Deleted element is : %d\n\n", ptr->next->data);
            ptr->next = NULL;
        }
    }
}

void delete_pos()
{
    if (head == NULL)
    {
        printf("\nList underflow!!\n\n");
    }
    else
    {
        int pos;
        printf("\nEnter position to delete an element before position  :  \n");
        scanf("%d", &pos);
        if (pos == 0 || pos == 1)
        {
            printf("\nInvalid position !!!\n\n");
        }
        else  if(pos==2){
            struct node *ptr = head;
            printf("\nDeleted element is : %d\n\n", ptr->data);
            head=head->next;
        }
        else
        {
            struct node *ptr = head;
            pos -= 3;
            while (pos--)
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                printf("\nInvalid position !!!\n\n");
            }
            else
            {
                struct node *temp = NULL;
                temp = ptr;
                printf("Deleted element is : %d\n\n", ptr->next->data);
                ptr->next = ptr->next->next;
                if(ptr->next != NULL)
                    ptr->next->prev = temp;
            }
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList underflow!!\n\n");
    }
    else
    {
        struct node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->next == NULL)
                printf("%d", ptr->data);
            else
                printf("%d <-->  ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    do
    {
        printf("\nEnter 1 for insert an element at end of list  : \n");
        printf("Enter 2 for display  :\n");
        printf("Enter 3 for insert an element at begin of list  : \n");
        printf("Enetr 4 for delete last element :\n");
        printf("Enter 5 for delete element before position  : \n");
        printf("enter 6 for exit  : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_end();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_begin();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            delete_pos();
            break;
        case 6:
            printf("\nThank you!!!\n\n");
            break;
        default:
            printf("\nInvalid choice !!!!\n\n");
        }

    } while (choice != 6);
}