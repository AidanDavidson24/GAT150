#include "Actor.h"
#include "RenderComponent.h"
#include "../Math/MathUtils.h"

namespace neu
{
	void Actor::Update()
	{
		for (auto& component : m_components)
		{
			component->Update();

		}
		for (auto& child : m_children)
		{
			child->Update();
		}
		if (m_parent) m_transform.Update(m_parent->m_transform.matrix);
		else m_transform.Update();
	}

	void Actor::Draw(Renderer& renderer)
	{
		//m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
		for (auto& component : m_components)
		{
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent)
			{
				renderComponent->Draw(renderer);
			}
		}
		for (auto& child : m_children)
		{
			child->Draw(renderer);
		}
	}

	void Actor::AddChild(std::unique_ptr<Actor> child)
	{
		child->m_parent = this;
		child->m_scene = this->m_scene;
		m_children.push_back(std::move(child));
	}

	void Actor::AddComponent(std::unique_ptr<Component> component)
	{
		component->m_owner = this;
		m_components.push_back(std::move(component));
	}
	bool Actor::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool Actor::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, tag);
		READ_DATA(value, name);

		return true;
	}
}
