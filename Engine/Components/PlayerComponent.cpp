#include "PlayerComponent.h"
#include "CharacterComponent.h"
#include "Engine.h"
#include <iostream>

void neu::PlayerComponent::Update()
{
	Vector2 direction = Vector2{ 0, 0 };

	if (g_inputSystem.GetKeyState(key_a) == InputSystem::State::Held)
	{
		std::cout << "KeyPressedA\n";
		direction = Vector2::left;
	}

	if (g_inputSystem.GetKeyState(key_d) == InputSystem::State::Held)
	{
		direction = Vector2::right;
	}
	if (g_inputSystem.GetKeyState(key_w) == InputSystem::State::Held)
	{
		direction = Vector2::up;
	} 
	Vector2 velocity;
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		float multiplier = (m_groundCount > 0) ? 1 : 0.2f;

		component->ApplyForce(direction * speed);
		velocity = component->m_velocity;
	}
	//auto component = m_owner->GetComponent<PhysicsComponent>();
	//if (component)
	//{
	//	//Vector2 force = Vector2::Rotate({ 1, 0 }, neu::DegToRad(m_owner->m_transform.rotation)) * thrust;
	//	component->ApplyForce(direction * 50);
	//}

	auto camera = m_owner->GetScene()->GetActorFromName("Camera");
	if (camera)
	{
		camera->m_transform.position = neu::Lerp(camera -> m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime);
	}

	auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
	if (animComponent)
	{
		if (velocity.x != 0) animComponent->SetFlipHorizontal(velocity.x < 0);
		if (std::fabs(velocity.x) > 0)
		{
			animComponent->SetSequence("run");
		}
		else
		{
			animComponent->SetSequence("idle");
		}
	}
}

bool neu::PlayerComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool neu::PlayerComponent::Read(const rapidjson::Value& value)
{
	CharacterComponent::Read(value);

	return true;
}

void neu::PlayerComponent::OnCollisionEnter(Actor* other)
{
	if (other->GetName() == "Coin") {

		Event event;

		event.name = "EVENT_ADD_POINTS";

		event.data = 100;

		g_eventManager.Notify(event);

		other->SetDestroy();

	}

	std::cout << "player enter\n";

}

void neu::PlayerComponent::OnCollisionExit(Actor* other)
{
	std::cout << "player enter\n";
}

void neu::PlayerComponent::OnNotify(const Event& event)
{
	if (event.name == "Event_Damage")
	{
		health -= std::get<float>(event.data);
		std::cout << health << std::endl;

		if (health <= 0)
		{
			// player dead
		}
	}
}
