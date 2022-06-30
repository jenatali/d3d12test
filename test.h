#pragma once

#ifndef _WIN32
#include <wsl/winadapter.h>
#endif

#include <stdio.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct IUnknown;
typedef HRESULT (*FnDXCoreCreateAdapterFactory)(REFIID, void**);
struct IUnknown *GetDXCoreAdapter(FnDXCoreCreateAdapterFactory create);

#if defined(__cplusplus)
}
#endif
