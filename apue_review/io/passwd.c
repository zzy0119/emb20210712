#include <stdio.h>
#include <string.h>
#include <shadow.h>
#define _XOPEN_SOURCE       /* See feature_test_macros(7) */
#include <unistd.h>

#define NAMESIZE	64

const char *encrypt(const char *key, const char *pwd);
int main(int argc, char *argv[])
{
	struct spwd *p;
	char name[NAMESIZE] = {};
  	const char *pwd;	 

	printf("username:");
	fgets(name, NAMESIZE, stdin);
	name[strlen(name)-1] = '\0'; // 去除'\n'
	pwd = getpass("password:");

	p = getspnam(name);
	if (NULL == p) {
		perror("getspnam()");
		return 1;
	}

	// 输入密码加密
	pwd = encrypt(pwd, p->sp_pwdp);

	if (strcmp(p->sp_pwdp, pwd))
		puts("密码错误");
	else
		puts("登录成功");

	return 0;
}

const char *encrypt(const char *key, const char *pwd)
{
	char *res = crypt(key, pwd);
	if (NULL == res)
		return NULL;
	return res;
}

