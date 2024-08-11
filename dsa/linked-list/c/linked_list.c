#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "node.h"

struct List {
  node_t *head;
  size_t length;
};

list_t *new_list(void) {
  list_t *list = malloc(sizeof(list_t));
  if (list == NULL) {
    fprintf(stderr, "Failed to allocate memory for list\n");
    return NULL;
  }
  list->head = NULL;
  list->length = 0;
  return list;
}

void free_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = node_get_next(current);
    free_node(current);
    current = next;
  }
  free(list);
}

bool list_is_empty(list_t *list) {
  return (list->head == NULL) && (list->length == 0);
}

node_t *list_find_node(list_t *list, char *key) {
  node_t *current = list->head;
  while (current != NULL) {
    if (node_cmp_key(current, key) == 0) {
      return current;
    }
    current = node_get_next(current);
  }
  return NULL;
}

void list_print(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    char *key = node_get_key(current);
    int value = node_get_value(current);
    printf("%s:%02x -> ", key, value);
    current = node_get_next(current);
  }
  printf("\n");
}

bool list_append(list_t *list, node_t *node) {
  if (list_is_empty(list)) {
    list->head = node;
  } else {
    node_t *current = list->head;
    while (node_get_next(current) != NULL) {
      current = node_get_next(current);
    }
    node_set_next(current, node);
  }
  list->length++;
  return true;
}

bool list_insert_after(list_t *list, node_t *target, node_t *node) {
  if (target == NULL) {
    return false;
  }
  node_t *next = node_get_next(target);
  node_set_next(target, node);
  node_set_next(node, next);
  list->length++;
  return true;
}

bool list_insert_before(list_t *list, node_t *target, node_t *node) {
  if (target == NULL) {
    return false;
  }
  node_set_next(node, target);
  node_t **indirect = &list->head;
  while (*indirect != target) {
    node_t *tmp = node_get_next(*indirect);
    indirect = &tmp;
  }
  *indirect = node;
  list->length++;
  return true;
}

node_t *list_remove(list_t *list, node_t *node) {
  if (node == NULL) {
    return NULL;
  }
  node_t **indirect = &list->head;
  while (*indirect != node) {
    node_t *tmp = node_get_next(*indirect);
    indirect = &tmp;
  }
  *indirect = node_get_next(node);
  list->length--;
  return node;
}
