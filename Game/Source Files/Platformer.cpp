#include "Platformer.h"
#include "Engine.h"

void Platformer::Initialize()
{
	m_scene = std::make_unique<neu::Scene>();

	rapidjson::Document document;
	bool success = neu::json::Load("level.txt", document);
	assert(success);

	m_scene->Read(document);
	m_scene->Initialize();

	for (int i = 0; i < 10; i++)
	{
		auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
		actor->m_transform.position = { neu::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
}

void Platformer::Shutdown()
{

}

void Platformer::Update()
{
	m_scene->Update();
}

void Platformer::Draw(neu::Renderer& renderer)
{
	m_scene->Draw(renderer);
}
