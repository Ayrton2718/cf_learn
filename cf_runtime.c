#include "cf_runtime.h"

#include <stdlib.h>

CFObj_t CFRuntime_alloc(size_t size, CFRuntime_destructorCallback_t destructor_callback)
{
    struct CFRuntime_t* _obj = (struct CFRuntime_t*)malloc(size);
    _obj->retain = 0;
    _obj->release = 0;
    _obj->destructor_callback = destructor_callback;
    printf("[Debug] Object maked!\n");
    return _obj;
}

void CFRuntime_retain(CFObj_t obj)
{
    struct CFRuntime_t* _obj = (struct CFRuntime_t*)obj;
    _obj->retain++;
    printf("[Debug] Object retain!\n");
}

void CFRuntime_release(CFObj_t obj)
{
    struct CFRuntime_t* _obj = (struct CFRuntime_t*)obj;
    _obj->release++;
    if(_obj->retain <= _obj->release)
    {
        _obj->destructor_callback(_obj);
        free(_obj);
        printf("[Debug] Object Destructed!\n");
    }
}
