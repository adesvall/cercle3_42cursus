#include <stdio.h>

int check_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", alphabet);
	// printf("%-20s: 0\n", "expected lenght");
	// printf("%-20s: %zu\n", "libc", strlen(NULL));
	// printf("%-20s: %zu\n", "libasm", ft_strlen(NULL));
	// printf("\n");
}

int main()
{
	check_strlen();
	//check_strcpy();
	//check_strcmp();
	//check_write();
	//check_read();
	//check_strdup();
}
