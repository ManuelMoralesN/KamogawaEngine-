#pragma once
#include "Prerequisites.h"

class 
Window;
class 
DeviceContext;

/**
 * @brief Clase que encapsula un viewport de Direct3D 11.
 *
 * Define la regi�n de la pantalla donde se renderizan los gr�ficos.
 */
class 
Viewport
{
public:
	Viewport() = default;
	~Viewport() = default;

	/**
	 * @brief Inicializa el viewport usando las dimensiones de una ventana.
	 * @param window Referencia a la ventana.
	 * @return HRESULT Resultado de la operaci�n.
	 */
	HRESULT
	init(const Window& window);

	/**
	 * @brief Inicializa el viewport con un ancho y alto espec�ficos.
	 * @param width Ancho del viewport.
	 * @param height Alto del viewport.
	 * @return HRESULT Resultado de la operaci�n.
	 */
	HRESULT
	init(unsigned int width, unsigned int height);

	/**
	 * @brief Actualiza la configuraci�n del viewport. (Vac�o por dise�o, puede ser extendido).
	 */
	void
	update();

	/**
	 * @brief Establece el viewport actual en el contexto de dispositivo.
	 * @param deviceContext Contexto del dispositivo donde aplicar el viewport.
	 */
	void
	render(DeviceContext& deviceContext);

	/**
	 * @brief Libera cualquier recurso asociado al viewport. (No aplica en este caso, pero mantiene consistencia).
	 */
	void
	destroy();

public:
	D3D11_VIEWPORT m_viewport; ///< Estructura del viewport de Direct3D.
};
