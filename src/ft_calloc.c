#include "../main.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (num != 0 && (num * size) / num != size)
		return (NULL);
	total_size = num * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	while ((size_t)ptr < total_size)
    {
        *(unsigned char *)ptr = '\0';
        ptr++;
    }
	return (ptr + 0);
}