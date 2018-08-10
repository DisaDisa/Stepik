#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>


int (*my_f)(int);

bool init_lib(char const * lib_name, char const * f_name) {
	void *hdl = dlopen(lib_name, RTLD_LAZY);
	if (hdl == NULL) 
		return false;
	my_f = (int(*)(int)) dlsym(hdl, f_name);
	return my_f != NULL;
}


int main(int argc, char ** argv) {
	char *c = malloc(sizeof(char) * (strlen(argv[1] + 2)));
	c = strcat(c, "./");
	c = strcat(c, argv[1]);
	if (init_lib(c, argv[2])) {
		printf("%d\n", my_f(atoi(argv[3])));
	} else {
		printf("ERROR\n");
	}
	free(c);
}
