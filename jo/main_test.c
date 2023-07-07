#include "libcub.h"

int	main(int argc, char **argv)
{
	if (check_argc(argc, 2, 2))
		return (1);
	checker(argv[1]);
}
