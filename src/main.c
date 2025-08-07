#include "../includes/bmp_file.h"
#include "../includes/common.h"

#define BUFF_SIZE 30000

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../includes/stb_image.h"
#include "../includes/stb_image_write.h"
#include "../includes/dict.h"
/* int main(int argc, char** argv)
{
    t_bmp_file file;
    if (argc < 1) return 0;

    if (read_bmp(argv[1], &file) == -1)
    {
        write(2, "ERROR: File not found\n", 22);
        return (-1);
    }

    printf("%llX\n",read_64(file, 0x46));
    free_bmp(file);
} */

int hide_in_image(char *path_image_in, char *secret, int width, int height, unsigned char *canvas)
{
    for (int i = 0; i < height; i += 20)
    {
        for (int j = 0; j < width; j += 20)
        {
            int k = (i * width + j) * 4;
            canvas[k + 3] = 220;
        }
    }
    return (0);
}

/* 
 * Layout of input:
 * +---------------------------------+----------------+---------------------------------+
 * | file where is stored the secret | image in input | image in output with the secret |
 * +---------------------------------+----------------+---------------------------------+
 * |> argv[1]                        |> argv[2]       |> argv[3]                        |
 * +---------------------------------+----------------+---------------------------------+
 */

int main(int argc, char **argv)
{
    int width, height, channels;
    unsigned char *canvas = stbi_load(argv[2], &width, &height, &channels, 4);
    char *secret = NULL;

    if (canvas == NULL)
    {
        printf("Error: Image is null\n");
        return (-1);
    }
    //minimum size to hide "Hello World!"
    if (height * width < 4800)
    {
        printf("Error: Image to small\n");
        return (-1);
    }
    
    if (hide_in_image(argv[1], secret, width, height, canvas) != 0)
    {
        return (-1);
    }
    printf("width %d\nheight %d\n", width, height);
    if (!stbi_write_png(argv[3], width, height, 4, canvas, width * 4))
    {
        printf("ptr2 is null\n");
        return (-1);
    }
    stbi_image_free(canvas);
    return (argc);
}