#pragma once
#include "Prerequisites.h"

// Forward Declarations - Declaraciones previas
class 
Device;
class 
DeviceContext;
class 
Window;
class 
Texture;

/**
 * @class SwapChain
 * @brief Clase que gestiona la cadena de intercambio de Direct3D 11.
 *
 * La cadena de intercambio es responsable de la presentaci�n de im�genes en pantalla,
 * permitiendo la renderizaci�n en un buffer y su posterior visualizaci�n.
 */
class 
SwapChain {
public:
    /**
     * @brief Constructor por defecto.
     */
    SwapChain() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~SwapChain() = default;

    /**
     * @brief Inicializa la cadena de intercambio.
     *
     * @param device Referencia al dispositivo Direct3D utilizado.
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param backBuffer Referencia a la textura del back buffer.
     * @param window Referencia a la ventana de renderizado.
     * @return HRESULT C�digo de resultado indicando �xito o error en la operaci�n.
     */
    HRESULT init(Device& device,
                 DeviceContext& deviceContext,
                 Texture& backBuffer,
                 Window window);

    /**
     * @brief Actualiza los par�metros de la cadena de intercambio si es necesario.
     */
    void 
    update();

    /**
     * @brief Renderiza el contenido en el buffer de la cadena de intercambio.
     */
    void 
    render();

    /**
     * @brief Libera los recursos asociados con la cadena de intercambio.
     */
    void 
    destroy();

    /**
     * @brief Presenta el buffer trasero en la pantalla.
     *
     * Se encarga de intercambiar el buffer trasero con el buffer frontal para mostrar la imagen renderizada.
     */
    void 
    present();

public:
    /// Puntero a la interfaz IDXGISwapChain que representa la cadena de intercambio.
    IDXGISwapChain* m_swapchain = nullptr;

    /// Tipo de driver utilizado por Direct3D.
    D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
    /// Nivel de caracter�sticas de Direct3D utilizado (por defecto 11.0).
    D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

    /// N�mero de muestras utilizadas para el antialiasing.
    unsigned int m_sampleCount;

    /// Niveles de calidad de las muestras de antialiasing.
    unsigned int m_qualityLevels;

    // Punteros a las interfaces DXGI para la gesti�n de dispositivos y adaptadores gr�ficos.

    /// Puntero a la interfaz IDXGIDevice para la gesti�n del dispositivo DXGI.
    IDXGIDevice* m_dxgiDevice = nullptr;

    /// Puntero a la interfaz IDXGIAdapter para la gesti�n del adaptador gr�fico.
    IDXGIAdapter* m_dxgiAdapter = nullptr;

    /// Puntero a la interfaz IDXGIFactory para la creaci�n de la cadena de intercambio.
    IDXGIFactory* m_dxgiFactory = nullptr;
};
