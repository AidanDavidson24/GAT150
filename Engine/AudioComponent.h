#pragma once
#include "Component.h"
#include <string>

namespace neu
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		bool PlayOnAwake = false;
		float Volume = 5;
		float m_pitch = 1;
		bool loop = false;

	};
}