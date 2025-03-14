#pragma once

// Librer�as est�ndar
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
//#include <memory>
#include <thread>

// Librer�as DirectX
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

/**
 * Macro para liberar recursos de DirectX de forma segura.
 * Evita fugas de memoria al asegurarse de liberar los recursos antes de establecerlos en nullptr.
 */
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

 /**
  * Macro para imprimir mensajes de depuraci�n sobre la creaci�n de recursos.
  *
  * @param classObj Nombre de la clase que llama.
  * @param method Nombre del m�todo donde se ejecuta.
  * @param state Estado de la creaci�n del recurso.
  */
#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREACI�N DE RECURSO " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

  /**
   * Macro para registrar errores en la depuraci�n y terminar la ejecuci�n.
   *
   * @param classObj Nombre de la clase donde ocurri� el error.
   * @param method M�todo en el que ocurri� el error.
   * @param errorMSG Mensaje descriptivo del error.
   */
#define ERROR( classObj, method, errorMSG )  \
{                                            \
   std::wostringstream os_;                  \
   os_ << "ERROR : " << classObj << "::" << method << " : " << "  Error en los datos de los par�metros [" << errorMSG << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
   exit(1);                                  \
}

   /**
    * Estructura que define un v�rtice simple con posici�n y coordenadas de textura.
    */
    struct 
    SimpleVertex {
    XMFLOAT3 Pos;  ///< Posici�n del v�rtice en el espacio 3D.
    XMFLOAT2 Tex;  ///< Coordenadas de textura del v�rtice.
};

/**
 * Estructura para almacenar la matriz de vista utilizada en la renderizaci�n.
 */
    struct 
    CBNeverChanges {
    XMMATRIX mView;  ///< Matriz de vista utilizada para transformar los objetos en el mundo.
};

/**
 * Estructura para almacenar la matriz de proyecci�n que cambia al redimensionar la ventana.
 */
    struct
    CBChangeOnResize {
    XMMATRIX mProjection;  ///< Matriz de proyecci�n para gestionar la perspectiva de la escena.
};

/**
 * Estructura que almacena transformaciones y color del objeto a ser renderizado.
 */
    struct 
    CBChangesEveryFrame {
    XMMATRIX mWorld;      ///< Matriz de transformaci�n del mundo para cada frame.
    XMFLOAT4 vMeshColor;  ///< Color del objeto en RGBA.
};

/**
 * Enumeraci�n para definir los tipos de extensiones de imagen soportadas.
 */
    enum 
    ExtensionType {
    DDS = 0, ///< Imagen en formato DDS (DirectDraw Surface).
    PNG = 1, ///< Imagen en formato PNG.
    JPG = 2  ///< Imagen en formato JPG.
};

    enum
    ShaderType {
        VERTEX_SHADER = 0,
        PIXEL_SHADER = 1
    };

    struct Camera {
        XMFLOAT3 position; //Posicion de la camara
        XMFLOAT3 target; //Posocion que mira

        XMFLOAT3 up; //Vector hacia arriba
        XMFLOAT3 forward; // Direccion hacia adelante
        XMFLOAT3 right; //Direccion hacia la derecha

        float yaw; //Rotacion en eje Y
        float pitch; //Rotacion en eje X

        Camera() {
            position = XMFLOAT3(0.0f, 2.0f, -5.0f);
            target = XMFLOAT3(0.0f, 2.0f, 0.0f);
            up = XMFLOAT3(0.0f, 1.0f, 0.0f);
            forward = XMFLOAT3(0.0f, 0.0f, 1.0f);
            right = XMFLOAT3(1.0f, 0.0f, 0.0f);
            yaw = 0.0f;
            pitch = 0.0f;
        }
    };