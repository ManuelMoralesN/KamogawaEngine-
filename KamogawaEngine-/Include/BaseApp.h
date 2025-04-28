#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "Swapchain.h"
#include "Texture.h"
#include "RenderTargetView.h"
#include "DepthStencilView.h"
#include "Viewport.h"
#include "ShaderProgram.h"
#include "Buffer.h"
#include "MeshComponent.h"
#include "SamplerState.h"
#include "UserInterface.h"
#include "ModelLoader.h"
#include "ECS/Actor.h"

/**
 * @brief Clase principal base para una aplicación gráfica.
 * Encapsula la lógica de inicialización, actualización, renderizado y destrucción.
 */
class 
BaseApp {
public:
    BaseApp() = default;
    ~BaseApp() = default;

    /**
     * @brief Inicializa los componentes necesarios para la aplicación.
     * @return HRESULT Indica si la inicialización fue exitosa.
     */
    HRESULT
    init();

    /**
     * @brief Actualiza el estado de la aplicación en cada ciclo.
     */
    void 
    update();

    /**
     * @brief Lógica de renderizado de cada frame.
     */
    void 
    render();

    /**
     * @brief Libera recursos y finaliza la aplicación.
     */
    void 
    destroy();

    /**
     * @brief Mapea las entradas del usuario y aplica acciones según el deltaTime.
     * @param deltaTime Tiempo transcurrido desde el último frame.
     */
    void 
    InputActionMap(float deltaTime);

    /**
     * @brief Maneja el evento de redimensionamiento de la ventana.
     * @param hWnd Manejador de la ventana.
     * @param lParam Parámetros del evento de redimensionamiento.
     * @return HRESULT Resultado del manejo.
     */
    HRESULT 
    resizeWindow(HWND hWnd, LPARAM lParam);

    /**
     * @brief Actualiza la cámara con base en las entradas o cambios del entorno.
     */
    void 
    updateCamera();

    /**
     * @brief Rota la cámara en función del movimiento del mouse.
     * @param mouseX Posición X del mouse.
     * @param mouseY Posición Y del mouse.
     */
    void 
    rotateCamera(int mouseX, int mouseY);

    /**
     * @brief Inicia la ejecución principal de la aplicación.
     * @param hInstance Instancia actual de la aplicación.
     * @param hPrevInstance Instancia anterior (usualmente nula).
     * @param lpCmdLine Línea de comandos.
     * @param nCmdShow Modo de visualización de la ventana.
     * @param wndproc Procedimiento de ventana.
     * @return int Código de retorno de la aplicación.
     */
    int run(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPWSTR lpCmdLine,
            int nCmdShow,
            WNDPROC wndproc);

public:
    Window                                          m_window;               ///< Objeto de la ventana principal.
    Device                                          m_device;               ///< Dispositivo de renderizado.
    DeviceContext                                   m_deviceContext;        ///< Contexto del dispositivo.
    SwapChain                                       m_swapchain;            ///< Cadena de intercambio para mostrar frames.
    Texture                                         m_backBuffer;           ///< Textura del back buffer.
    Texture                                         m_depthStencil;         ///< Textura del depth stencil.
    RenderTargetView                                m_renderTargetView;     ///< Vista del render target.
    DepthStencilView                                m_depthStencilView;     ///< Vista del depth stencil.
    Viewport                                        m_viewport;             ///< Viewport de renderizado.
    ShaderProgram                                   m_shaderProgram;        ///< Programa de shaders activo.
   
    Buffer                                          m_neverChanges;         ///< Buffer de constantes que no cambian.
    Buffer                                          m_changeOnResize;       ///< Buffer que cambia al redimensionar.
    Buffer                                          m_changeEveryFrame;     ///< Buffer que cambia cada frame.
 
    Camera                                          m_camera;               ///< Cámara principal.
    UserInterface                                   m_UI;                   ///< Interfaz de usuario.
   
    ModelLoader                                     m_model;
    EngineUtilities::TSharedPointer<Actor>          AModel;
    std::vector<Texture>                            m_modelTextures;

    ModelLoader                                     m_model2;
    EngineUtilities::TSharedPointer<Actor>          AModel2;
    std::vector<Texture>                            m_modelTextures2;

    ModelLoader                                     m_modelOBJ;
    EngineUtilities::TSharedPointer<Actor>          AModelOBJ;
    std::vector<Texture>                            m_modelTexturesOBJ;

    Texture                                         m_default;
 
    XMMATRIX                                        m_View;                 ///< Matriz de vista.
    XMMATRIX                                        m_Projection;           ///< Matriz de proyección.
    XMFLOAT4                                        m_vMeshColor;           ///< Color del mesh.
   
    CBNeverChanges                                  cbNeverChanges;         ///< Constantes que nunca cambian.
    CBChangeOnResize                                cbChangesOnResize;      ///< Constantes que cambian al redimensionar.

    bool keys[256] = { false };                     ///< Estado de las teclas del teclado.
    float sensitivity = 0.01f;                      ///< Sensibilidad para rotación de cámara.
    bool mouseLeftDown = false;                     ///< Estado del botón izquierdo del mouse.
    bool mouseRightDown = false;                    ///< Estado del botón derecho del mouse.
    int lastX;                                      ///< Última posición X del mouse.
    int lastY;                                      ///< Última posición Y del mouse.
};
