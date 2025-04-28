#include "BaseApp.h"

HRESULT
BaseApp::init() {
	HRESULT hr = S_OK;

	// Create Swapchain and BackBuffer
	hr = m_swapchain.init(m_device, m_deviceContext, m_backBuffer, m_window);
	if (FAILED(hr)) {
		return hr;
	}

	// Create a render target view
	hr = m_renderTargetView.init(m_device,
		m_backBuffer,
		DXGI_FORMAT_R8G8B8A8_UNORM);

	if (FAILED(hr)) {
		return hr;
	}

	// Create a depth stencil
	hr = m_depthStencil.init(m_device,
		m_window.m_width,
		m_window.m_height,
		DXGI_FORMAT_D24_UNORM_S8_UINT,
		D3D11_BIND_DEPTH_STENCIL,
		4,
		0);
	if (FAILED(hr))
		return hr;

	// Create the depth stencil view
	hr = m_depthStencilView.init(m_device,
		m_depthStencil,
		DXGI_FORMAT_D24_UNORM_S8_UINT);

	if (FAILED(hr))
		return hr;


	// Setup the viewport
	hr = m_viewport.init(m_window);

	if (FAILED(hr))
		return hr;

	// Define the input layout
	std::vector<D3D11_INPUT_ELEMENT_DESC> Layout;

	D3D11_INPUT_ELEMENT_DESC position;
	position.SemanticName = "POSITION";
	position.SemanticIndex = 0;
	position.Format = DXGI_FORMAT_R32G32B32_FLOAT;
	position.InputSlot = 0;
	position.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT /*0*/;
	position.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	position.InstanceDataStepRate = 0;
	Layout.push_back(position);

	D3D11_INPUT_ELEMENT_DESC texcoord;
	texcoord.SemanticName = "TEXCOORD";
	texcoord.SemanticIndex = 0;
	texcoord.Format = DXGI_FORMAT_R32G32_FLOAT;
	texcoord.InputSlot = 0;
	texcoord.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT /*12*/;
	texcoord.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	texcoord.InstanceDataStepRate = 0;
	Layout.push_back(texcoord);

	// Create the Shader Program
	hr = m_shaderProgram.init(m_device, "KamogawaEngine-.fx", Layout);

	if (FAILED(hr))
		return hr;

	// Create the constant buffers

	hr = m_neverChanges.init(m_device, sizeof(CBNeverChanges));
	if (FAILED(hr))
		return hr;

	hr = m_changeOnResize.init(m_device, sizeof(CBChangeOnResize));
	if (FAILED(hr))
		return hr;

	// Initialize the view matrix
	XMVECTOR Eye = XMVectorSet(0.0f, 3.0f, -6.0f, 0.0f);
	XMVECTOR At = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	m_View = XMMatrixLookAtLH(Eye, At, Up);
	
	//IMGUI
	m_UI.init(m_window.m_hWnd, m_device.m_device, m_deviceContext.m_deviceContext);
	

	// Set Vela Actor
	// Load the Texture
	Texture cuerpo;
	cuerpo.init(m_device, "Textures/cuerpo.png", ExtensionType::PNG);
	Texture color;
	color.init(m_device, "Textures/color.png", ExtensionType::PNG);
	Texture espalda;
	espalda.init(m_device, "Textures/espalda.png", ExtensionType::PNG);
	Texture pecho;
	pecho.init(m_device, "Textures/pecho.png", ExtensionType::PNG);
	Texture cara;
	cara.init(m_device, "Textures/cara.png", ExtensionType::PNG);
	Texture cara2;
	cara2.init(m_device, "Textures/cara2.png", ExtensionType::PNG);
	m_default.init(m_device, "Textures/Default.png", ExtensionType::PNG);

	m_modelTextures.push_back(cuerpo);
	m_modelTextures.push_back(color);
	m_modelTextures.push_back(espalda);
	m_modelTextures.push_back(pecho);
	m_modelTextures.push_back(cara);
	m_modelTextures.push_back(cara2);
	m_modelTextures.push_back(m_default);

	m_model.LoadFBXModel("Models/invincible.fbx");
	AModel = EngineUtilities::MakeShared<Actor>(m_device);
	if (!AModel.isNull()) {
		AModel->getComponent<Transform>()->setTransform(EngineUtilities::Vector3(0.7f, 1.0f, -0.4f),
														EngineUtilities::Vector3(XM_PI / -2.0f, 1.0f, XM_PI / 2.0f),
														EngineUtilities::Vector3(1.0f, 1.0f, 1.0f));

		AModel->setMesh(m_device, m_model.meshes);
		AModel->setTextures(m_modelTextures);

		std::string msg = AModel->getName() + "- Actor accessed successfully.";
		MESSAGE("Actor", "Actor", msg.c_str());
	}
	else {
		MESSAGE("Actor", "Actor", "Actor resource not found. ");
	}

	// Set Actor
	// Load the Texture
	Texture Mordecai;
	Mordecai.init(m_device, "Textures/Mordecai.png", ExtensionType::PNG);

	
	m_modelTextures2.push_back(Mordecai);
	m_modelTextures2.push_back(m_default);

	m_model2.LoadFBXModel("Models/mordecai.fbx");
	AModel2 = EngineUtilities::MakeShared<Actor>(m_device);
	if (!AModel2.isNull()) {
		AModel2->getComponent<Transform>()->setTransform(EngineUtilities::Vector3(2.0f, 1.0f, 1.0f),
														EngineUtilities::Vector3(XM_PI / -2.0f, 0.0f, XM_PI / 2.0f),
														EngineUtilities::Vector3(1.0f, 1.0f, 1.0f));

		AModel2->setMesh(m_device, m_model2.meshes);
		AModel2->setTextures(m_modelTextures2);

		std::string msg = AModel2->getName() + "- Actor accessed successfully.";
		MESSAGE("Actor", "Actor", msg.c_str());
	}
	else {
		MESSAGE("Actor", "Actor", "Actor resource not found. ");
	}

	// Set Actor
	// Load the Texture
	Texture gorra;
	gorra.init(m_device, "Textures/gorra.png", ExtensionType::PNG);
	Texture manos;
	manos.init(m_device, "Textures/manos.png", ExtensionType::PNG);
	Texture cejas;
	cejas.init(m_device, "Textures/cejas.png", ExtensionType::PNG);
	Texture rojo;
	rojo.init(m_device, "Textures/rojo.png", ExtensionType::PNG);
	Texture ropa;
	ropa.init(m_device, "Textures/ropa.png", ExtensionType::PNG);
	Texture pelo;
	pelo.init(m_device, "Textures/pelo.png", ExtensionType::PNG);
	Texture bigote;
	bigote.init(m_device, "Textures/bigote.png", ExtensionType::PNG);
	Texture ojos;
	ojos.init(m_device, "Textures/ojos.png", ExtensionType::PNG);

	m_modelTexturesOBJ.push_back(gorra);
	m_modelTexturesOBJ.push_back(bigote);
	m_modelTexturesOBJ.push_back(manos);
	m_modelTexturesOBJ.push_back(ojos);
	m_modelTexturesOBJ.push_back(ropa);
	m_modelTexturesOBJ.push_back(rojo);
	m_modelTexturesOBJ.push_back(pelo);
	m_modelTexturesOBJ.push_back(cejas);
	m_modelTexturesOBJ.push_back(m_default);

	m_modelOBJ.LoadOBJModel("Models/Mario.obj");
	AModelOBJ = EngineUtilities::MakeShared<Actor>(m_device);
	if (!AModelOBJ.isNull()) {
		AModelOBJ->getComponent<Transform>()->setTransform(EngineUtilities::Vector3(-3.2f, -1.2f, 10.0f),
															EngineUtilities::Vector3( 3.1f, 6.3f, 3.15f),
															EngineUtilities::Vector3(1.0f, 1.0f, 1.0f));

		AModelOBJ->setMesh(m_device, m_modelOBJ.meshes);
		AModelOBJ->setTextures(m_modelTexturesOBJ); 

		std::string msg = AModelOBJ->getName() + "- Actor accessed successfully.";
		MESSAGE("Actor", "Actor", msg.c_str());
	}
	else {
		MESSAGE("Actor", "Actor", "Actor resource not found. ");
	}

	return S_OK;
}

