#pragma once
#include "Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
namespace neu
{
	class CollisionComponent : public Component, public ICollision
	{
	public:
		virtual void Initialize();
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual void Write(const rapidjson::Value& value) const override;
		virtual void Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData data;
	};

}