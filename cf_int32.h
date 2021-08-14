#ifndef CF_INT32_H
#define CF_INT32_H

#include "cf_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

CFObj_t CFInt32_alloc(int32_t initial_value);

void CFInt32_set(CFObj_t obj, int32_t set_value);

int32_t CFInt32_get(CFObj_t obj);


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*CF_INT32_H*/