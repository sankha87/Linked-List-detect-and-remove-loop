#include<stdio.h>
#include<conio.h>

struct Node
{
	int data;
	struct Node *next;
};

Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void printList(Node* head)
{
	while (head != NULL)
	{
		printf(" %d ", head->data);
		head = head->next;
	}
}

// Function to detect and remove loop in a linked list that may contain loop 
void detectAndRemoveLoop(Node* head)
{
	// If list is empty or has only one node without loop 
	if (head == NULL || head->next == NULL)
		return;

	Node *slow = head, *fast = head;

	slow = slow->next;				// Move slow and fast 1 and 2 steps ahead respectively. 
	fast = fast->next->next;

	while (fast != NULL && fast->next != NULL)		// Search for loop using slow and fast pointers 
	{
		if (slow == fast)
		{
			printf("\nCycle detected");
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
		printf("\nCycle not detected");

	if (slow == fast)			/* If loop exists */
	{
		slow = head;

		while (slow->next != fast->next) 
		{
			slow = slow->next;
			fast = fast->next;
		}

		/* since fast->next is the looping point */
		fast->next = NULL; /* remove loop */
	}
}

int main()				/* Driver program to test above function*/
{
	Node *head = newNode(50);
//	head->next = head;
	head->next = newNode(20);
	head->next->next = newNode(15);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = newNode(8);

	/* Create a loop for testing */
	head->next->next->next->next->next->next = head->next->next;
//	head->next->next->next = head->next;
	detectAndRemoveLoop(head);

	printf("\nLinked List after removing loop \n");
	printList(head);

	_getch();
}