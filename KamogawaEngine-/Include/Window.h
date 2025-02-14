#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Clase que gestiona una ventana en Windows para renderizado con Direct3D.
 *
 * Se encarga de la creación, actualización, renderizado y destrucción de la ventana de la aplicación.
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
     * @brief Inicializa la ventana de la aplicación.
     *
     * @param hInstance Identificador de la instancia de la aplicación.
     * @param nCmdShow Parámetro de control de visualización de la ventana.
     * @param wndproc Puntero a la función de procedimiento de ventana.
     * @return HRESULT Código de resultado indicando éxito o error en la operación.
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

    /// Ancho de la ventana en píxeles.
    unsigned int m_width;

    /// Alto de la ventana en píxeles.
    unsigned int m_height;

private:
    /// Identificador de la instancia de la aplicación.
    HINSTANCE m_hInst = nullptr;

    /// Estructura que define los límites de la ventana.
    RECT m_rect;

    /// Nombre de la ventana.
    std::string m_windowName = "Kamogawa Engine";
};
