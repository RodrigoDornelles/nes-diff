#ifndef __NES_DIFF_NO_STD
#define __NES_DIFF_NO_STD

int strcmp(const char *l, const char *r)

int strcmp(const char *l, const char *r)
{
    while(*l==*r && *l) {
        l++;
        r++;
    }
	return *(unsigned char *)l - *(unsigned char *)r;
}
#endif
