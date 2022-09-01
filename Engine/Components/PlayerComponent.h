#pragma once
#include "Framework/Component.h"
#include "CharacterComponent.h"

namespace neu
{
	class PlayerComponent : public CharacterComponent
	{
	public:
		CLASS_DECLARATION(PlayerComponent)
		PlayerComponent() = default;

		void Update() override;
		int m_groundCount = 0;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
		virtual void OnNotify(const Event& event) override;
	};
}