#include<stdio.h>
int size = 3;
int queue[3];
int front = 0;
int rear = -1;
int length = 0;

void enqueue(int x)
{
    if (length == size)
    {
        printf("\nQueue Overflow\n");
    }
    else
    {
        rear = (rear + 1) % (size);
        queue[rear] = x;
        length++;
    }
}
void dequeue()
{
    if (length == 0)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        if (front == size - 1)
        {
            printf("\nDeleted element is : %d\n", queue[front]);
            length--;
            if (rear != size - 1)
            {
                front = 0;
            }
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
}
void peep()
{

    if (length == 0)
        printf("Queue is empty!");
    else
    {
        printf("\nTop element is : %d\n", queue[rear]);
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
        if (i <= rear)
        {
            while (i <= rear)
            {
                printf("%d ", queue[i]);
                i++;
            }
        }
        else
        {
            while (i < size)
            {
                printf("%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                printf("%d ", queue[i]);
                i++;
            }
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
        int i = front;
        if (i <= rear)
        {
            while (i <= rear)
            {
                if (queue[i] == x)
                {
                    queue[i] = y;
                    flag = 1;
                    break;
                }
                i++;
            }
        }
        else
        {
            while (i <= size)
            {
                if (queue[i] == x)
                {
                    queue[i] = y;
                    flag = 1;
                    break;
                }
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                if (queue[i] == x)
                {
                    queue[i] = y;
                    flag = 1;
                    break;
                }
                i++;
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
    printf("\nName  : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
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
            if (length == size)
            {
                printf("\nQueue Overflow\n");
            }
            else
            {
                printf("\nEnter an element : ");
                scanf("%d", &x);
                enqueue(x);
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peep();
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