#pragma once
#include "Prerequisites.h"

class 
Device;
class 
DeviceContext;
class 
Texture;
class 
DepthStencilView;

/**
 * @class RenderTargetView
 * @brief Clase que representa una vista de renderizado en Direct3D 11.
 *
 * Se encarga de gestionar un ID3D11RenderTargetView, que se utiliza
 * para representar la superficie de renderizado a la que se dibujarán los gráficos.
 */
class 
RenderTargetView {
public:
    /**
     * @brief Constructor por defecto.
     */
    RenderTargetView() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~RenderTargetView() = default;

    /**
     * @brief Inicializa la vista de renderizado.
     *
     * @param device Referencia al dispositivo Direct3D utilizado para la creación.
     * @param backBuffer Referencia a la textura del back buffer.
     * @param Format Formato de la vista de renderizado (DXGI_FORMAT).
     * @return HRESULT Código de resultado indicando éxito o error en la operación.
     */
    HRESULT 
    init(Device& device, 
         Texture& backBuffer, 
         DXGI_FORMAT Format);

    /**
     * @brief Actualiza la vista de renderizado si es necesario.
     */
    void 
    update();

    /**
     * @brief Renderiza la escena utilizando la vista de renderizado.
     *
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param depthStencilView Referencia a la vista de profundidad y stencil.
     * @param numViews Número de vistas a establecer en el pipeline de renderizado.
     * @param ClearColor Color utilizado para limpiar la vista de renderizado.
     */
    void 
    render(DeviceContext& deviceContext,
           DepthStencilView& depthStencilView,
           unsigned int numViews,
           const float ClearColor[4]);

    /**
     * @brief Libera los recursos asociados con la vista de renderizado.
     */
    void 
    destroy();

public:
    /// Puntero a la interfaz ID3D11RenderTargetView que representa la vista de renderizado.
    ID3D11RenderTargetView* m_renderTargetView = nullptr;
};
