#include "so_long.h"
// abir archivo, leer y guardar linea por linea en una matriz
// que pasa si no es un archivo .ber? se puede comprobar eso de alguna forma?
// checkear que el mapa sea correcto
	// 5 caracteres, 0 espacio vacio, 1 pared, C coleccion able, E salida, P posicion inicial
	// reglas
		// debe tener una E, un C (al menos) y una P
		// rectangular (todas las lineas misma longitud y menor (o igual) numero de lineas que de longitud)
		// rodeado de muros (1's)
		// camino valido (seguir un rastro de 0 o C hasta la E) aqui si es un rastro solo de 0 es valido, o debes coger un C???

void	check_map(t_map map)
{
	if (check_characters(map)) 
		error("The map has invalid characters");
	if (check_ex_coll_pos(&map))
		error("The map is missing an exit, collectable, or initial position");
	if (check_rectangular(&map))
		error("The map is not rectangular");
	if (check_walls(map))
		error("The map is not enclosed");
	if (check_path(&map)) // quiza haya que modificar esto tmb para que tenga en cuenta la posibilidad de que el pj no pueda coger ningun C
		error("There is no path to exit the map");
}

void	ft_map(char *file, t_map map)
{
	int		fd;
	char	*line;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Could not open the file");
	buffer = get_next_line(fd); // aqui estoy alocando memoria para la linea, y dentro del while tmb con el join, mirar bien donde debo liberarla // CREO QUE YA BIEN 
	line = ft_strdup(buffer);
	while (buffer)
	{
		line = ft_strjoin(line, buffer);
		buffer = get_next_line(fd);
	}
	map.parsed_map = ft_split(line, '\n');
	free(line);
	check_map(map); 
}