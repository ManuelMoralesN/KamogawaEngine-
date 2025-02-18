#include "Viewport.h"
#include "Window.h"
#include "DeviceContext.h"

HRESULT 
Viewport::init(const Window& window){
    if (window.m_width == 0 || window.m_height == 0) {
        ERROR("Viewport", "init", "Window dimensions are invalid");
        return E_POINTER;
    }
    return init(static_cast<unsigned int>(window.m_width),
                static_cast<unsigned int>(window.m_height));
}

HRESULT
Viewport::init(unsigned int width, unsigned int height){
    if (width == 0 || height == 0) {
        ERROR("Viewport", "init", "Width or height is zero");
        return E_POINTER;
    }
    m_viewport.Width = static_cast<float>(width);
    m_viewport.Height = static_cast<float>(height);
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0.0f;
    m_viewport.TopLeftY = 0.0f;

    return S_OK;
}

void 
Viewport::update(){
  
}

void 
Viewport::render(DeviceContext& deviceContext){
    if (!deviceContext.m_deviceContext) {
        ERROR("Viewport", "render", "DeviceContext is nullptr");
        return;
    }
    deviceContext.RSSetViewports(1, &m_viewport);
}

void 
Viewport::destroy(){
 
}
