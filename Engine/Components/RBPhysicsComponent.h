#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace neu
{
	class RBPhysicsComponent : public PhysicsComponent
	{
	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		void Initialize() override;
		void Update() override;
		virtual void ApplyForce(const Vector2& force);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson :: Value& value) override;
	};

}