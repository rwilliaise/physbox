
#include "PhysicsSystem.h"

namespace phys {
	
	void PhysicsSystem::update(double delta, sh::Scene &scene) {
		
	}

	void PhysicsSystem::addRigid(sh::Entity &entity) {
		entity.ofType(sh::CTYPE_POSITION);
	}



} // phys
