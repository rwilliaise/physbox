
#pragma once

#include "../System.h"

#include <btBulletDynamicsCommon.h>
#include <memory>

namespace phys {

	class PhysicsSystem : public sh::System {
	public:

		void update(double delta, sh::Scene &scene);
		void addRigid(sh::Entity &entity);	

	private: 
		btDbvtBroadphase broad;
		btDefaultCollisionConfiguration config;
		btCollisionDispatcher dispatch = btCollisionDispatcher(&config);
		btSequentialImpulseConstraintSolver solver;

		btDiscreteDynamicsWorld world = btDiscreteDynamicsWorld(
			&dispatch,
			&broad,
			&solver, 
			&config
		);

		std::vector<btRigidBody> rigids;
	};
} // phys
