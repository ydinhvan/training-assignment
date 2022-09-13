#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};


// insert a new node on the front of the list
void push(struct node** head, int new_data)
{
	// allocate node
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	// put data in the node
	new_node->data = new_data;
	// make next of new node as head
	new_node->next = (*head);
	// move head to point to the new node
	(*head) = new_node;
}

// Add a node to end of list 
void append(struct node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;  /* used in step 5*/
    /* 2. put in the data  */
    new_node->data  = new_data;
    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    } 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
    /* 6. Change the next of last node */
    last->next = new_node;
    return;   
}

void insertAfter(struct node** head, int des, int new_data)
{
    // check destination of new node
	if (des == 0)			// add new node to head
    {
		push(&(*head), new_data);
	}
	else 
	{
		int i = 1;
		struct node *last = *head;
		while (last->next != NULL )
		{
			i = i+1;
			last = last->next;
		}
		if (des == i)
		{
			append(&(*head), new_data);
		}

		else if (des > i)         // add new node to end of list
		{
			printf("\n Over list \n");    // destination is over list
			return;
		}
		else                            // add new node at destination
		{
			// allocate node
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			struct node *temp = *head;
			int j=1;
			while (j != des)
			{
				j = j+1;
				temp = temp->next;
			}
			// put data to node
			new_node->data = new_data;
			// make next of new_node to next of head
			new_node->next = temp->next;
			// move next of previous node to new node
			temp->next = new_node;
		}
	}
}

void del_begin(struct node** head)
{
	struct node* temp_node = (struct node*)malloc(sizeof(struct node));
	temp_node = (*head);
	(*head) = (*head)->next;
	free(temp_node); 
}

void del_end(struct node** head)
{
	struct node* end_node = (struct node*)malloc(sizeof(struct node));
	struct node* pre_node = (struct node*)malloc(sizeof(struct node));
	end_node = (*head);
	pre_node = NULL;
	while (end_node->next != NULL)
	{
		pre_node = end_node;
		end_node = end_node->next;
	}
	pre_node->next = NULL;
	free(end_node);
}


void del_des(struct node** head, int position)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    struct node* prev = (struct node*)malloc(sizeof(struct node));
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {           // delete begin node
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {	// delete des node
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                // Position was greater than number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void printList(struct node* n)
{
	while(n != NULL)
	{
		printf("%d ",n->data);
		n = n->next;
	} 
	printf("\n");
}

int main()
{
	// creat head node
	struct node* head = NULL;
	printList(head);
	append(&head, 1);		// 1
	printList(head);
	append(&head, 2);		// 1 2  
	printList(head);
	append(&head, 4);		// 1 2 4
	printList(head);
	push(&head,0);			// 0 1 2 4
	printList(head);
	insertAfter(&head,4,5);	// 0 1 2 4 5
	printList(head);
	insertAfter(&head,0,-1);	// -1 0 1 2 4 5   
	printList(head);
	push(&head,-2);			// -2 -1 0 1 2 4 5     
	printList(head);	
	insertAfter(&head,0,-3);	// -3 -2 -1 0 1 2 4 5  
	printList(head);
	insertAfter(&head,8,7);  // -3 -2 -1 0 1 2 4 5 7
	printList(head);
	insertAfter(&head,8,6);  // -3 -2 -1 0 1 2 4 5 6 7
	printList(head);
	insertAfter(&head,11,7);  // -3 -2 -1 0 1 2 4 5 6 7
	printList(head);
	printf("delete section\n");
	del_begin(&head);			//-2 -1 0 1 2 4 5 6 7
	printList(head);
    del_end(&head);				//-2 -1 0 1 2 4 5 6
	printList(head);
	del_des(&head,6);			// -2 -1 0 1 2 5 6
	printList(head);
	del_des(&head,1);			// -1 0 1 2 5 6
	printList(head);
	del_des(&head,6);			//	-1 0 1 2 5
	printList(head);
	del_des(&head,1);
	printList(head);

}
