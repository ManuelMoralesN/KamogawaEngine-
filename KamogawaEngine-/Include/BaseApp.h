#pragma once
#include "Prerequisites.h"

/**
 * Clase base para la aplicación principal.
 * Gestiona la inicialización, actualización, renderización y destrucción de la aplicación.
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
     * Inicializa la aplicación.
     *
     * @return HRESULT indicando el éxito o fallo de la inicialización.
     */
    HRESULT init();

    /**
     * Actualiza la lógica de la aplicación en cada frame.
     */
    void update();

    /**
     * Renderiza el contenido gráfico de la aplicación.
     */
    void render();

    /**
     * Libera los recursos utilizados por la aplicación.
     */
    void destroy();

    /**
     * Ejecuta la aplicación.
     *
     * @param hInstance Instancia de la aplicación.
     * @param hPrevInstance Instancia previa de la aplicación (normalmente nula en Windows modernos).
     * @param lpCmdLine Línea de comandos pasada a la aplicación.
     * @param nCmdShow Parámetro para mostrar la ventana.
     * @param wndproc Procedimiento de la ventana.
     * @return Código de retorno de la ejecución.
     */
    int run(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR lpCmdLine,
        int nCmdShow,
        WNDPROC wndproc);

private:
    // Variables privadas de la clase (a definir según necesidades).
};
