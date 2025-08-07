#include "../includes/stb_image.h"
#include "../includes/stb_image_write.h"
#include "../includes/dict.h"

#include "../includes/bmp_file.h"
#include "../includes/common.h"

#define BUFF_SIZE 30000

char	*ft_strlowcase(char *str)
{
	int	i;

	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char *file_handling(char *path_image_in, char *buf, int width, int height, unsigned char *canvas)
{
	int fd = open(path_image_in, O_RDONLY);
    int read_bytes;

    if (path_image_in == NULL)
    {
        printf("Error: no path assigned for the secret\n");
        return (1);
    }
    read_bytes = read(fd, buf, BUFF_SIZE - 1);
    if (read_bytes > 0)
        buf[read_bytes] = '\0';
	close(fd);
    return(ft_strlowcase(buf));
}
