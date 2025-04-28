Kamogawa Engine es un motor gráfico 3D en desarrollo que utiliza C++, DirectX 11 y ImGui para renderizado y herramientas de edición.

Antes de compilar, asegúrate de tener instalado:
Visual Studio 2022 o superior (Community, Professional o Enterprise).
Windows SDK (versión 10.0 o superior).
DirectX SDK (integrado en Windows Kits para VS2022).
FBX SDK de Autodesk (descargable desde Autodesk FBX SDK).
ImGui (ya incluido en el proyecto).

Estas bibliotecas ya deberían estar incluidas en el repositorio o configuradas:
imgui (interfaz gráfica)
ImGuizmo (manipuladores de transformaciones 3D)
FBX SDK (importación de modelos .fbx)
OBJ Loader personalizado para modelos .obj

¿Cómo compilar?
Clona el repositorio 
Abre Visual Studio.
Carga el proyecto.
Configura el modo de compilación:
Debug x64.
Configura las rutas de include y librerías.
Añade el Include Path de FBX SDK (ejemplo: C:\Program Files\Autodesk\FBX\FBX SDK\2020.0\include).
Añade el Library Path para los .lib del FBX SDK.
Ejecuta

Y listo, ya puedes probar el Motor: 
![Captura de pantalla 2025-04-10 161113](https://github.com/user-attachments/assets/ebb131f0-858d-4e56-a476-fe3da59aacd4)
