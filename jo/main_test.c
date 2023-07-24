#include "libcub.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (checker(argv[1]))
		printf("false");
	printf("%s %s %s %s", manage_stock_texture(NULL, 5), manage_stock_texture(NULL, 6), manage_stock_texture(NULL, 7), manage_stock_texture(NULL, 8));
}