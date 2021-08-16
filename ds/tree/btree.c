#include <stdlib.h>

#include "btree.h"

int btreeHeadInit(btree_t **tree, int size)
{
	*tree = malloc(sizeof(btree_t));
	if (NULL == *tree)
		return -1;
	(*tree)->root = NULL;
	(*tree)->size = size;

	return 0;
}

static int __insert(struct node_st **root, const void *data, cmp_t cmp, int size)
{
	if (*root == NULL)	{
		struct node_st *new;
		new = malloc(sizeof(struct node_st));
		if (NULL == new)
			return -1;
		new->data = malloc(size);
		if (new->data == NULL) {
			free(new);
			return -1;
		}
		memcpy(new->data, data, size);
		*root = new;
		return 0;
	}
	if (cmp((*root)->data, data) >= 0) {
		__insert(&(*root)->left, data, cmp, size);	
	} else {
		__insert(&(*root)->right, data, cmp, size);
	}
}

int treeInsert(btree_t *tree, const void *data, cmp_t cmp)
{
	__insert(&tree->root, data, cmp, tree->size);
}

static void __midTraval(const struct node_st *root, pri_t pri)
{
	if (root == NULL)
		return ;
	__midTraval(root->left, pri);
	pri(root->data);
	__midTraval(root->right, pri);
}

void treeMidTraval(const btree_t *tree, pri_t pri)
{
	__midTraval(tree->root, pri);	
}

static void __destroy(struct node_st **root)
{
	if (*root == NULL)
		return ;
	__destroy(&(*root)->left);
	__destroy(&(*root)->right);
	free((*root)->data);
	free(*root);
	*root = NULL;
}

void treeDestroy(btree_t *tree)
{
	__destroy(&tree->root);
	free(tree);
}
	
