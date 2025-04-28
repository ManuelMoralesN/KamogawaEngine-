#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
#include "fbxsdk.h"

/**
 * @brief Clase encargada de cargar modelos 3D en formato FBX y OBJ.
 *
 * Procesa nodos, mallas, y materiales para convertirlos en MeshComponents utilizables por el motor.
 */
class
ModelLoader {
public:
    /**
     * @brief Constructor por defecto.
     */
    ModelLoader() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~ModelLoader() = default;

    /**
     * @brief Inicializa el gestor de FBX (FbxManager).
     * @return true si la inicialización fue exitosa, false en caso contrario.
     */
    bool
    InitializeFBXManager();

    /**
     * @brief Carga un modelo en formato FBX desde el archivo especificado.
     * @param filePath Ruta del archivo FBX a cargar.
     * @return true si la carga fue exitosa, false en caso contrario.
     */
    bool
    LoadFBXModel(const std::string& filePath);

    /**
     * @brief Procesa recursivamente un nodo del archivo FBX.
     * @param node Puntero al nodo de FBX que se desea procesar.
     */
    void
    ProcessFBXNode(FbxNode* node);

    /**
     * @brief Procesa la malla contenida en un nodo FBX.
     * @param node Puntero al nodo que contiene la malla.
     */
    void
    ProcessFBXMesh(FbxNode* node);

    /**
     * @brief Procesa los materiales asociados a una superficie de malla en FBX.
     * @param material Puntero al material de superficie FBX.
     */
    void
    ProcessFBXMaterials(FbxSurfaceMaterial* material);

    /**
     * @brief Carga un modelo en formato OBJ desde el archivo especificado.
     * @param filePath Ruta del archivo OBJ a cargar.
     * @return true si la carga fue exitosa, false en caso contrario.
     */
    bool
    LoadOBJModel(const std::string& filePath);

    /**
     * @brief Obtiene la lista de nombres de archivos de texturas cargadas.
     * @return Vector de nombres de archivos de texturas.
     */
    std::vector<std::string>
        GetTextureFileNames() const { return textureFileNames; }

private:
    FbxManager* lSdkManager;               ///< Gestor de FBX utilizado para cargar y administrar escenas.
    FbxScene* lScene;                      ///< Escena cargada en memoria del archivo FBX.
    std::vector<std::string> textureFileNames; ///< Lista de nombres de texturas encontradas en el modelo.

public:
    std::vector<MeshComponent> meshes;     ///< Lista de componentes de malla generados a partir del modelo cargado.
};
