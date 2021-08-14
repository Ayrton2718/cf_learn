#ifndef CF_RUNTIME_H
#define CF_RUNTIME_H

#include "cf_type.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

// これらの関数は、ユーザ（main.c）からは呼ばれてはならない。


// デストラクタの関数ポインタ変数
typedef void (*CFRuntime_destructorCallback_t)(CFObj_t obj);

// 全てのオブジェクトに共通する、オブジェクトを管理するための情報
struct CFRuntime_t
{
    size_t retain;  // 参照された回数
    size_t release; // 参照終わった回数

    CFRuntime_destructorCallback_t destructor_callback; // コールバック変数の関数ポインタ格納変数
};

// オブジェクトの基本クラスの作成
// size : オブジェクトの大きさ（構造体）。
// destructor_callback : デストラクタの関数ポインタ
CFObj_t CFRuntime_alloc(size_t size, CFRuntime_destructorCallback_t destructor_callback);


// オブジェクトの参照回数のカウントアップ
void CFRuntime_retain(CFObj_t obj);

// オブジェクトの参照回数のカウントダウン
// 参照している人がいない場合、オブジェクトを削除
void CFRuntime_release(CFObj_t obj);


#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /*CF_RUNTIME_H*/