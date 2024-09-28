#pragma once
#include "glm/glm.hpp"

class Camera
{
public:
	Camera() = default;
	Camera(float fov, glm::vec2 resolution);

	glm::vec3 position;
	glm::vec3 rotation;

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix() { return projection; };
private:
	glm::mat4 projection;
};