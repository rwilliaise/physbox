
#pragma once

#include "Entity.h"
#include "System.h"

#include <vector>
#include <bitset>
#include <map>

namespace sh {

	class Scene {
	public:

		std::vector<std::pair<Entity *, Component *>> ofType(ComponentType type);

		inline void addSystem(System& system) {
			systems.push_back(system);
		}

		inline void update() {
			for (auto& system : systems) {
				system.update(*this);
			}
		}

	private:

		std::vector<Entity> entities;
		std::vector<System> systems;
	};

} // sh

