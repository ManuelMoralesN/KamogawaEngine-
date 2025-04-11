#pragma once
#include "Prerequisites.h"
#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx11.h"
#include <imgui_internal.h>
#include "ImGuizmo.h"
#include "ECS/Transform.h"


/**
 * @brief Clase encargada de la interfaz gráfica de usuario utilizando ImGui e ImGuizmo.
 *
 * Proporciona controles interactivos para manipular transformaciones y renderizar elementos UI.
 */
class 
UserInterface
{
public:
	UserInterface() = default;
	~UserInterface() = default;

	/**
	 * @brief Inicializa ImGui con las implementaciones para Win32 y Direct3D 11.
	 * @param window Puntero a la ventana Win32.
	 * @param device Dispositivo de Direct3D.
	 * @param deviceContext Contexto del dispositivo de Direct3D.
	 */
	void
	init(void* window,
		 ID3D11Device* device,
		 ID3D11DeviceContext* deviceContext);

	/**
	 * @brief Actualiza el estado de la interfaz antes del render.
	 */
	void
	update();

	/**
	 * @brief Renderiza la interfaz gráfica, incluyendo manipuladores de transformación.
	 * @param position Vector de posición del objeto.
	 * @param rotation Vector de rotación del objeto.
	 * @param scale Vector de escala del objeto.
	 * @param modelMatrix Matriz del modelo.
	 * @param viewMatrix Matriz de vista.
	 * @param projectionMatrix Matriz de proyección.
	 */
	void
	render(Transform& transform);

	/**
	 * @brief Libera todos los recursos asociados a ImGui.
	 */
	void
	destroy();

	/**
	 * @brief Crea un control personalizado para editar un vector3 (X, Y, Z) con ImGui.
	 * @param label Etiqueta del control.
	 * @param values Puntero al array de 3 floats que representa el vector.
	 * @param resetValues Valor por defecto para restablecer los ejes.
	 * @param columnWidth Ancho de la primera columna (etiqueta).
	 */
	void
	vec3Control(std::string label,
			    float* values,
			    float resetValues = 0.0f,
			    float columnWidth = 100.0f);

private:
	ImGuizmo::OPERATION mode = ImGuizmo::TRANSLATE; ///< Modo actual de manipulación (traslación, rotación o escala).
};
