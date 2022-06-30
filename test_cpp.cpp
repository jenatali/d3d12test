#include "test.h"

#include <directx/dxcore.h>
#include <dxguids/dxguids.h>
#include <wsl/wrladapter.h>

using Microsoft::WRL::ComPtr;

#define VERIFY_SUCCEEDED(expr) hr = (expr); if (FAILED(hr)) { printf("FAILED: %s: 0x%x\n", #expr, hr); return nullptr; } else { printf("Succeeded: %s\n", #expr); }
extern "C" IUnknown *GetDXCoreAdapter(FnDXCoreCreateAdapterFactory pfnDXCoreCreateAdapterFactory)
{
    HRESULT hr = S_OK;

    ComPtr<IDXCoreAdapterFactory> spFactory;
    VERIFY_SUCCEEDED(pfnDXCoreCreateAdapterFactory(IID_PPV_ARGS(&spFactory)));
    ComPtr<IDXCoreAdapterList> spList;
    VERIFY_SUCCEEDED(spFactory->CreateAdapterList(1, &DXCORE_ADAPTER_ATTRIBUTE_D3D12_CORE_COMPUTE, IID_PPV_ARGS(&spList)));
    ComPtr<IDXCoreAdapter> spAdapter;
    VERIFY_SUCCEEDED(spList->GetAdapter(0, IID_PPV_ARGS(&spAdapter)));

    return spAdapter.Detach();
}