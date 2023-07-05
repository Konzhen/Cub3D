#include <stdlib.h>

static char ***map_cpy(char ***map, char **blueprint)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(**blueprint)
	{
		*map[i][j] = blueprint[i][j];
		j++;
		if (*map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
	}
	*map[i][j] = '\0';
	return(map);
}

static char *fill_box(char *box, char c)
{
	int i;

	i = 0;
	box = malloc(sizeof(char *) * 91) + 1;
	while(i < 91)
	{
		box[i] = 'c';
		i++;
	}
	box[i] = '\n';
	i++;
}

static char **map_build(char **map, char **blueprint)
{
	int	i;
	char **map_flat;

	i = 0;
	map_flat = (char **)malloc(sizeof(char **) * 91) + 1;
	if (!map_flat)
		return (NULL);
	while(i < 91)
		map_flat[i] = fill_box(map_flat[i], *blueprint[i]);
	if (i < 90)
		map_flat[i][91] = '\0';
	map_flat[i] = NULL;
	return (map);
}

char ***map_init(char **blueprint, int size)
{
	char ***map;
	int i;

	i = 0;
	map = malloc(sizeof(char ***) * size);
	if(!map)
		return(NULL);
	map = map_cpy(map, blueprint);
	map[i] = map_build(map[i], blueprint);
}
