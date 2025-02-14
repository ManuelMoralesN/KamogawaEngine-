#pragma once
#include "PreRequisites.h"

class 
Device;
class 
DeviceContext;
class 
Texture;

/**
 * @class DepthStencilView
 * @brief Clase que representa una vista de profundidad y stencil en DirectX 11.
 *
 * Esta clase encapsula un ID3D11DepthStencilView, que se usa para gestionar
 * los buffers de profundidad y stencil en una aplicaci�n de gr�ficos.
 */
    class 
    DepthStencilView {
    public:
    /**
     * @brief Constructor por defecto.
     */
    DepthStencilView() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~DepthStencilView() = default;

    /**
     * @brief Inicializa la vista de profundidad y stencil.
     *
     * @param device Referencia al dispositivo Direct3D que crear� la vista.
     * @param depthStencil Referencia a la textura que actuar� como buffer de profundidad y stencil.
     * @param format Formato del buffer de profundidad y stencil (DXGI_FORMAT).
     * @return HRESULT C�digo de resultado que indica el �xito o error de la operaci�n.
     */
    HRESULT 
    init(Device& device, 
        Texture& depthStencil, 
        DXGI_FORMAT format);

    /**
     * @brief Actualiza la vista de profundidad y stencil si es necesario.
     *
     * Esta funci�n se puede utilizar para realizar cambios din�micos en la vista si el
     * contexto de la aplicaci�n lo requiere.
     */
    void 
    update();

    /**
     * @brief Vincula la vista de profundidad y stencil al contexto del dispositivo.
     *
     * @param deviceContext Referencia al contexto del dispositivo en el que se aplicar� la vista.
     */
    void 
    render(DeviceContext& deviceContext);

    /**
     * @brief Libera los recursos asociados con la vista de profundidad y stencil.
     *
     * Esta funci�n debe llamarse antes de la destrucci�n de la clase para evitar p�rdidas de memoria.
     */
    void 
    destroy();

public:
    /// Puntero a la interfaz ID3D11DepthStencilView que representa la vista de profundidad y stencil.
    ID3D11DepthStencilView* m_depthStencilView = nullptr;
};
