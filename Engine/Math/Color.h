#pragma once
#include <cstdint>
#include <sstream>
#include <iostream>

namespace neu
{
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		uint8_t operator [] (size_t index) const { return (&r)[index]; }
		uint8_t& operator [] (size_t index) { return (&r)[index]; }
	};
		
	std::istream& operator >> (std::istream& stream, Color& color);
	std::ostream& operator << (std::ostream& stream, const Color& color);
}