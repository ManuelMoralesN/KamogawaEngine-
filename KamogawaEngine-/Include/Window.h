#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Clase que gestiona una ventana en Windows para renderizado con Direct3D.
 *
 * Se encarga de la creaci�n, actualizaci�n, renderizado y destrucci�n de la ventana de la aplicaci�n.
 */
class 
Window {
public:
    /**
     * @brief Constructor por defecto.
     */
    Window() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Window() = default;

    /**
     * @brief Inicializa la ventana de la aplicaci�n.
     *
     * @param hInstance Identificador de la instancia de la aplicaci�n.
     * @param nCmdShow Par�metro de control de visualizaci�n de la ventana.
     * @param wndproc Puntero a la funci�n de procedimiento de ventana.
     * @return HRESULT C�digo de resultado indicando �xito o error en la operaci�n.
     */
    HRESULT init(HINSTANCE hInstance, 
                 int nCmdShow, 
                 WNDPROC wndproc);

    /**
     * @brief Actualiza los estados de la ventana si es necesario.
     */
    void 
    update();

    /**
     * @brief Renderiza el contenido de la ventana.
     */
    void 
    render();

    /**
     * @brief Libera los recursos asociados con la ventana.
     */
    void 
    destroy();

public:
    /// Identificador de la ventana en el sistema operativo.
    HWND m_hWnd = nullptr;

    /// Ancho de la ventana en p�xeles.
    unsigned int m_width;

    /// Alto de la ventana en p�xeles.
    unsigned int m_height;

private:
    /// Identificador de la instancia de la aplicaci�n.
    HINSTANCE m_hInst = nullptr;

    /// Estructura que define los l�mites de la ventana.
    RECT m_rect;

    /// Nombre de la ventana.
    std::string m_windowName = "Kamogawa Engine";
};
