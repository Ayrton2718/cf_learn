#ifndef CF_INT64_H
#define CF_INT64_H

#include "cf_runtime.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

// 64ビット整数型オブジェクトの生成
// initial_value : 初期値
CFObj_t CFInt64_alloc(int64_t initial_value);

// 64ビット整数型オブジェクト
// obj : CFInt64_allocで生成したオブジェクト
// set_value : objの中に保存されている値を変える。
void CFInt64_set(CFObj_t obj, int64_t set_value);

// 64ビット整数型オブジェクト
// 内包されている値を表示。
int64_t CFInt64_get(CFObj_t obj);


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*CF_INT64_H*/