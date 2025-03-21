#pragma once
#include "Prerequisites.h"
#include "DeviceContext.h"

/**
 * @brief Representa una malla básica que contiene vértices e índices.
 *
 * Esta clase almacena la geometría necesaria para representar un modelo 3D simple.
 */
class 
MeshComponent
{
public:
	MeshComponent() : m_numVertex(0), m_numIndex(0) {}
	~MeshComponent() = default;

public:
	std::string m_name;                       ///< Nombre identificador de la malla.
	std::vector<SimpleVertex> m_vertex;       ///< Lista de vértices que componen la malla.
	std::vector<unsigned int> m_index;        ///< Lista de índices para definir la topología.
	int m_numVertex;                          ///< Número total de vértices.
	int m_numIndex;                           ///< Número total de índices.
};
