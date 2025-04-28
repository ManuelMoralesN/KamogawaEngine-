#pragma once
#include "Prerequisites.h"
#include "Utilities/Vectors/Vector3.h"
#include "Component.h"

/**
 * @brief Componente de transformaci�n que gestiona posici�n, rotaci�n y escala de un objeto.
 *
 * Representa la transformaci�n espacial de una entidad en el mundo 3D.
 */
class
Transform : public Component {
public:
    /**
     * @brief Constructor que inicializa posici�n, rotaci�n y escala por defecto.
     */
    Transform() : position(),
        rotation(),
        scale(),
        matrix(),
        Component(ComponentType::TRANSFORM) {}

    /**
     * @brief Inicializa el componente de transformaci�n.
     */
    void
    init();

    /**
     * @brief Actualiza la transformaci�n en cada frame.
     * @param deltaTime Tiempo transcurrido desde el �ltimo frame.
     */
    void
    update(float deltaTime) override;

    /**
     * @brief Renderiza el componente. (Vac�o ya que Transform no tiene renderizado propio).
     * @param deviceContext Contexto del dispositivo de renderizado.
     */
    void
    render(DeviceContext& deviceContext) override {}

    /**
     * @brief Destruye el componente. (Vac�o en este caso).
     */
    void
    destroy() {}

    /**
     * @brief Obtiene la posici�n actual del objeto.
     * @return Referencia constante al vector de posici�n.
     */
    const EngineUtilities::Vector3&
    getPosition() const { return position; }

    /**
     * @brief Establece una nueva posici�n.
     * @param newPos Vector que representa la nueva posici�n.
     */
    void
    setPosition(const EngineUtilities::Vector3& newPos) { position = newPos; }

    /**
     * @brief Obtiene la rotaci�n actual del objeto.
     * @return Referencia constante al vector de rotaci�n.
     */
    const EngineUtilities::Vector3&
    getRotation() const { return rotation; }

    /**
     * @brief Establece una nueva rotaci�n.
     * @param newRot Vector que representa la nueva rotaci�n.
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
     * @brief Establece posici�n, rotaci�n y escala en una sola operaci�n.
     * @param newPos Nueva posici�n.
     * @param newRot Nueva rotaci�n.
     * @param newSca Nueva escala.
     */
    void
    setTransform(const EngineUtilities::Vector3& newPos,
                 const EngineUtilities::Vector3& newRot,
                 const EngineUtilities::Vector3& newSca);

    /**
     * @brief Traslada (mueve) la posici�n actual por un vector de traslaci�n.
     * @param translation Vector de traslaci�n a aplicar.
     */
    void
    translate(const EngineUtilities::Vector3& translation);

private:
    EngineUtilities::Vector3 position; ///< Posici�n del objeto.
    EngineUtilities::Vector3 rotation; ///< Rotaci�n del objeto.
    EngineUtilities::Vector3 scale;    ///< Escala del objeto.

public:
    XMMATRIX matrix; ///< Matriz de transformaci�n resultante (posici�n, rotaci�n y escala combinadas).
};
