#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Swapchain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "Buffer.h"
#include "MeshComponent.h"
#include "SamplerState.h"

class 
BaseApp {
public:
    BaseApp() = default;
    ~BaseApp() = default;

    
    HRESULT 
    init();
    
    void 
    update();

    void 
    render();

    void 
    destroy();

    void
    InputActionMap(float deltaTime);


    HRESULT
    resizeWindow(HWND hWnd, LPARAM lParam);

    void
    updateCamera();

    void
    rotateCamera(int mouseX, int mouseY);

    int run(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPWSTR lpCmdLine,
            int nCmdShow,
            WNDPROC wndproc);

public:     
    Window                                          m_window;
    Device                                          m_device;
    DeviceContext                                   m_deviceContext;
    SwapChain                                       m_swapchain;
    Texture                                         m_backBuffer;
    Texture                                         m_depthStencil;
    RenderTargetView                                m_renderTargetView;
    DepthStencilView                                m_depthStencilView;
    Viewport                                        m_viewport;
    ShaderProgram                                   m_shaderProgram;
    Buffer                                          m_vertexBuffer;
    Buffer                                          m_indexBuffer;
    Buffer                                          m_neverChanges;
    Buffer                                          m_changeOnResize;
    Buffer                                          m_changeEveryFrame;
    Texture											m_textureCubeImg;
    SamplerState									m_samplerState;
    Camera                                          m_camera;
    XMMATRIX                                        m_modelMatrix;
    XMMATRIX                                        m_View;
    XMMATRIX                                        m_Projection;
    XMFLOAT4                                        m_vMeshColor;
    XMFLOAT3                                        position;  
    XMFLOAT3                                        rotation;  
    XMFLOAT3                                        scale;     
    MeshComponent                                   m_meshComponent;
    CBChangesEveryFrame                             cb;
    CBNeverChanges                                  cbNeverChanges;
    CBChangeOnResize                                cbChangesOnResize;
    
    bool keys[256] = { false };
    float sensitivity = 0.01f;
    bool mouseLeftDown = false; 
    int lastX;
    int lastY;  
    
};
