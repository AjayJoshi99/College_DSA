#include <stdio.h>
#include <math.h>
int size = 100;
int stack[100];
int top = -1;
int isEmpty(){
 	 if(top==-1)  return 1; 
  	 else  return 0; 
}
int isFull(){
  	if(top==size-1)  return 1;  
  	else  return 0; 
}
void Push(int x)
{
  	if (top == size - 1)
  	{
    		printf("Stack is overflow\n\n");
  	}
  	else
  	{
    		top += 1;
    		stack[top] = x;
  	}
}

int Pop()
{
  	if ( !isEmpty() )
  	{
    		printf("Stack is underflow\n\n");
  	}
  	else
  	{
    		top -= 1;
    		printf("\nDeleted element is : %d", stack[top + 1]);
  	}
}
void Peep()
{
  	if ( isEmpty())
  	{
    		printf("Stack is empty!!\n\n");
  	}
  	else {
    		printf("Top element is : %d\n\n",stack[top]);
  	}
}
void Display()
{
  	printf("Elements of Stack : ");
  	for (int i = top; i >= 0; i--)
  	{
    	printf("%d ", stack[i]);
  	}
  	printf("\n\n");
}



void Change(int x,int y){
  	int flag =0;
  	for(int i =0; i<=top; i++){
    	if(stack[i]==x){
      	stack[i]=y;
      	flag=1;
   	 }
  }
  if(flag==0){
    printf("Element is not found");
  }
}

int main(void)
{
 	printf("Name : Ajay Joshi\nEnrollment No. : 92201703192");
  	int n,x,y;
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
      			printf("Enter element ");
      			scanf("%d", &x);
      			Push(x);
      			break;
    		case 2:
     			 Pop();
      			break;
    		case 3:
      			Peep();
     			 break;
    		case 4:
      			printf("Enetr element which you want to replace : ");
     			scanf("%d",&x);
      			printf("Enetr element for replacement : ");
      			scanf("%d",&y);
      			Change(x,y);
      			break;
    		case 5:
      			Display();
     			 break;
    		case 6:
      			break;
    		default :
      			printf("Invalid Input.");
    	}
    		printf("\n\n");
  	} while (n != 6);
  return 0;
}
