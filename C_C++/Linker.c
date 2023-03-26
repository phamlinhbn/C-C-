/***********************************************************************
 * Include files
 ***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/***********************************************************************
* API
***********************************************************************/
/**
* @brief        Create a linked list node
* @param[in]    ListNode: Linklist head
* @param[out]   None
* @param[inout] None
* @return       None
**/
typedef struct Node 
{
    uint8_t data;
    struct Node *next;
} node;

/**
* @brief        Initialize Linked list Vector with value = NULL
* @param[in]    head: Linklist head
* @param[out]   None
* @param[inout] None
* @return       None
**/
void initVector(node **head) ;

/**
* @brief        add an element to the end of a List
* @param[in]    head: Linklist head
* @param[in]    val: The value of the node to be pushed
* @param[out]   None
* @param[inout] None
* @return       None
**/
void pushBack(node **head, uint8_t val);

/**
* @brief        assigns new value to the element of the list by replacing the old value
* @param[in]    head: Linklist head
* @param[in]    val: The value of the new node to be assign
* @param[out]   None
* @param[inout] None
* @return       None
**/
void assign(node **head, uint8_t index, uint8_t val);

/**
* @brief        remove the last element of a list
* @param[in]    head: Linklist head
* @param[out]   None
* @param[inout] None
* @return       None
**/
void pop_back(node **head);

/**
* @brief        Insert new elements before the element at the position pointed to by the iterator
* @param[in]    head: Linklist head
* @param[in]    index: the position pointed to by the iterator
* @param[in]    val: The value of the new node to be insert
* @param[out]   None
* @param[inout] None
* @return       None
**/
void insert(node **head, uint8_t index, uint8_t val);

/**
* @brief        Delete element based on the position of the container
* @param[in]    head: Linklist head
* @param[in]    index: the position of the container
* @param[out]   None
* @param[inout] None
* @return       None
**/
void erase(node **head, uint8_t index);

/**
* @brief        Expand the container by inserting a new element.
* @param[in]    head: Linklist head
* @param[in]    index: the position to be emplace
* @param[in]    val: The value of the node to be emplace
* @param[out]   None
* @param[inout] None
* @return       None
**/
void emplace(node **head, uint8_t index, uint8_t val);

/**
* @brief        add an element to the end of a List
* @param[in]    head: Linklist head
* @param[in]    val: The value of the node to be emplace
* @param[out]   None
* @param[inout] None
* @return       None
**/
void emplace_back(node **head, uint8_t val);

/**
* @brief        swap contents of one list with another list of the same time
* @param[in]    head1: Linklist head 1
* @param[in]    head2: Linklist head 2
* @param[out]   None
* @param[inout] None
* @return       None
**/
void swap(node **head1, node **head2);

/**
* @brief        clear whole node of list
* @param[in]    head1: Linklist head
* @param[out]   None
* @param[inout] None
* @return       None
**/
void clear(node **head);

/**
* @brief        print whole node of list
* @param[in]    head1: Linklist head
* @param[out]   None
* @param[inout] None
* @return       None
**/
void printlist(node *head);

/*******************************************************************************
 * Functions
 ******************************************************************************/

void initVector(node **head)
{
    *head = NULL;
}

void pushBack(node **head, uint8_t val)
{
    node *newNode = (node*)malloc(sizeof(node));/*allocate node*/
    newNode->data = val;/*put in the data*/
    newNode->next = NULL;/*put in the next = Null*/

    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        node *ptr = *head;/*Make node ptr as head*/
        while (ptr->next != NULL) /*node last*/
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void assign(node **head, uint8_t index, uint8_t val) 
{
    if (*head == NULL) 
    {
        printf("List is already empty\n");
        return;
    }

    node *ptr = *head;

    for (uint8_t i = 0; i < index; i++) 
    {
        ptr = ptr->next;

        if(ptr->next == NULL)
        {
            printf("\nCould not find the element %dth in a List", index);
            return ;
        }
    }
    ptr->data = val; 
}

void pop_back(node **head) 
{
    if (*head == NULL) 
    {
        printf("List is already empty\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
    } 
    else 
    {
        node *ptr = *head;

        while (ptr->next->next != NULL) 
        {
            ptr = ptr->next;
        }
        free(ptr->next);
        ptr->next = NULL;
    }
}


void insert(node **head, uint8_t index, uint8_t val)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    node *ptr = *head;

    if (*head == NULL & index == 0) 
    {
        *head = newNode;
    }
    else if(index == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        for (uint8_t i = 0; i < index - 1; i++) 
        {
            ptr = ptr->next;
            // if(ptr->next == NULL)
            // {
            //     printf("\nThe %dth element is beyond the number of elements in the list", index);
            //     return;
            // }
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }     
}

void erase(node **head, uint8_t index)
{
    if (*head == NULL) 
    {
        printf("List is already empty\n");
        return;
    }
    if (index == 0) 
    {
        node *nodeToDelete = *head;
        *head = (*head)->next;
        free(nodeToDelete);
    } 
    else 
    {
        node *ptr = *head;
        for (uint8_t i = 0; i < index - 1; i++) 
        {
            ptr = ptr->next;
        }
        node *nodeToDelete = ptr->next;
        ptr->next = nodeToDelete->next;
        free(nodeToDelete);
    }
}

void emplace(node **head, uint8_t index, uint8_t val) 
{
    insert(head, index, val);
}

void emplace_back(node **head, uint8_t val)
{
    pushBack(head, val);
}

void swap(node **head1, node **head2)
{
    node *tempNode = *head1;
    *head1 = *head2;
    *head2 = tempNode;
}

void clear(node **head) 
{
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    node *ptr = *head;
    node *next;
    while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *head = NULL;
    printf("\nList cleared");
}

void printlist(node *head) 
{
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
    node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() 
{
    node *vector;
    initVector(&vector);
    
    pushBack(&vector, 10);
    pushBack(&vector, 20);
    pushBack(&vector, 30);
    printlist(vector);
    
    assign(&vector, 1, 15);
    printlist(vector);
    
    pop_back(&vector);
    printlist(vector);
    
    insert(&vector, 2, 25);
    printlist(vector);
    
    erase(&vector, 2);
    printlist(vector);
    
    emplace(&vector, 1, 35);
    printlist(vector);
    
    emplace_back(&vector, 40);
    printlist(vector);
    
    node *vector2;
    initVector(&vector2);
    pushBack(&vector2, 50);
    swap(&vector, &vector2);
    printlist(vector);
    printlist(vector2);

    clear(&vector);
    printlist(vector);

    return 0;
}