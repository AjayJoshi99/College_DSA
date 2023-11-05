#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(struct node *ptr, int data)
{
    if (ptr->info > data)
    {
        if (ptr->left != NULL)
        {
            insert(ptr->left, data);
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->info = data;
            new->left = NULL;
            new->right = NULL;
            ptr->left = new;
        }
    }
    else if (ptr->info < data)
    {
        if (ptr->right != NULL)
        {
            insert(ptr->right, data);
        }
        else
        {
            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->info = data;
            new->left = NULL;
            new->right = NULL;
            ptr->right = new;
        }
    }
    else
    {
        printf("%d is already available!!", data);
    }
    printf("Element is inserted!!!\n\n");
}


struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    if (data < root->info)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->info)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *current = root->right;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        root->info = current->info;
        root->right = deleteNode(root->right, current->info);
    }
    return root;
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    if (ptr->left)
    {
        inorder(ptr->left);
    }
    printf("%d  ", ptr->info);
    if (ptr->right)
    {
        inorder(ptr->right);
    }
}

void preorder(struct node *ptr)
{
    printf("%d  ", ptr->info);
    if (ptr->left)
    {
        preorder(ptr->left);
    }
    if (ptr->right)
    {
        preorder(ptr->right);
    }
}

void postorder(struct node *ptr)
{
    if (ptr->left)
    {
        postorder(ptr->left);
    }
    if (ptr->right)
    {
        postorder(ptr->right);
    }
    printf("%d  ", ptr->info);
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            printf("Root->:  ");
        else
        {
            for (i = 0; i < level; i++)
                printf("       ");
        }
        printf("%d", ptr->info);
        display(ptr->left, level + 1);
    }
}

void main()
{
    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    int choice,data;

    printf("\n\nOperations on BST\n\n");
    printf("1.  Insert Element\n ");
    printf("2.  Delete Element\n ");
    printf("3.  Inorder Traversal\n ");
    printf("4.  Preorder Traversal\n ");
    printf("5.  Postorder Traversal\n ");
    printf("6.  Display\n ");
    printf("7.  Quit\n ");

    while (1)
    {
        printf("\nEnter your choice : \n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter data : ");
            scanf("%d", &data);
            if (root == NULL)
            {
                struct node *new = (struct node *)malloc(sizeof(struct node));
                new->info = data;
                new->left = NULL;
                new->right = NULL;
                root = new;
            }
            else
            {
                insert(root, data);
            }
            break;

        case 2:
            printf("Enter data for deletion : ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printf("Inorder travarsal is   : \n");
            inorder(root);
            printf("\n");
            break;
        case 4:
             printf("preorder travarsal is   : \n");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("postorder travarsal is   : \n");
            postorder(root);
            printf("\n");
            break;
        case 6:
            display(root, 1);
            break;

        case 7:
            exit(1);

        default:
            printf("Wrong choice\n");
        }
    }
}
