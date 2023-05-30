// GcodeParser.cpp : スタティック ライブラリ用の関数を定義します。
//
#include "pch.h"

#ifdef _MSC_VER
#pragma	warning( disable : 4819 )		// codepage
#endif
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"
#include "GcodeParser.h"

using std::string;
using namespace boost;
using namespace boost::spirit;
namespace sw = qi::standard_wide;		// 2byte文字対応

//////////////////////////////////////////////////////////////////////
//	Parser definitions

template<typename Iterator, typename Skipper>
struct GP : qi::grammar<Iterator, Skipper, string()>
{
	qi::rule<Iterator, Skipper, string()>	rule;

	GP() : GP::base_type(rule) {
		using sw::char_;
		using qi::int_;
		using qi::float_;
		rule = qi::raw[
				(sw::upper >> float_) |		// Nomal Gcode
				(char_('/') >> -int_) |		// Optional Block Skip
				(qi::lit(',') >> (char_('R')|'C') >> float_)	// CornerR/C
		];
	}
};

typedef qi::rule<string::iterator>	SkipperType;
#define confix_p(S, E)	repository::confix(S, E)[*(sw::char_ - E)]
						// (qi::char_(S) >> *(qi::char_ - E) >> E)

//////////////////////////////////////////////////////////////////////
//	Constructor

GcodeParser::GcodeParser()
{
}

GcodeParser::GcodeParser(const char* s)
{
	SetBlock(s);
}

GcodeParser::GcodeParser(const std::string& s)
{
	SetBlock(s);
}

//////////////////////////////////////////////////////////////////////
//	Member Function

void GcodeParser::SetBlock(const char* s)
{
	m_strBlock = s;
	m_it = m_strBlock.begin();
}

void GcodeParser::SetBlock(const std::string& s)
{
	m_strBlock = s;
	m_it = m_strBlock.begin();
}

string GcodeParser::GetWord(void)
{
	static	SkipperType	skip_p = sw::space | confix_p('(', ')');
	static	GP<string::iterator, SkipperType>	gp;

	string	strWord;
	qi::phrase_parse(m_it, m_strBlock.end(), gp, skip_p, strWord);
	return strWord;
}
