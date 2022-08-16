#pragma once

#include "Serialization/Json.h" 


#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "PlayerComponent.h"
#include "SpriteComponent.h"
#include "AudioComponent.h"
#include "PhysicsComponent.h"
#include "ModelComponent.h"

#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Logger.h"

#include "..\Engine\Renderer\Font.h"
#include "../Engine/Text.h"
#include "AudioSystem.h"
#include "Texture.h"
#include "Renderer/Model.h"

#include "AudioSystem.h"
#include "Resource/ResourceManager.h"

#include <memory>
#include <vector>
#include <list>

namespace neu
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resources;
}