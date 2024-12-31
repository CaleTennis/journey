#pragma once
#include "WindowManager.hpp"

class Game {
public:
	Game();

	bool init();

	void processEvents();
	void update();
	void render();
	void clean();

	bool isRunning() const { return m_isRunning; }

private:
	bool m_isRunning;
	std::unique_ptr<WindowManager> m_windowManager;
};