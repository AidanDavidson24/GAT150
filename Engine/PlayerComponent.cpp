#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void neu::PlayerComponent::Update()
{
	Vector2 direction = Vector2{ 0, 0 };

	if (g_inputSystem.GetKeyState(key_a) == InputSystem::State::Held)
	{
		direction = Vector2::left;
	}

	if (g_inputSystem.GetKeyState(key_d) == InputSystem::State::Held)
	{
		direction = Vector2::right;
	}

	/*float thrust = 0;
	if (g_inputSystem.GetKeyState(key_w) == InputSystem::State::Held)
	{
		thrust = 100;
	}

	if (g_inputSystem.GetKeyState(key_s) == InputSystem::State::Held)
	{
		thrust = -100;
	}*/

	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		//Vector2 force = Vector2::Rotate({ 1, 0 }, neu::DegToRad(m_owner->m_transform.rotation)) * thrust;
		component->ApplyForce(direction * 50);
	}
}

bool neu::PlayerComponent::Write(const rapidjson::Value& value) const
{
	return false;
}

bool neu::PlayerComponent::Read(const rapidjson::Value& value)
{
	return false;
}
