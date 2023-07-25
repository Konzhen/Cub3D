#include "libcub.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;

	if (check_argc(argc, 2, 2))
		return (1);
	fd = checker(argv[1]);
	if (fd == -1)
	{
		printf("error_1\n");
		return (1);
	}
	data = get_data(fd, argv[1]);
	if (!data)
	{
		printf("error_2\n");
		return (1);
	}
	/*printf("x:%f y:%f start:%c", data->player->pos_x,
		data->player->pos_y, data->player->start);*/
	free_data(data);
}
