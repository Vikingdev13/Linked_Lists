#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_def
{
    int data;
    struct node *next;
} node;

node *makeNode(int val);
node *insertFront(node *head, node *new);
void printList(node *head);
node *deleteNode(node *head, int val);
node *modifyNode(node *head, int old, int new);
int inList(node *head, int val);
void lookForDupes(node *L);
// int length(node *L);

int main()
{

    node *head = NULL;
    node *tmp = NULL;
    node *newNode = NULL;

    int amt, randNums, find, swap, del;

    srand(time(NULL));
    printf("How many nodes?: ");
    scanf("%d", &amt);

    for (int i = 0; i < amt; ++i)
    {
        randNums = rand() % 10000;
        newNode = makeNode(randNums);
        head = insertFront(head, newNode);
    }
    printList(head);
    printf("\n");
    printf("Enter a number to search for: ");
    scanf("%d", &find);

    int mark = inList(head, find);
    if (mark)
    {
        printf("Found %d in list\n", find);
        printf("\n");
        printf("Change %d to what value? ", find);
        scanf("%d", &swap);
        head = modifyNode(head, find, swap);
        printf("\n");
        printList(head);
    }
    else
    {
        printf("%d Not in list\n");
    }
    printf("\n");
    printf("Enter a number to remove: ");
    scanf("%d", &del);
    head = deleteNode(head, del);
    printf("\n");
    printList(head);
    printf("\n");
    lookForDupes(head);

    return 0;
}

/**
 * create a node for your list
 * return a pointer to that node (node *)
 */
node *makeNode(int val)
{
    node *tmp = malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

/**
 * add a node to the front of the list
 * return new front of list
 */
node *insertFront(node *head, node *new)
{
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        new->next = head;
        head = new;
    }
    return head;
}

/**
 * P: print out the linked list (10 per line)
 */
void printList(node *head)
{
    node *tmp = head;

    int i = 0;

    for (i = 1; tmp != NULL; ++i)

    {

        printf("%4d ", tmp->data);

        if (i % 10 == 0)

            printf("\n");

        tmp = tmp->next;
    }

    if ((i - 1) % 10)

        printf("\n");

    return;
}

/**
 * P: given a value, search the list and remove the node with that value
 */
node *deleteNode(node *head, int val)
{
    node *tmp = head;
    node *curr, *prev = NULL;
    while (tmp != NULL)
    {
        if (tmp->data == val)
        {
            curr = tmp->next;
            printf("%d was deleted from the list\n", tmp->data);
            free(tmp);
            if (prev != NULL)
            {
                prev->next = curr;
                return head;
            }
            else
            {
                head = curr;
                return head;
            }
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

/**
 * given a new and old value, search the list for the old value and change it to the new one
 */
node *modifyNode(node *head, int old, int new)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == old)
        {
            tmp->data = new;
            break;
        }
        tmp = tmp->next;
    }
    return head;
}

/**
 * given a value, searches the list for that value
 * return true or false (or an integer 0 or 1 that you can use as true or false)
 */
int inList(node *head, int val)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == val)

            return 1;
        tmp = tmp->next;
    }
    return 0;
}

/**
 * P: search the linked list looking for any duplicate values in the list
 */
void lookForDupes(node *L)
{
    node *tmp = malloc(sizeof(node));
    tmp = NULL;

    node *X, *Y;
    X = L;
    int mark = 0;

    while (X && X->next)
    {
        Y = X->next;
        while (Y)
        {
            if (X->data == Y->data)
            {
                if (tmp == NULL)

                    tmp = makeNode(X->data);
                tmp = insertFront(tmp, X);
                mark = 1;
            }
            Y = Y->next;
        }
        X = X->next;
    }
    if (mark == 1)
    {
        printList(tmp);
    }
    else
    {
        printf("No Dupes Found!\n");
    }
}

/**
 * --Optional--
 * returns the number of nodes in a given list
 */
// int length(node *L)
// {

// }
