#include "../includes/bmp_file.h"
#include "../includes/common.h"

int main(int argc, char** argv)
{
    t_bmp_file file;
    if (argc < 1) return 0;

    if (read_bmp(argv[1], &file) == -1)
    {
        write(2, "ERROR: File not found", 21);
        return (-1);
    }

    printf("%llX\n",read_64(file, 0x46));
    free_bmp(file);
}