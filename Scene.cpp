
#include "Scene.h"
#include "Entity.h"

namespace sh {

	std::vector<std::pair<Entity *, Component *>> Scene::ofType(ComponentType type) {
		std::vector<std::pair<Entity *, Component *>> out;

		for (auto& entity : entities) {
			for (auto component : entity.components) {
				if (component != nullptr && component->type == type) {
					out.push_back(std::make_pair(&entity, component));
				}
			}
		}

		return out;
	}

} // sh
