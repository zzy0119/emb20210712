#ifndef __PROTO_H
#define __PROTO_H

#define PATH		"/etc/passwd"
#define PROJ_ID		'a'

#define PATHSIZE	128
#define TEXTSIZE	64	

struct server_st {
	long mtype;
	char mtext[TEXTSIZE];
};

#endif

