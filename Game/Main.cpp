#include "Engine.h"
#include <iostream>

using namespace std;

void f(int i, ...) // ... = any number of parameters
{

}


int main()
{
	neu::InitializeMemory();
	neu::SetFilePath("../Assets");


	neu::g_audioSystem.Initialize();
	neu::g_inputSystem.Initialize();
	neu::g_renderer.Initialize();
	neu::g_resources.Initialize();
	neu::g_physicsSystem.Initialize();

	neu::g_renderer.CreateWindow("Technoblade Neva Diessss", 800, 600);
	neu::g_renderer.SetClearColor(neu::Color{ 10, 10, 10, 255 });

	neu::Engine::Instance().Register();
	//std::shared_ptr<neu::Texture> texture = neu::g_resources.Get<neu::Texture>("sf2.bmp", neu::g_renderer);
	//texture->Create(neu::g_renderer, "sf2.bmp");
	//neu::g_audioSystem.AddAudio("Fart")

	//std::shared_ptr<neu::Model> model = neu::g_resources.Get<neu::Model>("enemy.txt");//std::make_shared<neu::Model>();
	//model->Create("Assets/enemy.txt");

	neu::Scene scene;

	rapidjson::Document document;
	bool success = neu::json::Load("level.txt", document);
	assert(success);

	scene.Read(document);
	scene.Initialize();

	for (int i = 0; i < 10; i++)
	{
		auto actor = neu::Factory::Instance().Create<neu::Actor>("Coin");
		actor->m_transform.position = { neu::randomf(0,800), 100.0f };
		actor->Initialize();

		scene.Add(std::move(actor));
	/*
	neu::Transform transform{ neu::Vector2{400,300 }, 90, { 1, 1} };
	std::unique_ptr<neu::Actor> actor = std::make_unique <neu::Actor>(transform);
	std::unique_ptr<neu::PlayerComponent> pcomponent = std::make_unique <neu::PlayerComponent>();
	actor->AddComponent(std::move(pcomponent));

	std::unique_ptr<neu::ModelComponent> mcomponent = std::make_unique <neu::ModelComponent>();
	mcomponent->m_model = model;
	actor->AddComponent(std::move(mcomponent));
	//std::unique_ptr<neu::SpriteComponent> scomponent = std::make_unique <neu::SpriteComponent>();
	//scomponent->m_texture = texture;
	//actor->AddComponent(std::move(scomponent));
	std::unique_ptr<neu::AudioComponent> acomponent = std::make_unique <neu::AudioComponent>();
	actor->AddComponent(std::move(acomponent));
	std::unique_ptr<neu::PhysicsComponent> phcomponent = std::make_unique <neu::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));

	neu::Transform transformC{ neu::Vector2{40,30 }, 0, { 1, 1} };
	std::unique_ptr<neu::Actor> child = std::make_unique <neu::Actor>(transformC);

	std::unique_ptr<neu::ModelComponent> mcomponentC = std::make_unique <neu::ModelComponent>();
	mcomponentC->m_model = model;
	child->AddComponent(std::move(mcomponentC));

	actor->AddChild(std::move(child));

	scene.Add(std::move(actor));

	//auto texture = neu::g_resources.Get<neu::Texture>("textures/blue_01.png", neu::g_renderer);

	float angle = 0;
	*/

	bool quit = false;
	while (!quit)
	{
		neu::g_time.Tick();
		neu::g_inputSystem.Update();
		neu::g_audioSystem.Update();
		neu::g_physicsSystem.Update();

		if (neu::g_inputSystem.GetKeyDown(neu::key_escape)) quit = true;
		
		scene.Update();

		neu::g_renderer.BeginFrame();

		scene.Draw(neu::g_renderer);

		neu::g_renderer.EndFrame();
	}


	scene.RemoveAll();
	neu::Factory::Instance().Shutdown();

	neu::g_renderer.Shutdown();
	neu::g_audioSystem.Shutdown();
	neu::g_physicsSystem.Shutdown();
	neu::g_inputSystem.Shutdown();
	neu::g_resources.Shutdown();


}