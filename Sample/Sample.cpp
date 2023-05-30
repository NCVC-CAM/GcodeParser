// Sample.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#ifdef QT_VERSION
#include <QCoreApplication>
#endif

#include <iostream>
#include <string>
#include "../GcodeParser/GcodeParser.h"

using namespace std;

int main()
{
	GcodeParser	gp;
	string	s, w;

	while ( getline(cin, s) ) {
		gp.SetBlock(s);
		while ( !(w=gp.GetWord()).empty() ) {
			cout << "<" << w << "> ";
		}
		cout << "\n";
	}
}
