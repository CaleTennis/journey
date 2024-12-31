#pragma once
#include "WindowManager.hpp"
#include "AssetManager.hpp"

class WindowManager;
class AssetManager;	

class Game {
	friend class WindowManager;
public:
	Game() = delete;

	static bool init();

	static void processEvents();
	static void update();
	static void render();
	static void clean();

	static bool isRunning() { return m_isRunning; }

private:
	static bool m_isRunning;
	static std::unique_ptr<WindowManager> m_windowManager;
	static std::unique_ptr<AssetManager> m_assetManager;
};