#ifndef CF_INT64_H
#define CF_INT64_H

#include "cf_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

CFObj_t CFInt64_alloc(int64_t initial_value);

void CFInt64_set(CFObj_t obj, int64_t set_value);

int64_t CFInt64_get(CFObj_t obj);


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*CF_INT64_H*/