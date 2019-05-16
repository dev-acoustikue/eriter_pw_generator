// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

// Include this file when writing Windows console application.
// customized.

#pragma once

// Console Options
#include <Windows.h>

#include <iostream> // never use default namespace std.
#include <string>

#ifndef _CONSOLE_APPLICATION_
#define _CONSOLE_APPLICATION_
#endif

#ifdef _CONSOLE_APPLICATION_

#define COUT	std::cout
#define CIN		std::cin
#define ENDL	std::endl

#define _WINDOW_CONSOLE_TEXT_ATTRIBUTES_
#ifdef _WINDOW_CONSOLE_TEXT_ATTRIBUTES_


#define TEXT_BLACK			0x0000
#define TEXT_BLUE			0x0001
#define TEXT_GREEN			0x0002
#define TEXT_CYAN			0x0003
#define TEXT_RED			0x0004
#define TEXT_MAGENTA		0x0005
#define TEXT_BROWN			0x0006
#define TEXT_LIGHTGRAY		0x0007
#define	TEXT_DARKGRAY		0x0008
#define TEXT_LIGHTBLUE		0x0009
#define TEXT_LIGHTGREEN		0x000A
#define TEXT_LIGHTCYAN		0x000B
#define TEXT_LIGHTRED		0x000C
#define TEXT_LIGHTMAGENTA	0x000D
#define TEXT_YELLOW			0x000E
#define TEXT_WHITE			0x000F

#endif


// Sets text colour.
#define SET_TEXT_COLOR(AT_CODE) \
	do { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AT_CODE); } while (0)

// Locks and unlocks the scope.
// Exactly the same.
#define LEASH_TEXT_COLOR(AT_CODE) \
	do { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), AT_CODE); } while (0)
#define UNLEASH_TEXT_COLOR() \
	do { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TEXT_WHITE); } while (0)

#define SET_APPLICATION_TITLE(TITLE) \
	do { SetConsoleTitle(TITLE); } while (0)


// Extra utils.
// namespace eriter {
namespace _jcode {

	class ConsoleOut final { // Wrapper
	public:
		// printSystemMsg()
		//
		static inline void printSystemMsg(const char* argMsg) {
			LEASH_TEXT_COLOR(TEXT_YELLOW); 			
				COUT << "SYS: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		/*static inline void printSystemMsg(const std::string argMsg) {
			LEASH_TEXT_COLOR(TEXT_YELLOW);
				COUT << "SYS: " << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};*/

		static inline void printSystemMsg(const std::string& argMsg) {
			LEASH_TEXT_COLOR(TEXT_YELLOW);
				COUT << "SYS: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		// printBanner()
		//
		static inline void printBanner(const char* argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTGRAY);
				COUT << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		static inline void printBanner(const std::string& argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTGRAY);
				COUT << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		// printMsg()
		//
		static inline void printNormalMsg(const char* argMsg) {
			LEASH_TEXT_COLOR(TEXT_CYAN);
				COUT << "MSG: \t";
			//UNLEASH_TEXT_COLOR();
			//LEASH_TEXT_COLOR(TEXT_WHITE);
				COUT << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		/*static inline void printNormalMsg(const std::string argMsg) {
			LEASH_TEXT_COLOR(TEXT_CYAN);
			COUT << "MSG: ";
			UNLEASH_TEXT_COLOR();
			LEASH_TEXT_COLOR(TEXT_WHITE);
			COUT << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};*/

		static inline void printNormalMsg(const std::string& argMsg) {
			LEASH_TEXT_COLOR(TEXT_CYAN);
				COUT << "MSG: \t";
			//UNLEASH_TEXT_COLOR();
			//LEASH_TEXT_COLOR(TEXT_WHITE);
				COUT << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		// printErrorMsg()
		//
		static inline void printErrorMsg(const char* argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTRED);
				COUT << "ERR: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		static inline void printErrorMsg(const std::string& argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTRED);
				COUT << "ERR: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		// printLog()
		//
		static inline void printLog(const char* argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTGRAY);
				COUT << "LOG: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};

		static inline void printLog(const std::string& argMsg) {
			LEASH_TEXT_COLOR(TEXT_LIGHTGRAY);
			COUT << "LOG: \t" << argMsg << ENDL;
			UNLEASH_TEXT_COLOR();
		};
	};
};
// };

#endif

//
// For easy use.

#define PRINT_SYSTEM_MSG(STR)	_jcode::ConsoleOut::printSystemMsg(STR)
#define PRINT_BANNER(STR)		_jcode::ConsoleOut::printBanner(STR)
#define PRINT_NORMAL_MSG(STR)	_jcode::ConsoleOut::printNormalMsg(STR)
#define PRINT_ERROR_MSG(STR)	_jcode::ConsoleOut::printErrorMsg(STR)
#define PRINT_LOG(STR)			_jcode::ConsoleOut::printLog(STR)



#undef _CONSOLE_APPLICATION_
#undef _WINDOW_CONSOLE_TEXT_ATTRIBUTES_