void
BaseApp::update() {

	// Actualizar tiempo y rotación
	static float t = 0.0f;
	if (m_swapchain.m_driverType == D3D_DRIVER_TYPE_REFERENCE) {
		t += (float)XM_PI * 0.0125f;
	}
	else {
		static DWORD dwTimeStart = 0;
		DWORD dwTimeCur = GetTickCount();
		if (dwTimeStart == 0)
			dwTimeStart = dwTimeCur;
		t = (dwTimeCur - dwTimeStart) / 1000.0f;
	}
	InputActionMap(0.016f);

	// Actualizar la matriz de proyección
	m_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, m_window.m_width / (float)m_window.m_height, 0.01f, 100.0f);

	// Actualizar la vista (si es necesario cambiar dinámicamente)
	/*cbNeverChanges.mView = XMMatrixTranspose(m_View);
	m_neverChanges.update(m_deviceContext, 0, nullptr, &cbNeverChanges, 0, 0);*/
	updateCamera();
	// Actualizar la proyección en el buffer constante
	cbChangesOnResize.mProjection = XMMatrixTranspose(m_Projection);
	m_changeOnResize.update(m_deviceContext, 0, nullptr, &cbChangesOnResize, 0, 0);

	// Actualizar info logica del mesh
	AModel->update(0, m_deviceContext);
	AModel2->update(0, m_deviceContext);
	AModelOBJ->update(0, m_deviceContext);

}

