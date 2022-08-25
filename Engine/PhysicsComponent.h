#pragma once
#include "Component.h"
#include "Math/Vector2.h"
#include <memory>

#define VECTOR2_TO_B2VEC2(vec) (*(b2Vec2*)(&vec))
#define B2VEC2_TO_VECTOR2(vec) (*(neu::Vector2*)(&vec))

namespace neu
{
	class PhysicsComponent : public Component
	{
	public:
		CLASS_DECLARATION(PhysicsComponent)
		PhysicsComponent() = default;

		void Update() override;
		virtual void ApplyForce(const Vector2& force) { m_acceleration += force; }

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_damping = 1;

	};
}