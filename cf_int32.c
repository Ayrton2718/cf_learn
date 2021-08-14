#include "cf_int32.h"

struct CFInt32_t
{
    struct CFRuntime_t runtime;

    int32_t var;
};


static void CFInt32_destructorCallback(CFObj_t obj)
{
    printf("[Debug] CFInt32 Destructing!\n");
    return;
}

CFObj_t CFInt32_alloc(int32_t initial_value)
{
    struct CFInt32_t* _obj = CFRuntime_alloc(sizeof(struct CFInt32_t), CFInt32_destructorCallback);
    _obj->var = initial_value;
    return _obj;
}


void CFInt32_set(CFObj_t obj, int32_t set_value)
{
    struct CFInt32_t* _obj = (struct CFInt32_t*)obj;
    _obj->var = set_value;
}


int32_t CFInt32_get(CFObj_t obj)
{
    struct CFInt32_t* _obj = (struct CFInt32_t*)obj;
    return _obj->var;
}

