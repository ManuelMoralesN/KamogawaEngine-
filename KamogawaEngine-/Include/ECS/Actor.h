#pragma once
#include "Prerequisites.h"
#include "ECS/Entity.h"
#include "Buffer.h"
#include "Texture.h"
#include "SamplerState.h"
#include "Transform.h"

class Device;
class Component;

/**
 * @brief Clase que representa un Actor en el motor de juego.
 *
 * Un Actor es una entidad con componentes como mallas, texturas y buffers,
 * capaz de actualizarse y renderizarse dentro de la escena.
 */
class
Actor : Entity {
public:
    /**
     * @brief Constructor por defecto.
     */
    Actor() = default;

    /**
     * @brief Constructor que inicializa un actor con un dispositivo de renderizado.
     * @param device Referencia al dispositivo de renderizado.
     */
    Actor(Device& device);

    /**
     * @brief Destructor virtual por defecto.
     */
    virtual ~Actor() = default;

    /**
     * @brief Actualiza la lógica del actor.
     * @param deltaTime Tiempo transcurrido desde el último frame.
     * @param deviceContext Contexto del dispositivo para operaciones de renderizado.
     */
    void
    update(float deltaTime, DeviceContext& deviceContext) override;

    /**
     * @brief Renderiza el actor utilizando el dispositivo de renderizado.
     * @param deviceContext Contexto del dispositivo para operaciones de renderizado.
     */
    void
    render(DeviceContext& deviceContext) override;

    /**
     * @brief Libera los recursos utilizados por el actor.
     */
    void
    destroy();

    /**
     * @brief Establece las mallas del actor.
     * @param device Referencia al dispositivo de renderizado.
     * @param meshes Vector de componentes de malla a asignar.
     */
    void
    setMesh(Device& device, std::vector<MeshComponent> meshes);

    /**
     * @brief Establece las texturas del actor.
     * @param textures Vector de texturas a asignar.
     */
    void
    setTextures(std::vector<Texture> textures) {
        m_textures = textures;
    }

    /**
     * @brief Obtiene el nombre del actor.
     * @return Nombre del actor como string.
     */
    std::string
        getName() {
        return m_name;
    }

    /**
     * @brief Obtiene un componente específico del actor.
     * @tparam T Tipo de componente a obtener.
     * @return Puntero compartido al componente solicitado o nulo si no existe.
     */
    template<typename T>
    EngineUtilities::TSharedPointer<T>
        getComponent();

private:
    std::vector<MeshComponent> m_meshes; ///< Mallas asociadas al actor.
    std::vector<Texture> m_textures; ///< Texturas asociadas al actor.
    std::vector<Buffer> m_vertexBuffers; ///< Buffers de vértices para cada malla.
    std::vector<Buffer> m_indexBuffers; ///< Buffers de índices para cada malla.

    CBChangesEveryFrame m_model; ///< Estructura de constantes que cambia cada frame.
    Buffer m_modelBuffer; ///< Buffer de constantes para el modelo.
    SamplerState m_sampler; ///< Estado del muestreador de texturas.
    std::string m_name = "Actor"; ///< Nombre del actor.
};

template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() { // template specialization for getting specific component type 
    for (auto& component : m_components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    return EngineUtilities::TSharedPointer<T>();
}
