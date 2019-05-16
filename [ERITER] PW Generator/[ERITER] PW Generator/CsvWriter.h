// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

#pragma once

#include <string>
#include <fstream>


namespace _jcode {

	class CsvWriter final {
	private:
		std::string FileName;	
		// file
		std::ofstream CsvFile;

		// core
		const int core();

	public:
		// ctor 
		CsvWriter(const std::string&);
		virtual ~CsvWriter(); // dtor

		// interface
		const int openFileToWrite() noexcept;
		const int closeFile() noexcept;

		const int writeLine(const std::string&) noexcept;

		void setFileNameOption(const std::string&) noexcept;
	
	};

};
