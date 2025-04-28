#pragma once
#include "Prerequisites.h"
#include "Utilities/Vectors/Vector3.h"
#include "Component.h"

/**
 * @brief Componente de transformación que gestiona posición, rotación y escala de un objeto.
 *
 * Representa la transformación espacial de una entidad en el mundo 3D.
 */
class
Transform : public Component {
public:
    /**
     * @brief Constructor que inicializa posición, rotación y escala por defecto.
     */
    Transform() : position(),
        rotation(),
        scale(),
        matrix(),
        Component(ComponentType::TRANSFORM) {}

    /**
     * @brief Inicializa el componente de transformación.
     */
    void
    init();

    /**
     * @brief Actualiza la transformación en cada frame.
     * @param deltaTime Tiempo transcurrido desde el último frame.
     */
    void
    update(float deltaTime) override;

    /**
     * @brief Renderiza el componente. (Vacío ya que Transform no tiene renderizado propio).
     * @param deviceContext Contexto del dispositivo de renderizado.
     */
    void
    render(DeviceContext& deviceContext) override {}

    /**
     * @brief Destruye el componente. (Vacío en este caso).
     */
    void
    destroy() {}

    /**
     * @brief Obtiene la posición actual del objeto.
     * @return Referencia constante al vector de posición.
     */
    const EngineUtilities::Vector3&
    getPosition() const { return position; }

    /**
     * @brief Establece una nueva posición.
     * @param newPos Vector que representa la nueva posición.
     */
    void
    setPosition(const EngineUtilities::Vector3& newPos) { position = newPos; }

    /**
     * @brief Obtiene la rotación actual del objeto.
     * @return Referencia constante al vector de rotación.
     */
    const EngineUtilities::Vector3&
    getRotation() const { return rotation; }

    /**
     * @brief Establece una nueva rotación.
     * @param newRot Vector que representa la nueva rotación.
     */
    void
    setRotation(const EngineUtilities::Vector3& newRot) { rotation = newRot; }

    /**
     * @brief Obtiene la escala actual del objeto.
     * @return Referencia constante al vector de escala.
     */
    const EngineUtilities::Vector3&
    getScale() const { return scale; }

    /**
     * @brief Establece una nueva escala.
     * @param newScale Vector que representa la nueva escala.
     */
    void
    setScale(const EngineUtilities::Vector3& newScale) { scale = newScale; }

    /**
     * @brief Establece posición, rotación y escala en una sola operación.
     * @param newPos Nueva posición.
     * @param newRot Nueva rotación.
     * @param newSca Nueva escala.
     */
    void
    setTransform(const EngineUtilities::Vector3& newPos,
                 const EngineUtilities::Vector3& newRot,
                 const EngineUtilities::Vector3& newSca);

    /**
     * @brief Traslada (mueve) la posición actual por un vector de traslación.
     * @param translation Vector de traslación a aplicar.
     */
    void
    translate(const EngineUtilities::Vector3& translation);

private:
    EngineUtilities::Vector3 position; ///< Posición del objeto.
    EngineUtilities::Vector3 rotation; ///< Rotación del objeto.
    EngineUtilities::Vector3 scale;    ///< Escala del objeto.

public:
    XMMATRIX matrix; ///< Matriz de transformación resultante (posición, rotación y escala combinadas).
};
