#pragma once

#include <string>

//////////////////////////////////////////////////////////////////////
//	GcodeParser.h

class GcodeParser
{
	std::string				m_strBlock;
	std::string::iterator	m_it;

public:
	GcodeParser();
	GcodeParser(const char*);
	GcodeParser(const std::string&);

	void	SetBlock(const char*);
	void	SetBlock(const std::string&);

	std::string	GetWord(void);
};
