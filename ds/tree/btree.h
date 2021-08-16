#ifndef __BTREE_H
#define __BTREE_H

struct node_st {
	void *data;
	struct node_st *left;
	struct node_st *right;
};

typedef struct {
	struct node_st *root;
	int size;
}btree_t;

typedef void (*pri_t)(const void *data);
typedef int (*cmp_t)(const void *data, const void *key);

int btreeHeadInit(btree_t **tree, int size);

int treeInsert(btree_t *tree, const void *data, cmp_t cmp);

int treeDelete(btree_t *tree, const void *key, cmp_t cmp);
// 查找

void treeMidTraval(const btree_t *tree, pri_t pri);

void treeDestroy(btree_t *tree);

#endif

