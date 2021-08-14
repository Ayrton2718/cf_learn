#ifndef CF_RUNTIME_H
#define CF_RUNTIME_H

#include "cf_type.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef void (*CFRuntime_destructorCallback_t)(CFObj_t obj);

struct CFRuntime_t
{
    size_t retain;
    size_t release;

    CFRuntime_destructorCallback_t destructor_callback;
};

CFObj_t CFRuntime_alloc(size_t size, CFRuntime_destructorCallback_t destructor_callback);

void CFRuntime_retain(CFObj_t obj);
void CFRuntime_release(CFObj_t obj);


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*CF_RUNTIME_H*/