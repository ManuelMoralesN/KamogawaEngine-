#pragma once
#include "Prerequisites.h"
#include "DeviceContext.h"

/**
 * @brief Representa una malla b�sica que contiene v�rtices e �ndices.
 *
 * Esta clase almacena la geometr�a necesaria para representar un modelo 3D simple.
 */
class 
MeshComponent
{
public:
	MeshComponent() : m_numVertex(0), m_numIndex(0) {}
	~MeshComponent() = default;

public:
	std::string m_name;                       ///< Nombre identificador de la malla.
	std::vector<SimpleVertex> m_vertex;       ///< Lista de v�rtices que componen la malla.
	std::vector<unsigned int> m_index;        ///< Lista de �ndices para definir la topolog�a.
	int m_numVertex;                          ///< N�mero total de v�rtices.
	int m_numIndex;                           ///< N�mero total de �ndices.
};
