#pragma once
#include "../Math/Transform.h"
#include "Serialization/Serialization.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);
namespace neu
{
	class GameObject
	{
	public:
		GameObject() = default;
		GameObject(const Transform& transform) : m_transform{ transform } {}

		Transform& GetTransform() { return m_transform; }

		Transform m_transform;

		virtual void Initialize() = 0;
		virtual void Update() = 0;
	protected:

	};
}