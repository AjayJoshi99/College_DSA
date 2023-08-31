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
        tail = head;
        tail->next = NULL;
    }
    else
    {
        new_node->next = head;
        new_node->data = num;
        head = new_node;
    }
    printf("Element is inserted!!!\n\n");
}
void Display()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("Elements of Stack are :  \n");
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
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("Deleted element of Stack is %d", head->data);
        head = head->next;
        ptr->next = NULL;
    }
}

void Peep()
{
    if (head == NULL)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("Top element of Stack is %d\n", head->data);
    }
}

void Change()
{
    if (head == NULL)
    {
        printf("Stack underflow!!\n");
    }
    else
    {
        int x, y,flag =0;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enetr element which you want to replace : ");
        scanf("%d", &x);
        printf("Enetr element for replacement : ");
        scanf("%d", &y);
        struct node *ptr = head;
        while(ptr){
            if(ptr->data==x){
                ptr->data= y;
                flag = 1;
                break;
            }
            ptr=ptr->next;
        }
        if(flag == 0){
            printf("Element is not found!!!!");
        }
        else{
            printf("Element is changed!!!!");
        }
    }
}

int main(void)
{
    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n");
    int n, x, y;
    printf("....................Stack.......................\n");
    printf("\nEnter 1 for Push an element");
    printf("\nEnter 2 for Pop an element");
    printf("\nEnter 3 for Peep");
    printf("\nEnetr 4 for Change");
    printf("\nEnetr 5 for Displpay stack");
    printf("\nEnetr 6 for Exit\n\n\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &n);
        switch (n)
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
            Change();
            break;
        case 5:
            Display();
            break;
        case 6:
            break;
        default:
            printf("Invalid Input.");
        }
        printf("\n\n");
    } while (n != 6);
    return 0;
}
