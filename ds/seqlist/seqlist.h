#ifndef __SEQLIST_H
#define __SEQLIST_H

/*
 函数的声明--->增删改查
 类型的定义--->顺序表结构类型　
 */
typedef struct {
	void *p; //存储线性表首地址
	int nmemb; // 表中成员个数
	int size; // 表中每一个元素字节大小
}seqlist_t;

typedef void (*pri_t)(const void *data);

/*
初始化顺序表结构:创建seqlist_t结构
*s:表结构的地址
size:存储数据每个元素的字节大小
return:0成功 -1失败
 */
int seqlistInit(seqlist_t **s, int size);

/* 
   增加
s:表结构的地址
data:待插入元素的地址
return :
0成功
-1失败
 */
int seqlistAdd(seqlist_t *s, const void *data);

/*
 遍历

 */
void seqlistTraval(const seqlist_t *s, pri_t pri);

#endif

