// GcodeParser.cpp : スタティック ライブラリ用の関数を定義します。
//

#include "pch.h"
#include "framework.h"

#pragma	warning( disable : 4819 )		// codepage
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"
#include "GcodeParser.h"

//////////////////////////////////////////////////////////////////////
//	Constructor

GcodeParser::GcodeParser()
{
}

GcodeParser::GcodeParser(const char* s)
{
	m_strBlock = s;
	m_it = m_strBlock.begin();
}

GcodeParser::GcodeParser(const std::string& s)
{
	m_strBlock = s;
	m_it = m_strBlock.begin();
}
