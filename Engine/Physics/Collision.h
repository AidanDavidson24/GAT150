#pragma once
#include "Framework/Actor.h"
namespace neu
{
	class ICollision
	{
	public:
		virtual void OnCollisionEnter(Actor* other) = 0;
		virtual void OnCollisionExit(Actor* other) = 0;
	};
}