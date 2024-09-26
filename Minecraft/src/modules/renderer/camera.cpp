#include "camera.h"
#include "glm/gtc/matrix_transform.hpp"

Camera::Camera(float fov, glm::vec2 resolution)
{
	projection = glm::perspective(glm::radians(fov), resolution.x / resolution.y, 0.1f, 1000.0f);
}

glm::mat4 Camera::getViewMatrix()
{
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::rotate(view, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	view = glm::rotate(view, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	view = glm::rotate(view, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	view = glm::translate(view, -position);
	return view;
}