#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class MeshComponent;

/**
 * @brief Clase que encapsula un buffer de Direct3D 11 (como vertex o index buffer).
 */
class 
Buffer
{
public:
    Buffer() = default;
    ~Buffer() = default;

    /**
     * @brief Inicializa el buffer con datos de un mesh y un tipo de enlace.
     * @param device Referencia al dispositivo de render.
     * @param mesh Componente de malla con los datos necesarios.
     * @param bindFlag Tipo de uso del buffer (D3D11_BIND_VERTEX_BUFFER, etc.).
     * @return HRESULT Resultado de la operaci�n.
     */
    HRESULT
    init(Device& device,
         const MeshComponent& mesh,
         unsigned int bindFlag);

    /**
     * @brief Inicializa un buffer vac�o con el tama�o especificado.
     * @param device Referencia al dispositivo de render.
     * @param ByteWidth Tama�o en bytes del buffer.
     * @return HRESULT Resultado de la operaci�n.
     */
    HRESULT
   init(Device& device,
        unsigned int ByteWidth);

    /**
     * @brief Actualiza el contenido del buffer con nuevos datos.
     * @param deviceContext Contexto del dispositivo para aplicar la actualizaci�n.
     * @param DstSubresource Subrecurso destino.
     * @param pDstBox Caja de destino para la regi�n a actualizar.
     * @param pSrcData Puntero a los nuevos datos.
     * @param SrcRowPitch Tama�o de cada fila en los datos fuente.
     * @param SrcDepthPitch Tama�o del volumen en los datos fuente.
     */
    void
    update(DeviceContext& deviceContext,
           unsigned int DstSubresource,
           const D3D11_BOX* pDstBox,
           const void* pSrcData,
           unsigned int SrcRowPitch,
           unsigned int SrcDepthPitch);

    /**
     * @brief Env�a el buffer al pipeline para su uso en renderizado.
     * @param deviceContext Contexto del dispositivo.
     * @param StartSlot Slot inicial donde enlazar el buffer.
     * @param NumBuffers N�mero de buffers a enlazar.
     * @param setPixelShader Si es verdadero, tambi�n se enlaza al pixel shader.
     * @param format Formato del �ndice si se usa como index buffer.
     */
    void
    render(DeviceContext& deviceContext,
           unsigned int StartSlot,
           unsigned int NumBuffers,
           bool setPixelShader = false,
           DXGI_FORMAT format = DXGI_FORMAT_UNKNOWN);

    /**
     * @brief Libera los recursos asociados al buffer.
     */
    void
    destroy();

private:
    /**
     * @brief Crea un buffer de Direct3D con la descripci�n y datos proporcionados.
     * @param device Referencia al dispositivo de render.
     * @param desc Descripci�n del buffer.
     * @param initData Datos iniciales del buffer (puede ser nullptr).
     * @return HRESULT Resultado de la creaci�n.
     */
    HRESULT
    createBuffer(Device& device,
                 D3D11_BUFFER_DESC& desc,
                 D3D11_SUBRESOURCE_DATA* initData);

private:
    ID3D11Buffer* m_buffer = nullptr;   ///< Puntero al buffer de Direct3D.
    unsigned int m_stride = 0;          ///< Tama�o de cada elemento del buffer.
    unsigned int m_offset = 0;          ///< Offset utilizado al enviar el buffer al pipeline.
    unsigned int m_bindFlag = 0;        ///< Tipo de enlace del buffer (vertex, index, constant, etc.).
};
