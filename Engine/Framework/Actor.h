#pragma once
#include "GameObject.h"
#include "Component.h"
#include "../Renderer/Model.h"
#include "Math/Transform.h"
#include <vector>
#include <string>

namespace neu
{
	class Scene;
	class Component;
	class Renderer;
	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Actor& other);
		Actor(const Transform& transform) : m_transform{ transform }  {}

		CLASS_DECLARATION(Actor)

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);

		void AddChild(std::unique_ptr<Actor> child);

		void AddComponent(std::unique_ptr<Component> component);
		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; }// m_model.GetRadius();
	
		const std::string& GetTag() { return tag; }
		void SetTag(const std::string& tag) { this->tag = tag; }

		const std::string& GetName() { return name; }
		void SetName(const std::string& name) { this->name = name; }

		void SetDestroy() { m_destroy = true; }

		void SetActive(bool active = true) { this->active = active; }
		bool IsActive() { return active; }

		Scene* GetScene() { return m_scene; }
		friend class Scene;
		friend class Component;

		Transform m_transform;

	protected:
		std::string tag;
		std::string name;

		bool active = true;
		bool m_destroy = false;
		float lifespan = 0;

		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;
		Model* m_model = nullptr;
		Actor* m_parent = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};

	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}

		return nullptr;
	}
}
