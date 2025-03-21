#pragma once
#include "Prerequisites.h"

class 
Device;
class 
DeviceContext;

/**
 * @brief Clase que encapsula un Sampler State en Direct3D 11.
 *
 * Un sampler state define cómo se muestrean las texturas (filtrado, direccionamiento, etc.).
 */
class 
SamplerState
{
public:
    SamplerState() = default;
    ~SamplerState() = default;

    /**
     * @brief Inicializa el sampler state con una configuración predeterminada.
     * @param device Referencia al dispositivo para crear el sampler.
     * @return HRESULT Resultado de la operación.
     */
    HRESULT
    init(Device& device);

    /**
     * @brief Actualiza el estado del sampler. (Vacío por diseño, puede ser extendido).
     */
    void
    update();

    /**
     * @brief Enlaza el sampler state al pipeline de renderizado.
     * @param deviceContext Contexto del dispositivo.
     * @param StartSlot Slot inicial donde se enlaza el sampler.
     * @param numSampler Número de samplers a enlazar.
     */
    void
    render(DeviceContext& deviceContext,
           unsigned int StartSlot,
           unsigned int numSampler);

    /**
     * @brief Libera los recursos asociados al sampler state.
     */
    void
    destroy();

private:
    ID3D11SamplerState* m_samplerState = nullptr; ///< Puntero al sampler state de Direct3D.
};
