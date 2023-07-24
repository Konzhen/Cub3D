#include "libcub.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1);
	fd = checker(argv[1]);
	if (fd == -1)
	{
		printf("false");
		return (1);
	}
	char **tab = get_tab(get_raw_tab(fd, argv[1]));
	if (!tab)
		return (1);
	if (check_tab(tab))
	{
		free_tab((void **)tab, 0);
		printf("false");
		return (1);
	}
	free_tab((void **)tab, 0);
}