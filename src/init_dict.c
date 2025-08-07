#include "../includes/dict.h"

t_entry *init()
{
	int i, j;
	t_entry *arr;

	i = 1;
	j = 'a';
	arr = malloc(sizeof(t_entry) * 40);
	while(i < 39)
	{
		while(j <= 'z')
		{
			arr[i].c = j;
			arr[i].value = i;
			j++;
			i++;
		}
		arr[i].c = ' ';
		arr[i].value = i;
		i++;
		arr[i].c = '!';
		arr[i].value = i;
		i++;
		arr[i].c = '?';
		arr[i].value = i;
		i++;
		arr[i].c = '\n';
		arr[i].value = i;
		i++;
		j = '0';
		while(j <='9')
		{
			arr[i].c = j;
			arr[i].value = i;
			j++;
			i++;
		}
	}
	return (arr);
}