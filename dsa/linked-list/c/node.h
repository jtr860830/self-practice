#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

typedef struct Node node_t;

node_t *new_node(const char *const, int);
void free_node(node_t *const);
int node_get_value(const node_t *const);
int node_set_value(node_t *const, int);
const char *node_get_key(const node_t *const);
int node_cmp_key(const node_t *const, const char *);
const char *node_set_key(node_t *const, const char *);
node_t *node_get_next(const node_t *const);
node_t *node_set_next(node_t *const, node_t *const);

#endif // !LINKED_LIST_NODE_H
