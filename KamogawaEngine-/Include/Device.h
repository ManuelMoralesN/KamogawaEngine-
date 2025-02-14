#pragma once
#include "Prerequisites.h"

/**
 * @class Device
 * @brief Clase encargada de la gestión del dispositivo Direct3D 11.
 *
 * Esta clase proporciona funciones para la creación de recursos gráficos,
 * como shaders, buffers y texturas, además de gestionar la inicialización,
 * actualización y renderizado del dispositivo.
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
     * @brief Libera los recursos del dispositivo antes de su destrucción.
     */
    void 
    destroy();

    /**
     * @brief Crea una vista de renderizado para un recurso.
     *
     * @param pResource Puntero al recurso de Direct3D.
     * @param pDesc Descripción de la vista de renderizado.
     * @param ppRTView Puntero de salida para la vista de renderizado creada.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateRenderTargetView(ID3D11Resource* pResource,
                                   const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
                                   ID3D11RenderTargetView** ppRTView);

    /**
     * @brief Crea una textura 2D en el dispositivo.
     *
     * @param pDesc Descripción de la textura.
     * @param pInitialData Datos iniciales para la textura (opcional).
     * @param ppTexture2D Puntero de salida para la textura creada.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
                            const D3D11_SUBRESOURCE_DATA* pInitialData,
                            ID3D11Texture2D** ppTexture2D);

    /**
     * @brief Crea una vista de profundidad y stencil para un recurso.
     *
     * @param pResource Puntero al recurso de Direct3D.
     * @param pDesc Descripción de la vista de profundidad y stencil.
     * @param ppDepthStencilView Puntero de salida para la vista creada.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateDepthStencilView(ID3D11Resource* pResource,
                                   const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
                                   ID3D11DepthStencilView** ppDepthStencilView);

    /**
     * @brief Crea un shader de vértices.
     *
     * @param pShaderBytecode Código de bytes del shader.
     * @param BytecodeLength Longitud del código de bytes.
     * @param pClassLinkage Puntero opcional a una interfaz de enlace de clases.
     * @param ppVertexShader Puntero de salida para el shader de vértices creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateVertexShader(const void* pShaderBytecode,
                               unsigned int BytecodeLength,
                               ID3D11ClassLinkage* pClassLinkage,
                               ID3D11VertexShader** ppVertexShader);

    /**
     * @brief Crea un diseño de entrada para el pipeline gráfico.
     *
     * @param pInputElementDescs Descripción de los elementos de entrada.
     * @param NumElements Número de elementos en la descripción.
     * @param pShaderBytecodeWithInputSignature Código de bytes del shader con la firma de entrada.
     * @param BytecodeLength Longitud del código de bytes.
     * @param ppInputLayout Puntero de salida para el diseño de entrada creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateInputLayout(D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
                              unsigned int NumElements,
                              const void* pShaderBytecodeWithInputSignature,
                              unsigned int BytecodeLength,
                              ID3D11InputLayout** ppInputLayout);

    /**
     * @brief Crea un shader de píxeles.
     *
     * @param pShaderBytecode Código de bytes del shader.
     * @param BytecodeLength Longitud del código de bytes.
     * @param pClassLinkage Puntero opcional a una interfaz de enlace de clases.
     * @param ppPixelShader Puntero de salida para el shader de píxeles creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreatePixelShader(const void* pShaderBytecode,
                              unsigned int BytecodeLength,
                              ID3D11ClassLinkage* pClassLinkage,
                              ID3D11PixelShader** ppPixelShader);

    /**
     * @brief Crea un buffer de datos en la GPU.
     *
     * @param pDesc Descripción del buffer.
     * @param pInitialData Datos iniciales del buffer (opcional).
     * @param ppBuffer Puntero de salida para el buffer creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
                         const D3D11_SUBRESOURCE_DATA* pInitialData,
                         ID3D11Buffer** ppBuffer);

    /**
     * @brief Crea un estado de muestreo para la configuración de texturas.
     *
     * @param pSamplerDesc Descripción del estado de muestreo.
     * @param ppSamplerState Puntero de salida para el estado de muestreo creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
                               ID3D11SamplerState** ppSamplerState);

    /**
     * @brief Crea un estado de rasterización para configurar la forma en que se dibujan los triángulos.
     *
     * @param pRasterizerDesc Descripción del estado de rasterización.
     * @param ppRasterizerState Puntero de salida para el estado de rasterización creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateRasterizerState(const D3D11_RASTERIZER_DESC* pRasterizerDesc,
                                  ID3D11RasterizerState** ppRasterizerState);

    /**
     * @brief Crea un estado de mezcla para configurar la mezcla de colores en el renderizado.
     *
     * @param pBlendStateDesc Descripción del estado de mezcla.
     * @param ppBlendState Puntero de salida para el estado de mezcla creado.
     * @return HRESULT Código de estado indicando éxito o fallo.
     */
    HRESULT 
    CreateBlendState(const D3D11_BLEND_DESC* pBlendStateDesc,
                             ID3D11BlendState** ppBlendState);

public:
    /// Puntero a la interfaz ID3D11Device que representa el dispositivo Direct3D.
    ID3D11Device* m_device = nullptr;
};
