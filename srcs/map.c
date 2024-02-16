// abir archivo, leer y guardar linea por linea en una matriz
// que pasa si no es un archivo .ber? se puede comprobar eso de alguna forma?
// checkear que el mapa sea correcto
	// 5 caracteres, 0 espacio vacio, 1 pared, C coleccion able, E salida, P posicion inicial
	// reglas
		// debe tener una E, un C (al menos) y una P
		// rectangular (todas las lineas misma longitud y menor (o igual) numero de lineas que de longitud)
		// rodeado de muros (1's)
		// camino valido (seguir un rastro de 0 o C hasta la E) aqui si es un rastro solo de 0 es valido, o debes coger un C???

void	check_map(char **file)
{
	if (!check_ex_coll_pos(file))
		error("The map is missing an exit, collectable, or initial position");
	if (!check_rectangular(file))
		error("The map is not rectangular");
	if (!check_walls(file))
		error("The map is not enclosed");
	if (!check_path(file))
		error("There is no path to exit the map");
}

void	ft_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Could not open the file");
	buffer = get_next_line(fd); // aqui estoy alocando memoria para la linea, y dentro del while tmb con el join, mirar bien donde debo liberarla
	while (buffer)
	{
		buffer = get_next_line(fd);
		ft_strjoin(line, buffer);
		free(buffer);
	}
	map->file = ft_split(line, '\n');
	check_map(map->file); // pensar si mandar el struct tmb, necesitare guardar la longitud de las lineas, posicion inicial y demas? si es asi, enviar para hacer mas eficiente
}