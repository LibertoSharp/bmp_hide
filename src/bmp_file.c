#include "../includes/bmp_file.h"
#include "../includes/common.h"

int read_bmp(char *filename, t_bmp_file *dest)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;

    dest->metadata = malloc(sizeof(struct stat));
    fstat(fd, dest->metadata);
    dest->buff = malloc(dest->metadata->st_size);
    read(fd, dest->buff, dest->metadata->st_size);

    close(fd);
    return 0;
}

void free_bmp(t_bmp_file file)
{
    free(file.metadata);
    free(file.buff);
}

unsigned char read_8(t_bmp_file file, int address)
{
    return file.buff[address];
}

unsigned short read_16(t_bmp_file file, int address)
{
    return read_8(file, address) << 8 | read_8(file, address+1);
}

unsigned int read_32(t_bmp_file file, int address)
{
    return read_16(file, address) << 16 | read_16(file, address+2);
}

unsigned long long read_64(t_bmp_file file, int address)
{
    return (unsigned long long)read_32(file, address) << 32 | read_32(file, address+4);
}