void
BaseApp::render() {
	// Limpiar los buffers
	const float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red, green, blue, alpha

	// Set Render Target View
	m_renderTargetView.render(m_deviceContext, m_depthStencilView, 1, ClearColor);

	// Set Viewport
	m_viewport.render(m_deviceContext);

	// Set Depth Stencil View
	m_depthStencilView.render(m_deviceContext);

	// Configurar los buffers y shaders para el pipeline
	m_shaderProgram.render(m_deviceContext);

	//render the models
	AModel->render(m_deviceContext);
	AModel2->render(m_deviceContext);
	AModelOBJ->render(m_deviceContext);

	// Asignar shaders y buffers constantes
	// Renderizar buffers constantes en el Vertex Shader
	m_neverChanges.render(m_deviceContext, 0, 1);
	m_changeOnResize.render(m_deviceContext, 1, 1);

	// Renderizar el modelo 
	std::vector<EngineUtilities::TSharedPointer<Actor>> actors = { AModel, AModel2, AModelOBJ }; 
	m_UI.render(actors); 

	// Presentar el frame en pantalla
	m_swapchain.present();
}

void
BaseApp::destroy() {
	if (m_deviceContext.m_deviceContext) m_deviceContext.m_deviceContext->ClearState();
	m_UI.destroy(); // Liberar ImGui antes de destruir DirectX

	AModel->destroy();
	

	m_neverChanges.destroy();
	m_changeOnResize.destroy();
	m_changeEveryFrame.destroy();
	m_shaderProgram.destroy();

	m_depthStencil.destroy();
	m_depthStencilView.destroy();
	m_renderTargetView.destroy();
	m_swapchain.destroy();
	m_deviceContext.destroy();
	m_device.destroy();
}

HRESULT
BaseApp::resizeWindow(HWND hWnd, LPARAM lParam) {
	if (m_swapchain.m_swapchain) {
		m_window.m_width = LOWORD(lParam);
		m_window.m_height = HIWORD(lParam);

		// Libera los recursos existentes
		m_renderTargetView.destroy();
		m_depthStencilView.destroy();
		m_depthStencil.destroy();
		m_backBuffer.destroy();

		// Redimensionar el swap chain
		HRESULT hr = m_swapchain.m_swapchain->ResizeBuffers(0,
			m_window.m_width,
			m_window.m_height,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			0);
		if (FAILED(hr)) {
			MessageBox(hWnd, "Failed to resize swap chain buffers.", "Error", MB_OK);
			PostQuitMessage(0);
		}

		// Recrear el backbuffer
		hr = m_swapchain.m_swapchain->GetBuffer(0,
			__uuidof(ID3D11Texture2D),
			reinterpret_cast<void**>(&m_backBuffer.m_texture));
		if (FAILED(hr)) {
			ERROR("SwapChain", "Resize", "Failed to get new back buffer");
			return hr;
		}

		// Recrear el render target view
		hr = m_renderTargetView.init(m_device,
			m_backBuffer,
			DXGI_FORMAT_R8G8B8A8_UNORM);
		if (FAILED(hr)) {
			ERROR("RenderTargetView", "Resize", "Failed to create new RenderTargetView");
			return hr;
		}

		// Recrear el depth stencil 
		hr = m_depthStencil.init(m_device,
			m_window.m_width,
			m_window.m_height,
			DXGI_FORMAT_D24_UNORM_S8_UINT,
			D3D11_BIND_DEPTH_STENCIL,
			4,
			0);
		if (FAILED(hr)) {
			ERROR("DepthStencil", "Resize", "Failed to create new DepthStencil");
			return hr;
		}

		hr = m_depthStencilView.init(m_device,
			m_depthStencil,
			DXGI_FORMAT_D24_UNORM_S8_UINT);
		if (FAILED(hr)) {
			ERROR("DepthStencilView", "Resize", "Failed to create new DepthStencilView");
			return hr;
		}

		// Actualizar el viewport
		hr = m_viewport.init(m_window);

		if (FAILED(hr)) {
			ERROR("Viewport", "Resize", "Failed to create new Viewport");
			return hr;
		}

		// Actualizar la proyección
		m_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, m_window.m_width / (float)m_window.m_height, 0.01f, 100.0f);
		cbChangesOnResize.mProjection = XMMatrixTranspose(m_Projection);
		m_changeOnResize.update(m_deviceContext, 0, nullptr, &cbChangesOnResize, 0, 0);
	}
}

