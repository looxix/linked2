//LINKED LISTS PRACTICE
#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct node
{
	int n;
	struct node *next;
}Node;
typedef struct list
{
	Node *first;
	int node_count;
}List;

//Prototypes
List *init(void);
void add_h(List *list, int nvalue);
void add_l(List *list, Node *b_elem, int nvalue);
void rm_h(List *list);
void rm_l(List *list, Node *to_rm);
void display_ll(List *list);
void rm_wl(List *list);
int countnodes_ll(List *list);

//MAIN.. (ll functions tests)
int main(void)
{
	printf("\n");
	//init the list.
	List *linked = init();
	//fill the list.
	linked->first->n = 7;
	add_h(linked, 5);
	add_h(linked, 10);
	add_h(linked, 12);
	add_h(linked, 78);
	//display inital list
	printf("INITIAL list: \n");
	display_ll(linked);

	//add an element (24) inside the list (before '12').
	Node *buff = linked->first;
	while(buff != NULL)
	{
		if(buff->n == 12)
		{
			add_l(linked, buff, 24);
		}

		buff = buff->next;
	}
	//display the list
	printf("ADDED 24 before 12: \n");
	display_ll(linked);
	
	//remove the node that contain '10' in the list.
	buff = linked->first;
	while(buff != NULL)
	{
		if(buff->n == 10)
		{	
			rm_l(linked, buff);	
		}
		
		buff = buff->next;
	}
	//display the list
	printf("REVOVED 10: \n");
	display_ll(linked);

	//count the nodes in the list.
	int nnodes = countnodes_ll(linked);
	//display the result
	printf("NUMBER of elements in the list: %d\n", nnodes);
	//or..
	printf("NUMBER of elements in the list: %d\n", linked->node_count);
	
	//Empty the list.
	rm_wl(linked);
	//display the (hopefuly) empty list.
	printf("EMPTIED THE LIST: \n");
	display_ll(linked);

	
	printf("\n");
		
	return 0;
}

//Initialize a linked list.
List *init(void)
{
	List *nlist = malloc(sizeof(List));
	Node *elem = malloc(sizeof(Node));

	if(nlist == NULL || elem == NULL)
	{
		exit(EXIT_FAILURE);
	}

	elem->n      = 0;
	elem->next   = NULL;
	nlist->first = elem;
	nlist->node_count = 1;
	return nlist;
}

//Add a node(n_elem) to the head of a linked list.
void add_h(List *list, int nvalue)
{
	Node *n_elem = malloc(sizeof(Node));
	
	if(list == NULL || n_elem == NULL)
	{
		exit(EXIT_FAILURE);
	}

	n_elem->n    = nvalue;
	n_elem->next = list->first;
	list->first  = n_elem;
	list->node_count = list->node_count + 1;
	
}

//Add a node 'inside' the list (after a specified node);
void add_l(List *list, Node *b_elem, int nvalue)
{
	Node *n_elem = malloc(sizeof(Node));

	if(list == NULL || n_elem == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	n_elem->n = nvalue;
	n_elem->next = b_elem->next;
	b_elem->next = n_elem;
	list->node_count = list->node_count + 1;

}

//Remove the node at the head of a linked list.
void rm_h(List *list)
{
	if(list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if(list->first != NULL)
	{
		Node *rmbuff = list->first;
		list->first = list->first->next;
		free(rmbuff);
	}
	list->node_count = list->node_count + 1;

}

//Remove a node inside the list.
void rm_l(List *list, Node *to_rm)
{

	if(list == NULL || to_rm == NULL)
	{
		exit(EXIT_FAILURE);
	}

		if(to_rm == list->first)
		{
			Node *rmbuff = list->first;
			list->first = list->first->next;
		       	free(rmbuff);	
		}
		
		else
		{
			Node *b_rm = list->first;
			Node *rmbuff = list->first->next;
			int endloop = 0;

			do
			{	
				if(to_rm == rmbuff)
				{
					b_rm->next = rmbuff->next;
					free(rmbuff);
					endloop = 1;
				}
				
				b_rm = rmbuff;
				rmbuff = rmbuff->next;
			}while(endloop != 1);
		
		}
		list->node_count = list->node_count - 1;
}

//Delete (free) the whole list.
void rm_wl(List *list)
{

	if(list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Node *buff = malloc(sizeof(Node));
	while(list->first != NULL)
	{
		buff = list->first;
		list->first = list->first->next;
		free(buff);
	}
	list->node_count = 0;
}

//Display a whole linked list.
void display_ll(List *list)
{
	if(list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Node *buff = list->first;
	while(buff != NULL)
	{
		printf("%d -> ", buff->n);
		buff = buff->next;
	}
	
	printf("END.\n");
}

//Count the number of elements in a linked list.
int countnodes_ll(List *list)
{
	if(list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Node *cbuff = list->first;
	int ncount = 0;
	do
	{
		if(cbuff != NULL)
		{
			ncount++;
		}
		cbuff = cbuff->next;
	}while(cbuff != NULL);

	return ncount;
}




