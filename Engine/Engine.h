#pragma once

#include "Serialization/Json.h" 


#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ModelComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"
#include "Components/CameraComponent.h"

#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Core/Logger.h"

#include "Renderer\Font.h"
#include "Renderer/Text.h"
#include "Audio/AudioSystem.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"
#include "Physics/PhysicsSystem.h"
#include "Components/RBPhysicsComponent.h"
#include "Framework/Singleton.h"
#include "Framework/EventManager.h"

#include "Audio/AudioSystem.h"
#include "Resource/ResourceManager.h"

#include <memory>
#include <vector>
#include <list>
#include <variant>

namespace neu
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;
	
	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}