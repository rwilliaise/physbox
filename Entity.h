
#pragma once

#include <cinttypes>
#include <cstring>
#include <bitset>

namespace sh {

	enum ComponentType {
		CTYPE_POSITION
	};

	class Component {
	private:
		friend class Entity;
		friend class Scene;

		ComponentType type;
	};

	class Entity {
	public:
		explicit Entity(uint32_t id): id(id) {
			std::memset(components, 0, 32 * sizeof(void*));
		};

	private:
		friend class Scene;

		uint32_t id;
		Component *components[32];
	};

} // sh 
