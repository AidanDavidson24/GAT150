#include "Engine.h"

namespace neu
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	AudioSystem g_audioSystem;
	Time g_time;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
	}
}