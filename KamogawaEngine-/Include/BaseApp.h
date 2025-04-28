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
 * @brief Clase principal base para una aplicaci�n gr�fica.
 * Encapsula la l�gica de inicializaci�n, actualizaci�n, renderizado y destrucci�n.
 */
class 
BaseApp {
public:
    BaseApp() = default;
    ~BaseApp() = default;

    /**
     * @brief Inicializa los componentes necesarios para la aplicaci�n.
     * @return HRESULT Indica si la inicializaci�n fue exitosa.
     */
    HRESULT
    init();

    /**
     * @brief Actualiza el estado de la aplicaci�n en cada ciclo.
     */
    void 
    update();

    /**
     * @brief L�gica de renderizado de cada frame.
     */
    void 
    render();

    /**
     * @brief Libera recursos y finaliza la aplicaci�n.
     */
    void 
    destroy();

    /**
     * @brief Mapea las entradas del usuario y aplica acciones seg�n el deltaTime.
     * @param deltaTime Tiempo transcurrido desde el �ltimo frame.
     */
    void 
    InputActionMap(float deltaTime);

    /**
     * @brief Maneja el evento de redimensionamiento de la ventana.
     * @param hWnd Manejador de la ventana.
     * @param lParam Par�metros del evento de redimensionamiento.
     * @return HRESULT Resultado del manejo.
     */
    HRESULT 
    resizeWindow(HWND hWnd, LPARAM lParam);

    /**
     * @brief Actualiza la c�mara con base en las entradas o cambios del entorno.
     */
    void 
    updateCamera();

    /**
     * @brief Rota la c�mara en funci�n del movimiento del mouse.
     * @param mouseX Posici�n X del mouse.
     * @param mouseY Posici�n Y del mouse.
     */
    void 
    rotateCamera(int mouseX, int mouseY);

    /**
     * @brief Inicia la ejecuci�n principal de la aplicaci�n.
     * @param hInstance Instancia actual de la aplicaci�n.
     * @param hPrevInstance Instancia anterior (usualmente nula).
     * @param lpCmdLine L�nea de comandos.
     * @param nCmdShow Modo de visualizaci�n de la ventana.
     * @param wndproc Procedimiento de ventana.
     * @return int C�digo de retorno de la aplicaci�n.
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
 
    Camera                                          m_camera;               ///< C�mara principal.
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
    XMMATRIX                                        m_Projection;           ///< Matriz de proyecci�n.
    XMFLOAT4                                        m_vMeshColor;           ///< Color del mesh.
   
    CBNeverChanges                                  cbNeverChanges;         ///< Constantes que nunca cambian.
    CBChangeOnResize                                cbChangesOnResize;      ///< Constantes que cambian al redimensionar.

    bool keys[256] = { false };                     ///< Estado de las teclas del teclado.
    float sensitivity = 0.01f;                      ///< Sensibilidad para rotaci�n de c�mara.
    bool mouseLeftDown = false;                     ///< Estado del bot�n izquierdo del mouse.
    bool mouseRightDown = false;                    ///< Estado del bot�n derecho del mouse.
    int lastX;                                      ///< �ltima posici�n X del mouse.
    int lastY;                                      ///< �ltima posici�n Y del mouse.
};
