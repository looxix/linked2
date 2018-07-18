// LINKED LISTS PRACTICE
#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct node {
	int n;
	struct node *next;
} Node;
typedef struct list {
	Node *first;
	int node_count;
} List;

// Prototypes
List *init(void);
void add_h(List *list, int nvalue);
void add_l(List *list, Node *b_elem, int nvalue);
void rm_h(List *list);
void rm_l(List *list, Node *to_rm);
void display_ll(List *list);
void rm_wl(List *list);
int countnodes_ll(List *list);

// Initialize a linked list.
List *init(void)
// lvo: use a better name like 'll_init()' ?
{
	// lvo: here a list is always create with already one element
	// lvo: why not create an empty list?
	List *nlist = malloc(sizeof(List));
	Node *elem = malloc(sizeof(Node));

	if (nlist == NULL || elem == NULL) {
	// lvo: (!nlist || !elem) is more idiomatic
		exit(EXIT_FAILURE);
		// lvo: no error message, better to make a wrapper for malloc()
	}

	elem->n = 0;
	elem->next = NULL;
	nlist->first = elem;
	nlist->node_count = 1;
	return nlist;
}

// Add a node(n_elem) to the head of a linked list.
void add_h(List *list, int nvalue)
// lvo: s/add_h/ll_add(_head)/ ?
{
	Node *n_elem = malloc(sizeof(Node));
	// lvo: what's the meaning of 'n' & 'elem'?
	// lvo: simply use 'n' or 'node'

	if (list == NULL || n_elem == NULL) {
		// lvo: probably better to not check for list here
		exit(EXIT_FAILURE);
	}

	n_elem->n = nvalue;
	n_elem->next = list->first;
	list->first = n_elem;
	list->node_count = list->node_count + 1;

}

// Add a node 'inside' the list (after a specified node);
// lvo: this is almost the same as add_h()
// lvo: which bring the question: do you really need the type 'List'?
// lvo: can't you simply use a pointer to a Node for the head of the list?
void add_l(List *list, Node *b_elem, int nvalue)
// lvo: s/add_l/list_insert/ ?
{
	Node *n_elem = malloc(sizeof(Node));

	if (list == NULL || n_elem == NULL) {
		exit(EXIT_FAILURE);
	}

	n_elem->n = nvalue;
	n_elem->next = b_elem->next;
	b_elem->next = n_elem;
	list->node_count = list->node_count + 1;

}

// Remove the node at the head of a linked list.
void rm_h(List *list)
// lvo: same reamrks about cryptic function name
{
	if (list == NULL) {
		exit(EXIT_FAILURE);
	}

	if (list->first != NULL) {
		Node *rmbuff = list->first;
		// lvo: 'rm*buff*' is a strange name for a node
		// lvo: simply use 'n' or 'node'
		list->first = list->first->next;
		free(rmbuff);
	}
	list->node_count = list->node_count + 1;

}

// Remove a node inside the list.
void rm_l(List *list, Node *to_rm)
// lvo: same remarks about cryptic function name
// lvo: 'n' or 'node' are better names than 'to_rm'
{

	if (list == NULL || to_rm == NULL) {
		exit(EXIT_FAILURE);
	}

	// lvo: better no if-else with the removal
	// lvo:
	//	if (...) {
	//		prev = ...
	//	} else {
	//		prev = ...
	//	}
	//	prev->next = ...
	//	free(...)
	if (to_rm == list->first) {
		Node *rmbuff = list->first;
		// lvo: 'rm*buff*' is a strange name for a node
		// lvo: rmbuff is always equals to to_rm, thus unneeded
		list->first = list->first->next;
		// lvo: list->first = to_rm->next;
		free(rmbuff);
	} else {
		// lvo: better to create an helper function to do the lookup
		Node *b_rm = list->first;
		// lvo: what 'b_rm' means? 'before (the element to) remove' ?
		Node *rmbuff = list->first->next;
		// lvo: use var name explaining their role like : 'prev' & 'curr'

		int endloop = 0;

		// lvo: do-while() loops are generally the wrong thing to use
		// lvo: use while-loops or for-loops instead
		do {
			if (to_rm == rmbuff) {
				b_rm->next = rmbuff->next;
				free(rmbuff);
				endloop = 1;
			}

			b_rm = rmbuff;
			rmbuff = rmbuff->next;
		} while (endloop != 1);
		// lvo: end-of-loop flags are costly and unneeded,
		// lvo: use 'break;' instead

	}
	list->node_count = list->node_count - 1;
	// lvo: list->node_count--;
}

