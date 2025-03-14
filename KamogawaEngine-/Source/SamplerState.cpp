#include "SamplerState.h"
#include "Device.h"
#include "DeviceContext.h"

HRESULT
SamplerState::init(Device& device) {
    if (!device.m_device) {
        ERROR("SamplerState", "init", "Device is nullptr");
        return E_POINTER;
    }

    D3D11_SAMPLER_DESC sampDesc;
    ZeroMemory(&sampDesc, sizeof(sampDesc));
    sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

    HRESULT hr = device.CreateSamplerState(&sampDesc, &m_samplerState);
    if (FAILED(hr)) {
        ERROR("SamplerState", "init", "Failed to create SamplerState");
    }
    return hr;
}

void
SamplerState::update() {
}

void
SamplerState::render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int numSampler) {
    if (!m_samplerState) {
        ERROR("SamplerState", "render", "SamplerState is nullptr");
        return;
    }
    if (!deviceContext.m_deviceContext) {
        ERROR("SamplerState", "render", "DeviceContext is nullptr");
        return;
    }
    deviceContext.PSSetSamplers(StartSlot, 1, &m_samplerState);
}

void
SamplerState::destroy() {
    SAFE_RELEASE(m_samplerState);
}
