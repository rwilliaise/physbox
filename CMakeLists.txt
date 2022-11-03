cmake_minimum_required(VERSION 3.21)
project(physbox)

set(PHYSICS_SOURCES
	physics/PhysicsSystem.cpp
)

set(RENDER_SOURCES
	
)

set(PHYSBOX_SOURCES
	Scene.cpp
	main.cpp
)

if(WIN32)
	find_package(Bullet CONFIG REQUIRED)
	find_package(glm REQUIRED)
else()
	find_package(Bullet REQUIRED)
	find_package(glm REQUIRED)
endif()

add_library(physbox_phys STATIC ${PHYSICS_SOURCES})
target_link_libraries(physbox_phys PRIVATE BulletDynamics BulletCollision Bullet3Common LinearMath)
target_include_directories(physbox_phys PRIVATE ${BULLET_INCLUDE_DIRS})

add_executable(physbox
	${PHYSBOX_SOURCES}
)
target_link_libraries(physbox PRIVATE physbox_phys)

if(WIN32)
	target_link_libraries(physbox_phys PRIVATE glm::glm)
elseif()
	target_link_libraries(physbox_phys PRIVATE glm)
endif()
