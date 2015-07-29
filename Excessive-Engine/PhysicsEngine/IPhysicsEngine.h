#pragma once
#include "mymath/mymath.h"
#include "SupportLibrary/BasicTypes.h"
#include "PhysicsCommon.h"

#include <vector>

class IPhysicsEngine
{
public:
	virtual void Release() = 0;

	virtual void Update(float deltaTime) = 0;

	// Create, Add DYNAMIC rigid body to physics world
	virtual physics::IRigidBodyEntity* AddEntityRigidDynamic(mm::vec3* vertices, u32 nVertices, float mass = 1) = 0;

	// Create, Add STATIC rigid body to physics world
	virtual physics::IRigidBodyEntity* AddEntityRigidStatic(mm::vec3* vertices, u32 nVertices, void* indices, u32 indexSize, u32 nIndices) = 0;

	// Create, Add capsule rigid body to physics world
	virtual physics::IRigidBodyEntity* AddEntityRigidCapsule(float height, float radius, float mass) = 0;

	// Remove rigidBody entity from world
	virtual bool RemoveEntity(physics::IRigidBodyEntity* e) = 0;

	virtual void SetLayerCollision(size_t ID0, size_t ID1, bool bEnableCollision) = 0;

	virtual bool CheckLayerCollision(size_t ID0, size_t ID1) const = 0;

	virtual const std::vector<rPhysicsCollision>& GetCollisionList() const = 0;

	virtual bool GetDebugData(mm::vec3*& linesFromNonUniqPoints_out, size_t& nLines_out) const = 0;
};