#include "cf_int64.h"


int main(void)
{
    CFObj_t value1 = CFInt64_alloc(100);
    CFRuntime_retain(value1);

    printf("%lld\n", CFInt64_get(value1));

    CFRuntime_release(value1);
    return 0;
}

// 同じことをしようとすると、本当はこうなる
// int main(void)
// {
//     int64_t* value1 = (int64_t*)malloc(sizeof(int64_t));
//     *value1 = 100;

//     printf("%lld\n", *value1);

//     free(value1);
//     return 0;
// }