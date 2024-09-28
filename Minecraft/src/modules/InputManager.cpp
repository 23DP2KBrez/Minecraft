#include "InputManager.h"
#include <Windows.h>

glm::vec2 InputManager::getCursorPos()
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	return glm::vec2(x, y);
}

void InputManager::lockCursor(bool value)
{
	if (!window) return;
	glfwSetInputMode(window, GLFW_CURSOR, value ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
}

void InputManager::update()
{
	if (!window) return;
	glfwPollEvents();
	for (auto& key : keyActions)
	{
		if (glfwGetKey(window, key.first) == GLFW_PRESS)
		{
			key.second();
		}
	}
}

void InputManager::bindKey(int key, std::function<void()> action)
{
	keyActions[key] = action;
}

void InputManager::setCursorPos(glm::vec2 pos)
{
	if (!window) return;
	glfwSetCursorPos(window, pos.x, pos.y);
}

bool InputManager::onMouseClick(int key)
{
	if (!window) return false;
	return glfwGetMouseButton(window, key) == GLFW_PRESS;
}

bool InputManager::onKeyPress(int key)
{
	if (!window) return false;
	return glfwGetKey(window, key) == GLFW_PRESS;
}