#ifndef __PROTO_H
#define __PROTO_H

#define PATHNAME	"/etc/passwd"
#define PROJID		1
#define NAMESIZE	32

// data
struct stu_st {
	int id;
	char name[NAMESIZE];
};

struct msg_st {
	long mtype; // > 0
	struct stu_st stu;
};

#endif

