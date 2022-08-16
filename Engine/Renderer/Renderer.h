#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include "../Texture.h"
#include "Math/Transform.h"
//#include <SDL.h>


struct SDL_Renderer;
struct SDL_Window;

namespace neu
{
	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;

		void Initialize();
		void Shutdown();
		void CreateWindow(const char* name, int width, int height);	
		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color& color) { m_clearColor = color; }

		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color);
		void DrawPoint(float x, float y);
		void DrawPoint(const Vector2& v, const Color& color);
		//void Draw(std::shared_ptr<Texture> texture, const Vector2& position, float angle = 0);
		//void Draw(std::shared_ptr<Texture> texture, const Transform& transform);
		//void Draw(std::shared_ptr<Texture> texture, const SDL_Rect source, const Transform& transform);
		void Draw(Renderer& renderer, std::shared_ptr<Texture> texture, const Vector2& position, float angle, Vector2& scale);
		void Draw(Renderer& renderer, std::shared_ptr<Texture> texture, const Transform& transform);

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height; }

		auto GetRenderer() { return m_renderer; }

		friend class Texture;

	private:
		int m_width = 0;
		int m_height = 0;

		Color m_clearColor{ 0, 0, 0, 255 };

		SDL_Renderer* m_renderer = nullptr;
		SDL_Window* m_window = nullptr;
	};
}