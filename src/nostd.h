#ifndef __NES_DIFF_NO_STD
#define __NES_DIFF_NO_STD

int strcmp(const char* buffer1, const char* buffer2);

int strcmp(const char* buffer1, const char* buffer2)
{
    register int compare_buffers;

    while (*buffer1 && *buffer2)
    {
        compare_buffers = (*buffer1) - (*buffer2);

        if (compare_buffers != 0) {
            return compare_buffers;
        }

        if (*buffer1) buffer1++;
        if (*buffer2) buffer2++;
    }

    return 0;
}

#endif
