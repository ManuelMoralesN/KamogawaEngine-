#include "ECS/Transform.h"
#include "DeviceContext.h"

void 
Transform::init(){
	scale.one(); // inicializa la escala a 1

	matrix = XMMatrixIdentity();
}

void 
Transform::update(float deltaTime) {
	//aplicar escala
	XMMATRIX scaleMatrix = XMMatrixScaling(scale.x, scale.y, scale.z);
	//aplicar rotacion
	XMMATRIX rotationMatrix = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, rotation.z);
	//aplicar traslacion
	XMMATRIX traslationMatrix = XMMatrixTranslation(position.x, position.y, position.z);

	//componer la matrix final en el orden: scale -> rotation -> translation
	matrix = scaleMatrix * rotationMatrix * traslationMatrix;
}

void 
Transform::setTransform(const EngineUtilities::Vector3& newPos, 
						const EngineUtilities::Vector3& newRot, 
						const EngineUtilities::Vector3& newSca) {
	position = newPos;
	rotation = newRot;
	scale = newSca;
}

void
Transform::translate(const EngineUtilities::Vector3& translation) {

}
