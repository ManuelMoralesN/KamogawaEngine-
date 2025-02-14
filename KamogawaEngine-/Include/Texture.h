#pragma once
#include "Prerequisites.h"

class 
Device;
class 
DeviceContext;

/**
 * @class Texture
 * @brief Clase que representa una textura en Direct3D 11.
 *
 * Gestiona la creación, actualización, renderizado y destrucción de texturas en la GPU.
 */
class 
Texture {
public:
    /**
     * @brief Constructor por defecto.
     */
    Texture() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~Texture() = default;

    /**
     * @brief Inicializa una textura desde un archivo de imagen.
     *
     * @param device Referencia al dispositivo Direct3D.
     * @param textureName Nombre del archivo de la textura.
     * @param extensionType Tipo de extensión del archivo de la textura.
     * @return HRESULT Código de resultado indicando éxito o error en la operación.
     */
    HRESULT init(Device device,
                 const std::string& textureName,
                 ExtensionType extensionType);

    /**
     * @brief Inicializa una textura con dimensiones y formato específicos.
     *
     * @param device Referencia al dispositivo Direct3D.
     * @param width Ancho de la textura en píxeles.
     * @param height Alto de la textura en píxeles.
     * @param Format Formato de la textura (DXGI_FORMAT).
     * @param BindFlags Flags que indican el uso de la textura.
     * @param sampleCount Número de muestras para antialiasing (opcional, por defecto 1).
     * @param qualityLevels Niveles de calidad del muestreo (opcional, por defecto 0).
     * @return HRESULT Código de resultado indicando éxito o error en la operación.
     */
    HRESULT init(Device device,
                 unsigned int width,
                 unsigned int height,
                 DXGI_FORMAT Format,
                 unsigned int BindFlags,
                 unsigned int sampleCount = 1,
                 unsigned int qualityLevels = 0);

    /**
     * @brief Actualiza la textura si es necesario.
     */
    void 
    update();

    /**
     * @brief Renderiza la textura en la etapa de shader.
     *
     * @param deviceContext Referencia al contexto del dispositivo.
     * @param StartSlot Primer slot en el que se asignará la textura.
     * @param NumViews Número de vistas de la textura a asignar.
     */
    void 
    render(DeviceContext& deviceContext, 
           unsigned int StartSlot, 
           unsigned int NumViews);

    /**
     * @brief Libera los recursos asociados con la textura.
     */
    void 
    destroy();

public:
    /// Puntero a la interfaz ID3D11Texture2D que representa la textura como recurso de datos.
    ID3D11Texture2D* m_texture = nullptr;

    /// Puntero a la interfaz ID3D11ShaderResourceView que representa la textura como imagen para los shaders.
    ID3D11ShaderResourceView* m_textureFromImg;
};
