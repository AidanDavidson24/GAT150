#pragma once
#include "Component.h"

namespace neu
{
	class PlayerComponent : public Component
	{
	public:
		CLASS_DECLARATION(PlayerComponent)
		PlayerComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}