#include <stdio.h>
#include <assert.h>
void *memcpy(void * dest, const void* src, size_t count)
{
	void * tmpdes = dest;
	if (((src > (void *)((char *)dest + count)) || dest > (void *)((char *)src + count))
		&& src != NULL
		&& dest != NULL
		)
	{
		while (count)
		{
			((char *)dest)[--count] = ((char *)src)[--count];
		}
	}
	else
	{
		return NULL;
	}
	return tmpdes;
}

void* mymemcpy(void *dst, const void *src, size_t count)
{
	//安全检查  
	assert((dst != NULL) && (src != NULL));

	unsigned char *pdst = (unsigned char *)dst;
	const unsigned char *psrc = (const unsigned char *)src;

	//防止内存重复  
	assert(!(psrc <= pdst && pdst<psrc + count));
	assert(!(pdst <= psrc && psrc<pdst + count));

	while (count--)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	return dst;
}