void 
BaseApp::updateCamera(){
	XMVECTOR pos = XMLoadFloat3(&m_camera.position);
	XMVECTOR dir = XMLoadFloat3(&m_camera.forward);
	XMVECTOR up = XMLoadFloat3(&m_camera.up);
	//Calcular la nueva vista
	m_View = XMMatrixLookAtLH(pos, pos + dir, up);

	//Trasponer y actualizar el buffer de la vista
	cbNeverChanges.mView = XMMatrixTranspose(m_View);
	m_neverChanges.update(m_deviceContext, 0, nullptr, &cbNeverChanges, 0, 0);
}

void BaseApp::rotateCamera(int mouseX, int mouseY){
	float offsetX = (mouseX - lastX) * sensitivity;
	float offsetY = (mouseY - lastY) * sensitivity;

	lastX = mouseX;
	lastY = mouseY;

	m_camera.yaw += offsetX;
	m_camera.pitch += offsetY;

	//limitar la inclinacion de la camara
	if (m_camera.pitch > 1.5f) m_camera.pitch = 1.5f;
	if (m_camera.pitch > -1.5f) m_camera.pitch = -1.5f;

	//recalcular la direccion hacia adelante
	XMVECTOR forward = XMVectorSet(
		cosf(m_camera.yaw) * cosf(m_camera.pitch),
		sinf(m_camera.pitch),
		sinf(m_camera.yaw) * cosf(m_camera.pitch),
		0.0f
	);

	XMVECTOR right = XMVector3Cross(forward, XMLoadFloat3(&m_camera.up));

	XMStoreFloat3(&m_camera.forward, XMVector3Normalize(forward));
	XMStoreFloat3(&m_camera.right, XMVector3Normalize(right));
}

void
BaseApp::InputActionMap(float deltaTime) {
	float speed = 1.0f * deltaTime; 
	float speedCamera = 1.0f * deltaTime;

	//if (keys['E']) {
	//	position.z += speed; // Atras
	//}
	//if (keys['U']) {
	//	position.z -= speed; // Adelante
	//}
	//if (keys['J']) {
	//	position.x -= speed; // Izquierda
	//}
	//if (keys['L']) {
	//	position.x += speed; // Derecha
	//}
	//if (keys['I']) {
	//	position.y += speed; // Arriba
	//}
	//if (keys['K']) {
	//	position.y -= speed; // Abajo
	//}

	XMVECTOR pos = XMLoadFloat3(&m_camera.position);
	XMVECTOR forward = XMLoadFloat3(&m_camera.forward);
	XMVECTOR right = XMLoadFloat3(&m_camera.right);

	if (keys['W']) pos += forward * speedCamera;
	if (keys['S']) pos -= forward * speedCamera;
	if (keys['A']) pos -= right * speedCamera;
	if (keys['D']) pos += right * speedCamera;
	
	XMStoreFloat3(&m_camera.position, pos);
}

int
BaseApp::run(HINSTANCE hInstance,
			 HINSTANCE hPrevInstance,
			 LPWSTR lpCmdLine,
			 int nCmdShow,
			 WNDPROC wndproc) {
			 UNREFERENCED_PARAMETER(hPrevInstance);
			 UNREFERENCED_PARAMETER(lpCmdLine);

	if (FAILED(m_window.init(hInstance, nCmdShow, wndproc)))
		return 0;

	if (FAILED(init())) {
		destroy();
		return 0;
	}

	// Main message loop
	MSG msg = { 0 };
	while (WM_QUIT != msg.message) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			update();
			render();
		}
	}

	destroy();

	return (int)msg.wParam;
}
