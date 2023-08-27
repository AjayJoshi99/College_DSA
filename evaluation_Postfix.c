#include <stdio.h>
#include<string.h>
int top = -1;
int arr[50];
int length = 0;

void push(int x)
{
    top += 1;
    arr[top] = x;
    length++;
}

int pop()
{
    if (top == -1)
        return 0;
    top -= 1;
    length--;
    return arr[top + 1];
}

int main()
{
    printf("\nName  : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    char ex[100];
    int len,flag = 0,i=0,a,b,ans;
    printf("Enter expression  : ");
    gets(ex);
    /**printf("Enter expression size : ");
    scanf("%d", &len);
    printf("Enter expression : \n");
    for(i =0; i<len; i++){
        scanf("%s", &ex[i]);
    }
    **/

    for (int i = 0; i <100; i++)
    {
        if(ex[i]=='\0'){
            break;
        }
        if (ex[i] != '+' && ex[i] != '-' && ex[i] != '*' && ex[i] != '/' && ex[i] != '^' && ex[i] != '%')
        {
            push(ex[i]-48);   
        }
        else
        {
            if ( length < 2)
            {
                printf("Invalid expression!!");
                flag = 1;
                break;
            }
            switch (ex[i])
            {
            case '+':
                a = pop();
                b = pop();
                push(a+b);
                break;
            case '-':
                a = pop();
                b = pop();
                push(a - b);
                break;
            case '*':
                a = pop();
                b = pop();
                push(a * b);
                break;
            case '/':
                a = pop();
                b = pop();
                push(b/a);
                break;
            case '^':
                a = pop();
                b = pop();
                ans = 1;
                for (int j = 1; j <= b; j++)
                {
                    ans *= a;
                }
                push(ans);
                break;
            case '%':
                a = pop();
                b = pop();
                push(b%a);
                break;
            }
        }
    }
    if (flag == 0)
    {
        printf("Answer of given expression is : %d ", pop());
        
    }
}
