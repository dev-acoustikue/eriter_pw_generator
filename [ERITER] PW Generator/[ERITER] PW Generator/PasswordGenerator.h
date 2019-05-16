// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

#pragma once

#include "ConsoleOut.h"

#include <string>
#include <filesystem>

#ifndef _COMPILATION_MODE_
#define _COMPILATION_MODE_
#endif

// functions
namespace eriter_extended {

	//
	// namespace filesystem
	namespace fs = std::experimental::filesystem; // still experimental??

	// Just prints banner and title.
	inline void applicationSet() {

		SET_APPLICATION_TITLE("Password Random Generator va.0.0.01.31");

		PRINT_BANNER("[ERITER] Password Random Generator va.0.0.01.31");
		PRINT_BANNER("Windows 7 Enterprise 32-bit, VS Professional 2015, VS Platform Tool 15");
		PRINT_BANNER("Operations Information & Communication Wing");
		PRINT_BANNER("System Development Department, Air-Defense Guided Missile System Team");
		PRINT_BANNER("KTMO-CELL S/W Support, SukJoon Oh(17-70010114)");
		PRINT_BANNER("Copyright. 2019, All rights reserved.");

		_jcode::ConsoleOut::printSystemMsg(_COMPILATION_MODE_);
	};

	// Application starting node directory.
	inline const std::string applicationCurrentDir() {
		
		return fs::path(".").string();
	};


	// 
	inline const int applicationCommandAppInitList() {
		


		return 0;
	};
};


