#include "Renderer/Font.h"
#include <SDL_ttf.h>
#include "Logger.h"

namespace neu
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Load(filename, 15);
	}

	Font::~Font()
	{
		if (m_ttfFont != NULL)
		{
			TTF_CloseFont(m_ttfFont);
			m_ttfFont = nullptr;
		}
	}

	bool Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
		if (m_ttfFont == nullptr)
		{
			return false;
		}

		return true;
	}


	bool Font::Create(std::string filename, ...)
	{
		// va_list - type to hold information about variable arguments 
		va_list args;

		// va_start - enables access to variadic function arguments 
		va_start(args, filename);

		// va_arg - accesses the next variadic function arguments 
		int fontSize = va_arg(args, int);

		// va_end - ends traversal of the variadic function arguments 
		va_end(args);

		return Load(filename, fontSize);
	}

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c); 
		if (surface == nullptr)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}
}