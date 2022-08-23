#pragma once
#include "box2d/b2_world.h" 
#include "box2d/box2d.h"
#include <memory> 

namespace neu
{
	class PhysicsSystem
	{
	public:
		struct RigidBody
		{
			float gravity_scale = 1;
			bool Constrain_angle = false;
			bool is_dynamic = true;
		};
		struct CollisionData
		{
			Vector2 size;
			float density = 1;
			float friction = 1;
			float restitution = 0.3f;
			bool is_trigger = false;
		};
	public:
		PhysicsSystem() = default;
		~PhysicsSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		b2Body* CreateBody(const Vector2& position, float angle, const RigidBodyData& data);
		void DestroyBody(b2Body* body);

		void SetCollisionBox(b2Body* body, const CollisionData& data, class Actor* actor = nullptr);

		static Vector2 WorldToScreen(const Vector2& world) { return world * pixelsPerUnit; }
		static Vector2 ScreenToWorld(const Vector2& screen) { return screen * (1.0f / pixelsPerUnit); }

	private:
		static const float pixelsPerUnit;

		std::unique_ptr<b2World> m_world;
	};
}