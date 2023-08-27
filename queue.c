#include <stdio.h>
int queue[100];
int front = 0;
int rear = -1;
int length = 0;

void insert(int x)
{
    if (rear == 100)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        queue[++rear] = x;
        length++;
    }
}
int Delete()
{
    if (length == 0)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nDeleted element is : %d\n", queue[front++]);
        length--;
        if (length == 0)
        {
            front = 0;
            rear = -1;
        }
    }
}
int peep()
{

    if (length == 0)
        printf("Queue is empty!");
    else
    {
        return queue[rear];
    }
}
void display()
{
    if (length == 0)
    {
        printf("Queue is Underflow!!\n");
    }
    else
    {
        int i = front;
        while (i <= rear)
        {
            printf("%d ", queue[i]);
            i++;
        }
        printf("\n");
    }
}

void change(int x, int y)
{
    if (length == 0)
    {
        printf("Queue is Underflow!!\n");
    }
    else
    {
        int flag = 0;
        for (int i = rear; i >= front; i--)
        {
            if (queue[i] == x)
            {
                queue[i] = y;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("Element is not found!!!!\n\n");
        }
        else
        {
            printf("Element is changed\n");
        }
    }
}
int main()
{
    int choice, x, y;
    do
    {
        printf("\nEnter 1 for insertion : ");
        printf("\nEnter 2 for deletation of an element.");
        printf("\nEnter 3 for top element : ");
        printf("\nEnter 4 for diaplay a queue");
        printf("\nEnter 5 for changing an element: ");
        printf("\nEnter 6 for Exit : \n");
        printf("Choice   : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter an element : ");
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            Delete();
            break;
        case 3:
            printf("\nTop element is : %d\n", peep());
            break;
        case 4:
            printf("Element of Queue are : \n");
            display();
            break;
        case 5:
            printf("Which element you want to replace: ");
            scanf("%d", &x);
            printf("Enter element for replacement :");
            scanf("%d", &y);
            change(x, y);
            break;
        case 6:
            break;
        default:
            printf("Enter valid choice");
        }
    } while (choice != 6);

    return 0;
}
