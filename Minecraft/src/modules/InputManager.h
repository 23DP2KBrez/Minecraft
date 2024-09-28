#pragma once
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include <functional>
#include <unordered_map>

class InputManager
{
public:
	InputManager(GLFWwindow *window) : window(window) {}
	glm::vec2 getCursorPos();
	void lockCursor(bool value);
	void setCursorPos(glm::vec2 pos);
	void update();

	void bindKey(int key, std::function<void()> action);

	bool onKeyPress(int key);
	bool onMouseClick(int key);

private:
	GLFWwindow* window;

	std::unordered_map<int, std::function<void()>> keyActions;
};