// Delete (free) the whole list.
void rm_wl(List *list)
{

	if (list == NULL) {
		exit(EXIT_FAILURE);
	}

	Node *buff = malloc(sizeof(Node));
	// lvo: need to allocate a new node while removing eveything ???
	while (list->first != NULL) {
		buff = list->first;
		list->first = list->first->next;
		// lvo: no need to assign anything whie removing
		free(buff);
	}
	// lvo: just set the next pointer to NULL here
	list->node_count = 0;
}

// Display a whole linked list.
void display_ll(List *list)
{
	// lvo: declaration on top, please
	//	Node *buff;

	if (list == NULL) {
		exit(EXIT_FAILURE);
	}

	Node *buff = list->first;
	// lvo: 'buff' is a strange name for a node
	while (buff != NULL) {
	// lvo: for (n = list->first; n; n = n->next)
		printf("%d -> ", buff->n);
		buff = buff->next;
	}

	printf("END.\n");
}

// Count the number of elements in a linked list.
int countnodes_ll(List *list)
{
	if (list == NULL) {
		exit(EXIT_FAILURE);
	}

	Node *cbuff = list->first;
	int ncount = 0;
	// lvo: 'ncount' is strange, 'n' or 'count' is enough

	// lvo: what's the purpose of list->node_count?

	// lvo: do-while() loops are generally the wrong thing to use
	// lvo: here you need to do all tests twice
	do {
		if (cbuff != NULL) {
			ncount++;
		}
		cbuff = cbuff->next;
	} while (cbuff != NULL);

	// lvo:
	//	for (count = 0, node = list->first; node; node = node->next)
	//		count++;

	return ncount;
}

// MAIN.. (ll functions tests)
int main(void)
{
	printf("\n");
	// init the list.
	List *linked = init();
	// fill the list.
	linked->first->n = 7;
	// lvo: why not add_h(linked, 7) ?
	add_h(linked, 5);
	add_h(linked, 10);
	add_h(linked, 12);
	add_h(linked, 78);
	// display inital list
	printf("INITIAL list: \n");
	display_ll(linked);

	// add an element (24) inside the list (before '12').
	Node *buff = linked->first;
	while (buff != NULL) {
		if (buff->n == 12) {
			add_l(linked, buff, 24);
		}

		buff = buff->next;
	}
	// display the list
	printf("ADDED 24 before 12: \n");
	display_ll(linked);

	// remove the node that contain '10' in the list.
	buff = linked->first;
	while (buff != NULL) {
		if (buff->n == 10) {
			// lvo: rm_l() already needs to walk the list
			// lvo: you need to walk the list twice to remove
			// lvo: a given element
			rm_l(linked, buff);
			// lvo: once removed, no need to continue to loop
		}
		buff = buff->next;
	}
	// display the list
	printf("REVOVED 10: \n");
	display_ll(linked);

	// count the nodes in the list.
	int nnodes = countnodes_ll(linked);
	// display the result
	printf("NUMBER of elements in the list: %d\n", nnodes);
	// or..
	printf("NUMBER of elements in the list: %d\n", linked->node_count);

	// Empty the list.
	rm_wl(linked);
	// display the (hopefuly) empty list.
	printf("EMPTIED THE LIST: \n");
	display_ll(linked);

	printf("\n");

	return 0;
}
