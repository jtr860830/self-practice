#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

struct Node {
  const char *key;
  int value;
  node_t *next;
};

node_t *new_node(const char *const key, int value) {
  node_t *node = malloc(sizeof(node_t));
  if (node == NULL) {
    fprintf(stderr, "Failed to allocate memory for node\n");
    return NULL;
  }
  node->key = key;
  node->value = value;
  node->next = NULL;
  return node;
}

void free_node(node_t *const node) { free(node); }

int node_get_value(const node_t *const node) { return node->value; }

int node_set_value(node_t *const node, int value) {
  return node->value = value;
}

const char *node_get_key(const node_t *const node) { return node->key; }

int node_cmp_key(const node_t *const node, const char *key) {
  return strcmp(node->key, key);
}

const char *node_set_key(node_t *const node, const char *key) {
  return node->key = key;
}

node_t *node_get_next(const node_t *const node) { return node->next; }

node_t *node_set_next(node_t *const node, node_t *const next) {
  return node->next = next;
}
