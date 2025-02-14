#pragma once
#include "Prerequisites.h"

/**
 * @class Device
 * @brief Clase encargada de la gesti�n del dispositivo Direct3D 11.
 *
 * Esta clase proporciona funciones para la creaci�n de recursos gr�ficos,
 * como shaders, buffers y texturas, adem�s de gestionar la inicializaci�n,
 * actualizaci�n y renderizado del dispositivo.
 */
class 
Device
{
public:
    /**
     * @brief Constructor por defecto.
     */
    Device() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Device() = default;

    /**
     * @brief Inicializa el dispositivo Direct3D.
     */
    void 
    init();

    /**
     * @brief Actualiza el estado del dispositivo si es necesario.
     */
    void 
    update();

    /**
     * @brief Renderiza la escena utilizando el dispositivo.
     */
    void 
    render();

    /**
     * @brief Libera los recursos del dispositivo antes de su destrucci�n.
     */
    void 
    destroy();

    /**
     * @brief Crea una vista de renderizado para un recurso.
     *
     * @param pResource Puntero al recurso de Direct3D.
     * @param pDesc Descripci�n de la vista de renderizado.
     * @param ppRTView Puntero de salida para la vista de renderizado creada.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateRenderTargetView(ID3D11Resource* pResource,
                                   const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
                                   ID3D11RenderTargetView** ppRTView);

    /**
     * @brief Crea una textura 2D en el dispositivo.
     *
     * @param pDesc Descripci�n de la textura.
     * @param pInitialData Datos iniciales para la textura (opcional).
     * @param ppTexture2D Puntero de salida para la textura creada.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
                            const D3D11_SUBRESOURCE_DATA* pInitialData,
                            ID3D11Texture2D** ppTexture2D);

    /**
     * @brief Crea una vista de profundidad y stencil para un recurso.
     *
     * @param pResource Puntero al recurso de Direct3D.
     * @param pDesc Descripci�n de la vista de profundidad y stencil.
     * @param ppDepthStencilView Puntero de salida para la vista creada.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateDepthStencilView(ID3D11Resource* pResource,
                                   const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
                                   ID3D11DepthStencilView** ppDepthStencilView);

    /**
     * @brief Crea un shader de v�rtices.
     *
     * @param pShaderBytecode C�digo de bytes del shader.
     * @param BytecodeLength Longitud del c�digo de bytes.
     * @param pClassLinkage Puntero opcional a una interfaz de enlace de clases.
     * @param ppVertexShader Puntero de salida para el shader de v�rtices creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateVertexShader(const void* pShaderBytecode,
                               unsigned int BytecodeLength,
                               ID3D11ClassLinkage* pClassLinkage,
                               ID3D11VertexShader** ppVertexShader);

    /**
     * @brief Crea un dise�o de entrada para el pipeline gr�fico.
     *
     * @param pInputElementDescs Descripci�n de los elementos de entrada.
     * @param NumElements N�mero de elementos en la descripci�n.
     * @param pShaderBytecodeWithInputSignature C�digo de bytes del shader con la firma de entrada.
     * @param BytecodeLength Longitud del c�digo de bytes.
     * @param ppInputLayout Puntero de salida para el dise�o de entrada creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateInputLayout(D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
                              unsigned int NumElements,
                              const void* pShaderBytecodeWithInputSignature,
                              unsigned int BytecodeLength,
                              ID3D11InputLayout** ppInputLayout);

    /**
     * @brief Crea un shader de p�xeles.
     *
     * @param pShaderBytecode C�digo de bytes del shader.
     * @param BytecodeLength Longitud del c�digo de bytes.
     * @param pClassLinkage Puntero opcional a una interfaz de enlace de clases.
     * @param ppPixelShader Puntero de salida para el shader de p�xeles creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreatePixelShader(const void* pShaderBytecode,
                              unsigned int BytecodeLength,
                              ID3D11ClassLinkage* pClassLinkage,
                              ID3D11PixelShader** ppPixelShader);

    /**
     * @brief Crea un buffer de datos en la GPU.
     *
     * @param pDesc Descripci�n del buffer.
     * @param pInitialData Datos iniciales del buffer (opcional).
     * @param ppBuffer Puntero de salida para el buffer creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
                         const D3D11_SUBRESOURCE_DATA* pInitialData,
                         ID3D11Buffer** ppBuffer);

    /**
     * @brief Crea un estado de muestreo para la configuraci�n de texturas.
     *
     * @param pSamplerDesc Descripci�n del estado de muestreo.
     * @param ppSamplerState Puntero de salida para el estado de muestreo creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
                               ID3D11SamplerState** ppSamplerState);

    /**
     * @brief Crea un estado de rasterizaci�n para configurar la forma en que se dibujan los tri�ngulos.
     *
     * @param pRasterizerDesc Descripci�n del estado de rasterizaci�n.
     * @param ppRasterizerState Puntero de salida para el estado de rasterizaci�n creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
                                  ID3D11RasterizerState** ppRasterizerState);

    /**
     * @brief Crea un estado de mezcla para configurar la mezcla de colores en el renderizado.
     *
     * @param pBlendStateDesc Descripci�n del estado de mezcla.
     * @param ppBlendState Puntero de salida para el estado de mezcla creado.
     * @return HRESULT C�digo de estado indicando �xito o fallo.
     */
    HRESULT 
    CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc,
                             ID3D11BlendState** ppBlendState);

public:
    /// Puntero a la interfaz ID3D11Device que representa el dispositivo Direct3D.
    ID3D11Device* m_device = nullptr;
};
