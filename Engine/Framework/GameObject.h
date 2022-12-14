#pragma once
#include "../Math/Transform.h"
#include "Serialization/Serialization.h"

#define CLASS_DECLARATION(class) \
	std::unique_ptr<GameObject> Clone() { return std::make_unique<class>(*this); }
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

		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;
	protected:

	};
}