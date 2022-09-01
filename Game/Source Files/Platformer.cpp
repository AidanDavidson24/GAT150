#include "Platformer.h"
#include "Components/EnemyComponent.h"
#include "Engine.h"

void Platformer::Initialize()
{
	neu::REGISTER_CLASS(EnemyComponent);
	m_scene = std::make_unique<neu::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "scenes/prefabs.txt","scenes/tilemap.txt","scenes/level.txt"};

	for (auto sceneName : sceneNames)
	{
		bool success = neu::json::Load(sceneName, document);
		if (!success)
		{
			LOG("could not load scene %s", sceneName);
			continue;
		}
		m_scene->Read(document);
	}
	m_scene->Initialize();

	//for (int i = 0; i < 10; i++)
	//{
	//	auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
	//	actor->m_transform.position = { neu::randomf(0,800), 100.0f };
	//	actor->Initialize();

	//	m_scene->Add(std::move(actor));
	//}
	for (int i = 0; i < 18; i++)
	{
		auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
		actor->m_transform.position = { neu::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
	for (int i = 0; i < 3; i++)
	{
		auto actor = neu::Factory::Instance().Create<neu::Actor>("Ghost");
		actor->m_transform.position = { neu::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
	for (int i = 0; i < 1; i++)
	{
		auto actor = neu::Factory::Instance().Create<neu::Actor>("Demon");
		actor->m_transform.position = { neu::randomf(0,800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
	neu::g_eventManager.Subscribe("EVENT ADD POINTS", std::bind(&Platformer::OnAddPoints, this, std::placeholders::_1));
}

void Platformer::Shutdown()
{
	m_scene->RemoveAll();
}

void Platformer::Update()
{
	switch (m_gameState)
	{
	case Platformer::gameState::titleScreen:
		/*if (neu::g_inputSystem.GetKeyState(neu::key_space) == neu::InputSystem::State::Press)
		{
			m_scene->GetActorFromName("title")->SetActive(false);

			m_gameState = gameState::startLevel;
		}*/
		break;
	case Platformer::gameState::startLevel:

		for (int i = 0; i < 10; i++)
		{


			auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
			actor->m_transform.position = { neu::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		for (int i = 0; i < 3; i++)
		{
			auto actor = neu::Factory::Instance().Create<neu::Actor>("Ghost");
			actor->m_transform.position = { neu::randomf(0,800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		break;
	case Platformer::gameState::game:
		break;
	case Platformer::gameState::playerDead:
		m_stateTimer -= neu::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = gameState::startLevel;
		}
		break;
	case Platformer::gameState::gameOver:
		break;
	default:
		break;
	}
	m_scene->Update();
}

void Platformer::Draw(neu::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void Platformer::OnAddPoints(const neu::Event& event)
{
	std::cout << event.name << std::endl;
	std::cout << std::get<int>(event.data) << std::endl;
	std::cout << GetScore() << std::endl;
}

void Platformer::OnPlayerDead(const neu::Event& event)
{
	m_gameState = gameState::playerDead;
	m_stateTimer = 3;
	m_lives--;
}
