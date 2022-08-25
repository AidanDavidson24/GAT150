#pragma once
#include "Component.h"
#include "Physics/Collision.h"
#include "Physics/PhysicsSystem.h"
namespace neu
{
	class CollisionComponent : public Component, public ICollision
	{
	public:

		CLASS_DECLARATION(CollisionComponent)
		virtual void Initialize();
		virtual void Update() override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		PhysicsSystem::CollisionData data;
	};

}