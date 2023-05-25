#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct s_node {
    char* data;
    struct s_node* nxtpointer;
}*head_ref;

struct s_linked
{
	char			*data;
	struct s_linked	*next;
}*head;

#endif 