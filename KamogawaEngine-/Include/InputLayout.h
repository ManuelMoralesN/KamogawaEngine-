#pragma once
#include "Prerequisites.h"

class 
Device;
class 
DeviceContext;

/**
 * @brief Clase que encapsula un Input Layout de Direct3D 11.
 * Define cómo se interpretan los datos del vertex buffer al pasar al pipeline.
 */
class 
InputLayout
{
public:
	InputLayout() = default;
	~InputLayout() = default;

	/**
	 * @brief Inicializa el input layout con una descripción y los datos del shader.
	 * @param device Referencia al dispositivo de render.
	 * @param Layout Vector con la descripción de los elementos de entrada.
	 * @param VertexShaderData Blob con los datos compilados del vertex shader.
	 * @return HRESULT Resultado de la operación.
	 */
	HRESULT
	init(Device& device,
		 std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout,
		 ID3DBlob* VertexShaderData);

	/**
	 * @brief Actualiza el estado del input layout. (Vacío por diseño, puede ser extendido).
	 */
	void
	update();

	/**
	 * @brief Enlaza el input layout al contexto del dispositivo para su uso en el pipeline.
	 * @param deviceContext Contexto del dispositivo.
	 */
	void
	render(DeviceContext& deviceContext);

	/**
	 * @brief Libera los recursos asociados al input layout.
	 */
	void
	destroy();

public:
	ID3D11InputLayout* m_inputLayout = nullptr; ///< Puntero al input layout de Direct3D.
};
