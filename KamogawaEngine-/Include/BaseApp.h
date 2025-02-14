#pragma once
#include "Prerequisites.h"

/**
 * Clase base para la aplicaci�n principal.
 * Gestiona la inicializaci�n, actualizaci�n, renderizaci�n y destrucci�n de la aplicaci�n.
 */
class BaseApp {
public:
    /**
     * Constructor por defecto.
     */
    BaseApp() = default;

    /**
     * Destructor por defecto.
     */
    ~BaseApp() = default;

    /**
     * Inicializa la aplicaci�n.
     *
     * @return HRESULT indicando el �xito o fallo de la inicializaci�n.
     */
    HRESULT init();

    /**
     * Actualiza la l�gica de la aplicaci�n en cada frame.
     */
    void update();

    /**
     * Renderiza el contenido gr�fico de la aplicaci�n.
     */
    void render();

    /**
     * Libera los recursos utilizados por la aplicaci�n.
     */
    void destroy();

    /**
     * Ejecuta la aplicaci�n.
     *
     * @param hInstance Instancia de la aplicaci�n.
     * @param hPrevInstance Instancia previa de la aplicaci�n (normalmente nula en Windows modernos).
     * @param lpCmdLine L�nea de comandos pasada a la aplicaci�n.
     * @param nCmdShow Par�metro para mostrar la ventana.
     * @param wndproc Procedimiento de la ventana.
     * @return C�digo de retorno de la ejecuci�n.
     */
    int run(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR lpCmdLine,
        int nCmdShow,
        WNDPROC wndproc);

private:
    // Variables privadas de la clase (a definir seg�n necesidades).
};
