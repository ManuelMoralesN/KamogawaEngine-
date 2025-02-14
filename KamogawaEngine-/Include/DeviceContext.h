#pragma once
#include "PreRequisites.h"

/**
 * @class DeviceContext
 * @brief Clase que gestiona el contexto del dispositivo Direct3D 11.
 *
 * Proporciona métodos para configurar y ejecutar operaciones de renderizado
 * en el pipeline gráfico de Direct3D.
 */
    class 
    DeviceContext {
    public:
    /**
     * @brief Constructor por defecto.
     */
    DeviceContext() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~DeviceContext() = default;

    /**
     * @brief Inicializa el contexto del dispositivo.
     */
    void 
    init();

    /**
     * @brief Actualiza los estados del contexto del dispositivo.
     */
    void 
    update();

    /**
     * @brief Realiza operaciones de renderizado utilizando el contexto del dispositivo.
     */
    void 
    render();

    /**
     * @brief Libera los recursos del contexto del dispositivo.
     */
    void 
    destroy();

    /**
     * @brief Establece las vistas de la pantalla.
     *
     * @param NumViewports Número de viewports a establecer.
     * @param pViewports Puntero a los viewports.
     */
    void 
    RSSetViewports(unsigned int NumViewports, 
                   const D3D11_VIEWPORT* pViewports);

    /**
     * @brief Asigna recursos de textura a la etapa de píxeles del pipeline.
     *
     * @param StartSlot Primer slot en el que se asignará el recurso.
     * @param NumViews Número de vistas a asignar.
     * @param ppShaderResourceViews Puntero a la lista de vistas de recursos de shader.
     */
    void 
    PSSetShaderResources(unsigned int StartSlot,
                              unsigned int NumViews,
                              ID3D11ShaderResourceView* const* ppShaderResourceViews);

    /**
     * @brief Establece el diseño de entrada para la etapa de entrada del ensamblador.
     *
     * @param pInputLayout Puntero al diseño de entrada.
     */
    void 
    IASetInputLayout(ID3D11InputLayout* pInputLayout);

    /**
     * @brief Establece el shader de vértices en el pipeline.
     *
     * @param pVertexShader Puntero al shader de vértices.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances Número de instancias de clase.
     */
    void 
    VSSetShader(ID3D11VertexShader* pVertexShader,
                ID3D11ClassInstance* const* ppClassInstances,
                unsigned int NumClassInstances);

    /**
     * @brief Establece el shader de píxeles en el pipeline.
     *
     * @param pPixelShader Puntero al shader de píxeles.
     * @param ppClassInstances Lista de instancias de clase.
     * @param NumClassInstances Número de instancias de clase.
     */
    void 
    PSSetShader(ID3D11PixelShader* pPixelShader,
                ID3D11ClassInstance* const* ppClassInstances,
                unsigned int NumClassInstances);

    /**
     * @brief Actualiza los datos de un recurso en la GPU.
     *
     * @param pDstResource Recurso de destino.
     * @param DstSubresource Subrecurso de destino.
     * @param pDstBox Región de destino a actualizar (opcional).
     * @param pSrcData Datos de origen.
     * @param SrcRowPitch Desplazamiento por fila.
     * @param SrcDepthPitch Desplazamiento por profundidad.
     */
    void 
    UpdateSubresource(ID3D11Resource* pDstResource,
                      unsigned int DstSubresource,
                      const D3D11_BOX* pDstBox,
                      const void* pSrcData,
                      unsigned int SrcRowPitch,
                      unsigned int SrcDepthPitch);

    /**
     * @brief Asigna buffers de vértices al pipeline gráfico.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers Número de buffers.
     * @param ppVertexBuffers Puntero a los buffers de vértices.
     * @param pStrides Tamaño de cada vértice en los buffers.
     * @param pOffsets Desplazamiento inicial en los buffers.
     */
    void 
    IASetVertexBuffers(unsigned int StartSlot,
                       unsigned int NumBuffers,
                       ID3D11Buffer* const* ppVertexBuffers,
                       const unsigned int* pStrides,
                       const unsigned int* pOffsets);

    /**
     * @brief Asigna un buffer de índices al pipeline gráfico.
     *
     * @param pIndexBuffer Puntero al buffer de índices.
     * @param Format Formato de los índices.
     * @param Offset Desplazamiento dentro del buffer.
     */
    void 
    IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
                     DXGI_FORMAT Format,
                     unsigned int Offset);

    /**
     * @brief Establece los estados de muestreo en la etapa de píxeles.
     *
     * @param StartSlot Primer slot del sampler.
     * @param NumSamplers Número de estados de muestreo.
     * @param ppSamplers Puntero a los estados de muestreo.
     */
    void 
    PSSetSamplers(unsigned int StartSlot,
                  unsigned int NumSamplers,
                  ID3D11SamplerState* const* ppSamplers);

    /**
     * @brief Configura el estado de rasterización.
     *
     * @param pRasterizerState Puntero al estado de rasterización.
     */
    void 
    RSSetState(ID3D11RasterizerState* pRasterizerState);

    /**
     * @brief Configura el estado de mezcla para la etapa de salida.
     *
     * @param pBlendState Puntero al estado de mezcla.
     * @param BlendFactor Factores de mezcla de color.
     * @param SampleMask Máscara de muestreo.
     */
    void 
    OMSetBlendState(ID3D11BlendState* pBlendState,
                    const float BlendFactor[4],
                    unsigned int SampleMask);

    /**
     * @brief Establece los objetivos de renderizado y el buffer de profundidad.
     *
     * @param NumViews Número de vistas de renderizado.
     * @param ppRenderTargetViews Puntero a la lista de vistas de renderizado.
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     */
    void 
    OMSetRenderTargets(unsigned int NumViews,
                       ID3D11RenderTargetView* const* ppRenderTargetViews,
                       ID3D11DepthStencilView* pDepthStencilView);

    /**
     * @brief Establece la topología primitiva utilizada en el pipeline.
     *
     * @param Topology Tipo de topología de primitivas.
     */
    void 
    IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

    /**
     * @brief Limpia una vista de renderizado con un color específico.
     *
     * @param pRenderTargetView Puntero a la vista de renderizado.
     * @param ColorRGBA Color en formato RGBA.
     */
    void 
    ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
                          const float ColorRGBA[4]);

    /**
     * @brief Limpia el buffer de profundidad y stencil.
     *
     * @param pDepthStencilView Puntero a la vista de profundidad y stencil.
     * @param ClearFlags Flags que indican qué limpiar (profundidad/stencil).
     * @param Depth Valor de profundidad a establecer.
     * @param Stencil Valor de stencil a establecer.
     */
    void 
    ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
                          unsigned int ClearFlags,
                          float Depth,
                          UINT8 Stencil);

    /**
     * @brief Asigna buffers constantes a la etapa de vértices.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers Número de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
    void 
    VSSetConstantBuffers(unsigned int StartSlot,
                         unsigned int NumBuffers,
                         ID3D11Buffer* const* ppConstantBuffers);

    /**
     * @brief Asigna buffers constantes a la etapa de píxeles.
     *
     * @param StartSlot Primer slot del buffer.
     * @param NumBuffers Número de buffers.
     * @param ppConstantBuffers Puntero a los buffers constantes.
     */
    void 
    PSSetConstantBuffers(unsigned int StartSlot,
                         unsigned int NumBuffers,
                         ID3D11Buffer* const* ppConstantBuffers);

    /**
     * @brief Dibuja los elementos indexados.
     *
     * @param IndexCount Número de índices.
     * @param StartIndexLocation Ubicación inicial del índice.
     * @param BaseVertexLocation Ubicación base del vértice.
     */
    void 
    DrawIndexed(unsigned int IndexCount,
                unsigned int StartIndexLocation,
                int BaseVertexLocation);

public:
    /// Puntero al contexto del dispositivo Direct3D.
    ID3D11DeviceContext* m_deviceContext = nullptr;
};
