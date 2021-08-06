#ifndef __LIST_H
#define __LIST_H

// 结点
struct node_st {
	void *data;
	struct node_st *next;
};

// 头结点
typedef struct {
	struct node_st head;
	int size;
}listhead_t;

enum {LISTINSERTHEAD, LISTINSERTTAIL};
typedef void (*pri_t)(const void *data);
typedef int (*cmp_t)(const void *data, const void *key);

// 初始化头结点
int listheadInit(listhead_t **l, int size);

// 插入(头插(新节点作为第一个结点)/尾插(新节点作为最后一个结点))
int listInsert(listhead_t *l, const void *data, int way);

// 遍历
void listTraval(const listhead_t *l, pri_t pri);

// 释放
void listDestroy(listhead_t *l);

// 删除
int listDelete(listhead_t *l, const void *key, cmp_t cmp);

// 查找
void *listSearch(const listhead_t *l, const void *key, cmp_t cmp);

// 转置
void listReverse(listhead_t *l);

#endif





