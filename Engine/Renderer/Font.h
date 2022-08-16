#pragma once
#include "Resource/Resource.h"
#include <string>

struct _TTF_Font;

namespace neu
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		virtual bool Create(std::string name, ...) override;
		bool Load(const std::string& filename, int fontSize);

		friend class Text;

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}