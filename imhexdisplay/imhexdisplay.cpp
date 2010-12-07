#include <iostream>
#include <string>
#include <sstream>
#include <exception>

#include "imdebug.h"

std::string imdebug_string(const char * format)
{
	std::stringstream stream;
	stream << format << " w=%d h=%d %p";
	return stream.str();
}

inline bool is_valid_hex_char(char c)
{
	return (c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'f') ||
		(c >= 'A' && c <= 'F');
}

inline unsigned char char_from_hex(char h)
{
	if(h >= '0' && h <= '9')
		return h - '0';
	else if(h >= 'a' && h <= 'f')
		return h - 'a' + 10;
	else if(h >= 'A' && h <= 'F')
		return h - 'A' + 10;
	throw std::exception();
}

inline unsigned char hex_to_byte(char a, char b)
{
	return char_from_hex(a) * 16 + char_from_hex(b);
}

struct pixels_from_hex_result
{
	unsigned char * pixels;
	unsigned int num_channels;
};

pixels_from_hex_result pixels_from_hex(const std::string & hex)
{
	unsigned char * pixels = (unsigned char *)::operator new(hex.size());

	size_t i = 0, j = 0;
	char first;

	for(std::string::const_iterator it = hex.begin(); it != hex.end(); ++it)
	{
		if(!is_valid_hex_char(*it)) continue;
		if(++i % 2 == 0)
			pixels[j++] = hex_to_byte(first, *it);
		else
			first = *it;
	}

	pixels_from_hex_result ret = {pixels, j};
	return ret;
}

int main()
{
	unsigned int width;
	std::string format;

	std::cin >> format >> width;

	std::stringstream stream;
	std::string buffer;
	while(std::getline(std::cin, buffer))
	{
		stream << buffer;
	}

	pixels_from_hex_result px = pixels_from_hex(stream.str());

	imdebug(imdebug_string(format.c_str()).c_str(), width,
		(px.num_channels / format.length() / width - 1), px.pixels);

	return 0;
}