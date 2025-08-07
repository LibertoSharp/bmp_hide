#ifndef BMP_FILE_H
#define BMP_FILE_H

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include "dict.h"

typedef struct s_bmp_file
{
    struct stat *metadata;
    char *buff; 
} t_bmp_file;

int read_bmp(char *filename, t_bmp_file *dest);
void free_bmp(t_bmp_file file);
unsigned char read_8(t_bmp_file file, int address);
unsigned short read_16(t_bmp_file file, int address);
unsigned int read_32(t_bmp_file file, int address);
unsigned long long read_64(t_bmp_file file, int address);

t_entry *init();

#endif