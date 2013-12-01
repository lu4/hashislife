/* Hashtable of Quad using a Node as key */

#ifndef HASHTBL_H
#define HASHTBL_H

typedef struct Hashtbl *Hashtbl;

/* Internal node or leaf */
typedef union Node Node;

/* List like type */
typedef struct Quad Quad;

struct Hashtbl {
  int size;
  int len;
  struct Quad **tbl;
};

union Node {
  // internal node
  struct {
    struct Quad *sub[4], *next; // subtrees : 0-upperleft, 1-upperright, 2-bottomleft, 3-bottomright
  } n;

  // leaf
  struct {
    int map[4];
    /* 0 1
     * 2 3
     * */
  } l;
};

struct Quad {
  int depth; // head information,
             // quad tree for a square map with side 2^(depth+1)
  union Node node;
  struct Quad *tl; // tail
};

int hash(Quad*[4]);

Hashtbl hashtbl_new();

/* Hash is computed before calling find and/or add */
Quad *hashtbl_find(Hashtbl hashtbl, int h, Quad *key[4]);

void hashtbl_add(Hashtbl hashtbl, int h, Quad *elt);

Quad *list_find(Quad *key[4], Quad *list);

void hashtbl_free(Hashtbl);

void print_quad(Quad *q);

void htbl_stat(Hashtbl htbl);

#endif