#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char *name = (char *)malloc(sizeof(char) * 10);
	char *name_2;
	gets(name);
	printf("before free name is %s\n", name);
	free(name);
	printf("after free name is %s\n", name);
	name_2 = (char *)malloc(sizeof(char) * 10);
	gets(name_2);
	printf("malloc name_2 and name is %s\nname_2 is %s\n", name, name_2);
	return 0;
}
