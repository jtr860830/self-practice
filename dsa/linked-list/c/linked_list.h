#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

#include "node.h"

struct List;

typedef struct List list_t;

list_t *new_list(void);
void free_list(list_t *);
bool list_is_empty(list_t *);
node_t *list_find_node(list_t *, char *);
void list_print(list_t *);
bool list_append(list_t *, node_t *);
bool list_insert_after(list_t *, node_t *, node_t *);
bool list_insert_before(list_t *, node_t *, node_t *);
node_t *list_remove(list_t *, node_t *);

#endif // !LINKED_LIST_H
