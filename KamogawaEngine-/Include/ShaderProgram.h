#pragma once
#include "Prerequisites.h"
#include "InputLayout.h"

class 
Device;
class 
DeviceContext;

/**
 * @brief Clase que encapsula la creaci�n, compilaci�n y gesti�n de shaders en Direct3D 11.
 *
 * Incluye vertex shader, pixel shader y su correspondiente input layout.
 */
class 
ShaderProgram
{
public:
	ShaderProgram() = default;
	~ShaderProgram() = default;

	/**
	 * @brief Inicializa el shader program cargando y compilando shaders desde archivo.
	 * @param device Referencia al dispositivo de render.
	 * @param fileName Nombre del archivo de shader (HLSL).
	 * @param Layout Descripci�n del layout de entrada.
	 * @return HRESULT Resultado de la operaci�n.
	 */
	HRESULT
	init(Device& device,
		 const std::string& fileName,
		 std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

	/**
	 * @brief L�gica de actualizaci�n del shader program. (Vac�o por defecto).
	 */
	void
	update();

	/**
	 * @brief Establece los shaders y el input layout en el pipeline de renderizado.
	 * @param deviceContext Contexto del dispositivo.
	 */
	void
	render(DeviceContext& deviceContext);

	/**
	 * @brief Libera todos los recursos asociados a los shaders.
	 */
	void
	destroy();

	/**
	 * @brief Crea el input layout para el vertex shader.
	 * @param device Referencia al dispositivo de render.
	 * @param Layout Descripci�n de la entrada del layout.
	 * @return HRESULT Resultado de la operaci�n.
	 */
	HRESULT
	CreateInputLayout(Device& device,
					  std::vector<D3D11_INPUT_ELEMENT_DESC> Layout);

	/**
	 * @brief Crea un shader (vertex o pixel) seg�n el tipo especificado.
	 * @param device Referencia al dispositivo de render.
	 * @param type Tipo de shader a crear.
	 * @return HRESULT Resultado de la operaci�n.
	 */
	HRESULT
	CreateShader(Device& device,
			     ShaderType type);

	/**
	 * @brief Compila un shader HLSL desde archivo.
	 * @param szFileName Nombre del archivo del shader.
	 * @param szEntryPoint Punto de entrada del shader.
	 * @param szShaderModel Modelo de shader (ej. "vs_5_0", "ps_5_0").
	 * @param ppBlobOut Puntero al blob resultante de la compilaci�n.
	 * @return HRESULT Resultado de la compilaci�n.
	 */
	HRESULT
	CompileShaderFromFile(char* szFileName,
						  LPCSTR szEntryPoint,
						  LPCSTR szShaderModel,
						  ID3DBlob** ppBlobOut);

private:
	ID3D11VertexShader* m_VertexShader = nullptr; ///< Vertex Shader de Direct3D.
	ID3D11PixelShader* m_PixelShader = nullptr;   ///< Pixel Shader de Direct3D.
	InputLayout m_inputLayout;                    ///< Input Layout asociado al Vertex Shader.

public:
	std::string m_shaderFileName;                 ///< Ruta o nombre del archivo de shader.
	ID3DBlob* m_vertexShaderData = nullptr;       ///< Datos compilados del Vertex Shader.
	ID3DBlob* m_pixelShaderData = nullptr;        ///< Datos compilados del Pixel Shader.
};
