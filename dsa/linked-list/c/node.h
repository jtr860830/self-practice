#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct Node node_t;

node_t *new_node(char *, int);
void free_node(node_t *);
int node_get_value(node_t *);
int node_set_value(node_t *, int);
char *node_get_key(node_t *);
int node_cmp_key(node_t *, char *);
char *node_set_key(node_t *, char *);
node_t *node_get_next(node_t *);
node_t *node_set_next(node_t *, node_t *);

#endif // !LINKED_LIST_NODE_H
