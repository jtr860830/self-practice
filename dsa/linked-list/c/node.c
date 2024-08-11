#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

struct Node {
  char *key;
  int value;
  node_t *next;
};

node_t *new_node(char *key, int value) {
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

void free_node(node_t *node) { free(node); }

int node_get_value(node_t *node) { return node->value; }

int node_set_value(node_t *node, int value) { return node->value = value; }

char *node_get_key(node_t *node) { return node->key; }

int node_cmp_key(node_t *node, char *key) { return strcmp(node->key, key); }

char *node_set_key(node_t *node, char *key) { return node->key = key; }

node_t *node_get_next(node_t *node) { return node->next; }

node_t *node_set_next(node_t *node, node_t *next) { return node->next = next; }
