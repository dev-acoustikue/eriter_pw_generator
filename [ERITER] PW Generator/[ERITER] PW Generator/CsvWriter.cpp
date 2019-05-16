// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//


#include <fstream>

#include "ConsoleOut.h"
#include "CsvWriter.h"

_jcode::CsvWriter::CsvWriter(const std::string& argrFileName) : FileName(argrFileName){

	// PRINT_SYSTEM_MSG("");
};

_jcode::CsvWriter::~CsvWriter() { }; // default



// core
const int _jcode::CsvWriter::core() {
	
	return 0x00;
};


// interface
const int _jcode::CsvWriter::openFileToWrite() noexcept {
	
	//if (argFileName.compare("")) {
	//	argFileName = "pw_gen"; // if blanked
	//	PRINT_NORMAL_MSG("File name set to default.");
	//	
	//} else {
		
		CsvFile.open(FileName + ".csv");
		PRINT_LOG("File " + FileName + ".csv opened.");

		return 0x00;
	
//	};
};


const int _jcode::CsvWriter::closeFile() noexcept {
	
	CsvFile.close();
	PRINT_LOG("File closed.");

	return 0x00;
};


const int _jcode::CsvWriter::writeLine(const std::string& argLine) noexcept {
	
	CsvFile << argLine << ENDL;

	return 0x00;
};


void _jcode::CsvWriter::setFileNameOption(const std::string& argOption) noexcept {

	FileName.append("_" + argOption);
};