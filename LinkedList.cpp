//Dorizabelle Northecide
//Software Development
//October 30, 2020

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void Push(struct node **headRef, int dataValue)
{

    struct node *newNode = new struct node;
    newNode->data = dataValue;
    newNode->next = *headRef;
    *headRef = newNode;
}

void PrintWithLoop(struct node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void Print(struct node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    Print(head->next);
}

int Length(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void AddToEnd(struct node **headRef, int dataValue)
{
    struct node *current = *headRef;
    if (current == NULL)
    {
        Push(headRef, dataValue);
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        Push(&(current->next), dataValue);
    }
}

void RemoveNode(struct node **headRef, int dataValue)
{
    struct node *current = *headRef;
    struct node *prev = NULL;

    while (current != NULL)
    {

        if (current->data == dataValue)
        {
            if (current == *headRef)
            {
                *headRef = (*headRef)->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

struct node *FindkthToLast(struct node *head, int k)
{
    /*
	â€¢ Create two pointers to store current and runner, set both to point head.
	â€¢ Iterate the runner pointer with k times
	â€¢ Iterate the runner and current pointer at the same speed over the list.
	â€¢ Return the current pointer.
	*/
    struct node *current = head;
    struct node *runner = head;

    while ((runner != NULL) && (k > 0))
    {
        runner = runner->next;
        k--;
        if ((runner == NULL) && (k > 0))
            return NULL;
    }

    while (runner != NULL)
    {
        runner = runner->next;
        current = current->next;
    }

    return current;
}

void Reverse(struct node **headRef)
{
    struct node *newlist = NULL;
    struct node *current = *headRef;
    struct node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = newlist;
        newlist = current;
        current = next;
    }
    *headRef = newlist;
}

void InsertSorted(struct node **headRef, int dataValue)
{
    /*
	â€¢ Create a new node with the given data.
	â€¢ If the list is empty or given data is smaller than the first node data, then
	â€¢ Insert the new node on the frontofthelist,change the head to point the newnode.
	â€¢ Else, iterate the list for looking the right place to insert the new value
	*/
    struct node *newNode = new struct node;
    newNode->data = dataValue;

    struct node *current = *headRef;

    if ((*headRef == NULL) || dataValue <= (*headRef)->data)
    {
        newNode->next = (*headRef);
        *headRef = newNode;
    }
    else
    {
        while ((current->next != NULL) && (current->next->data <= newNode->data))
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

//------------------------------------------------
//Remove duplicates from a sorted linked list

void removeDuplicates(struct node *head)
{
    /* Pointer to traverse the linked list */
    struct node *current = head;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct node *next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
        return;

    /* Traverse the list till last node */
    while (current->next != NULL)
    {
        /* Compare current node with next node */
        if (current->data == current->next->data)
        {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            current = current->next;
        }
    }
}

//------------------------------------------------
//Remove duplicates from an unsorted linked list V1

void removeDuplicatesUnsortedV1(struct node *head)
{ //This function removes the duplicates using the standard runner method taking 2 pointers
    node *temp = head;
    node *temp1 = (head);
    while (temp != NULL)
    {
        while (temp1->next != NULL)
        {
            if (temp->data == temp1->next->data)
            {
                node *p;
                p = temp1->next;
                temp1->next = temp1->next->next;
                delete (p);
            }
            else
            {
                temp1 = temp1->next;
            }
        }

        temp = temp->next;
        temp1 = temp;
    }
}

//------------------------------------------------
//Remove duplicates from an unsorted linked list V2
void removeDuplicatesUnsortedV2(struct node *head)
{
    struct node *current, *runner, *dup;
    current = head;

    /* Pick elements one by one */
    while (current != NULL && current->next != NULL)
    {
        runner = current;

        /* Compare the picked element with rest 
           of the elements */
        while (runner->next != NULL)
        {
            /* If duplicate then delete it */
            if (current->data == runner->next->data)
            {
                /* sequence of steps is important here */
                dup = runner->next;
                runner->next = runner->next->next;
                delete (dup);
            }
            else /* This is tricky */
                runner = runner->next;
        }
        current = current->next;
    }
}

int main()
{

    struct node *head = NULL;

    Push(&head, 70);
    Push(&head, 60);
    Push(&head, 50);
    Push(&head, 60);
    Push(&head, 24);
    Push(&head, 32);
    Push(&head, 64);
    Push(&head, 50);
    Push(&head, 50);

    PrintWithLoop(head);
    cout << endl;
    Print(head);
    cout << endl;
    removeDuplicates(head);
    Print(head);
    cout << endl;

    removeDuplicatesUnsortedV1(head);
    Print(head);
    cout << endl;
    cout << Length(head) << endl;
    AddToEnd(&head, 75);
    Push(&head, 20);
    Print(head);
    RemoveNode(&head, 75);
    cout << endl;
    Print(head);
    /*
	struct node* temp = FindkthToLast(head, 4);
	if(temp != NULL)
		cout << "k = 4, value = " << temp->data << endl;
	else
		cout << "Out of range" << endl;

	Reverse(&head);
	cout << endl;
	Print(head);
	*/
    InsertSorted(&head, 55);
    cout << endl;
    Print(head);

    return 0;
}