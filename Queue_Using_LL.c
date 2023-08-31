#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;
void Push()
{
    int num;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter an element : ");
    scanf("%d", &num);
    if (head == NULL)
    {
        head = new_node;
        head->data = num;
        tail = new_node;
        tail->next = NULL;
    }
    else
    {
        tail->next = new_node;
        new_node->data = num;
        tail = tail->next;
        tail->next = NULL;
    }
    printf("Element is inserted!!!\n\n");
}

void Display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Queue Underflow!!\n");
    }
    else
    {
        printf("Elements of Queue are :  \n");
        while (ptr != NULL)
        {
            printf("%d  ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void Pop()
{
    if (head == NULL)
    {
        printf("Queue underflow!!!\n");
    }
    else
    {
        
            printf("Element  %d  is deleted.\n", head->data);
            head = head->next;

    }
}

void Peep()
{
    if (head == NULL)
    {
        printf("Queue Underflow!!\n");
    }
    else
    {
        printf("Top element of Stack is    :   %d\n", tail->data);
    }
}

void Change()
{
    if (head == NULL)
    {
        printf("Queue underflow!!\n");
    }
    else
    {
        int x, y, flag = 0;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enetr element which you want to replace :  ");
        scanf("%d", &x);
        printf("Enetr element for replacement : ");
        scanf("%d", &y);
        struct node *ptr = head;
        while (ptr)
        {
            if (ptr->data == x)
            {
                ptr->data = y;
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag == 0)
        {
            printf("Element is not found!!!!\n");
        }
        else
        {
            printf("Element is changed!!!!\n");
        }
    }
}

int main()
{
    int choice, x, y;
    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("....................Queue.......................\n");
    do
    {
        printf("\nEnter 1 for insertion : ");
        printf("\nEnter 2 for deletation of an element :");
        printf("\nEnter 3 for top element : ");
        printf("\nEnter 4 for diaplay a queue");
        printf("\nEnter 5 for changing an element: ");
        printf("\nEnter 6 for Exit : \n");
        printf("Choice   : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peep();
            break;
        case 4:
            Display();
            break;
        case 5:
            Change();
            break;
        case 6:
            break;
        default:
            printf("Enter valid choice\n");
        }
    } while (choice != 6);

    return 0;
}