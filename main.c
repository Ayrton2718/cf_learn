#include "cf_int64.h"
#include "cf_int32.h"

int main(void)
{
    CFObj_t value1 = CFInt64_alloc(100);    // オブジェクトの生成
    CFRuntime_retain(value1);   // 参照カウンターのカウントアップ

    CFObj_t value2 = CFInt32_alloc(100);    // オブジェクトの生成
    CFRuntime_retain(value2);   // 参照カウンターのカウントアップ


    printf("%lld\n", CFInt64_get(value1));  // 値を表示
    printf("%d\n", CFInt32_get(value2));  // 値を表示

    CFRuntime_release(value1);  // 参照カウンターのカウントダウン。参照している人が0人になったので、メモリを解放する。
    CFRuntime_release(value2);   // 参照カウンターのカウントアップ
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