#include "cf_int64.h"

// 64ビット整数型オブジェクト構造体
struct CFInt64_t
{
    // 必ず、runtimeオブジェクトを、構造体の先頭に宣言する。これについては、後日説明するけど、考えてみて
    struct CFRuntime_t runtime;

    int64_t var;
};


static void CFInt64_destructorCallback(CFObj_t obj)
{
    printf("[Debug] CFInt64 Destructing!\n"); // デバッグ用、上位オブジェクトを作成する際に用いる。今は無視.
    return;
}

CFObj_t CFInt64_alloc(int64_t initial_value)
{
    struct CFInt64_t* _obj = CFRuntime_alloc(sizeof(struct CFInt64_t), CFInt64_destructorCallback);
    _obj->var = initial_value;
    return _obj;
}


void CFInt64_set(CFObj_t obj, int64_t set_value)
{
    struct CFInt64_t* _obj = (struct CFInt64_t*)obj;
    _obj->var = set_value;
}


int64_t CFInt64_get(CFObj_t obj)
{
    struct CFInt64_t* _obj = (struct CFInt64_t*)obj;
    return _obj->var;
}

