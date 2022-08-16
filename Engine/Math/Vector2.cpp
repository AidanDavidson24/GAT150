#include "Vector2.h"

namespace neu
{
	std::istream& operator >> (std::istream& stream, Vector2& v)
	{
		std::string line;
		std::getline(stream, line);

		// { ##, ## }
		std::string xs = line.substr(line.find("{") + 1, line.find(",") - line.find("{") + 1);
		v.x = std::stof(xs);
		std::string ys = line.substr(line.find(",") + 1, line.find("}") - line.find(",") + 1);
		v.y = std::stof(ys);

		return stream;
	}
	std::ostream& operator<<(std::ostream& stream, const Vector2& v)
	{
		stream << v.x << " " << v.y;

		return stream;
	}
}