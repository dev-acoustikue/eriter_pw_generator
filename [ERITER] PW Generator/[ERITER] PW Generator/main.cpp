// [eriter_extended] Password_Random_Generator va.0.0.01.31
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

// Either one should be defined. Otherwise, compilation would not be done.

//#define _UNIT_TEST_MODE_ "_UNIT_TEST_MODE_"
//#define _TEST_MODE_		"_TEST_MODE_"
#define _RELEASE_MODE_	"_RELEASE_MODE_"


#ifdef _UNIT_TEST_MODE_
#define _COMPILATION_MODE_	_UNIT_TEST_MODE_

#elif defined(_TEST_MODE_)
#define _COMPILATION_MODE_	_TEST_MODE_

#elif defined(_RELEASE_MODE_)
#define _COMPILATION_MODE_	_RELEASE_MODE_

#endif

#include <cstdlib>
#define PAUSE()				system("pause")
#define CALL(EXTERNAL_APP)	system(EXTERNAL_APP)


// Users
#include "ConsoleOut.h"
#include "OpTimer.h"

#include "PasswordGenerator.h"

#include "CsvWriter.h"
#include "Generator.h"

//
// main()
//

#ifdef _UNIT_TEST_MODE_

int main() try {

#define _APPLICATION_SETTINGS_
#ifdef _APPLICATION_SETTINGS_
	// Application setttings
	eriter_extended::applicationSet();

#endif

// Set _WHAT_ !!
#define _WHAT_	1

#if (_WHAT_ == 1)

	std::string sample;

	std::random_device Seed;

	std::default_random_engine Gen(Seed());
	std::uniform_int_distribution<> uniformDistribution(33, 126);

	char T;


	for (auto itor = 0; itor < 9; itor++) {
		
		while (92 == (T = uniformDistribution(Gen)))
			;
		
		//COUT << T;
		// sample.append(&T);
		sample.push_back(T);
	}


	COUT << sample;




#elif (_WHAT_ == 2)



#else


#endif





	PAUSE();

	return 0;

} catch (...) {

};

#elif defined(_TEST_MODE_)

int main() try {

	CLOCK_COUNT_START(); // counting

#define _APPLICATION_SETTINGS_
#ifdef _APPLICATION_SETTINGS_
	// Application setttings
	eriter_extended::applicationSet();

#endif

	std::string FileName;
	int PwNumber;

#define PW_SIZE	9

	// Settings
	PRINT_SYSTEM_MSG("Set file name.");
	COUT << "> ";
	CIN >> FileName;

	// locals, user-defined
		// Main
	_jcode::CsvWriter Main_First_Writer(FileName);
	Main_First_Writer.setFileNameOption("MAIN_1");
	_jcode::Generator Main_First_Gen;

	_jcode::CsvWriter Main_Second_Writer(FileName);
	Main_Second_Writer.setFileNameOption("MAIN_2");
	_jcode::Generator Main_Second_Gen;
	
		// Sub
	_jcode::CsvWriter Sub_First_Writer(FileName);
	Sub_First_Writer.setFileNameOption("SUB_1");
	_jcode::Generator Sub_First_Gen;

	_jcode::CsvWriter Sub_Second_Writer(FileName);
	Sub_Second_Writer.setFileNameOption("SUB_2");
	_jcode::Generator Sub_Second_Gen;

	// Will used as iterator
	_jcode::CsvWriter* WriterArray[4] = {

		&Main_First_Writer,
		&Main_Second_Writer,
		&Sub_First_Writer,
		&Sub_Second_Writer
	};

	// Generator
	_jcode::Generator* Gen[4] = {
		
		&Main_First_Gen,
		&Main_Second_Gen,
		&Sub_First_Gen,
		&Sub_Second_Gen
	};

	// Settings
	PRINT_SYSTEM_MSG("Set numbers to of passwords to be generated.");
	COUT << "> ";
	CIN >> PwNumber;
	

	for (int itor = 0; itor < 4; itor++) {
	
		WriterArray[itor]->openFileToWrite();


		for (auto StringList : Gen[itor]->getGeneratedStringList(PW_SIZE, PwNumber)) {
			
			WriterArray[itor]->writeLine(StringList);
			//PRINT_LOG("Writing...");

		};

		Gen[itor]->clear();
		WriterArray[itor]->closeFile();
	}


	// _jcode::ConsoleOut::printLog(CLOCK_COUNT_END());
	PRINT_SYSTEM_MSG("Duration - " + std::to_string(CLOCK_COUNT_END() / 1000.0) + "s.");
	PAUSE();

	return 0;

} catch (...) {

	PRINT_ERROR_MSG("Unknown error. Shutting down the program.");
	PAUSE();

};

// Release mode
#elif defined(_RELEASE_MODE_)


int main() try {
	
	CLOCK_COUNT_START(); // counting

#define _APPLICATION_SETTINGS_
#ifdef _APPLICATION_SETTINGS_
						 // Application setttings
	eriter_extended::applicationSet();

#endif

	std::string FileName;
	int PwNumber;

#define PW_SIZE	9

	// Settings
	PRINT_SYSTEM_MSG("Set file name.");
	COUT << "> ";
	CIN >> FileName;

	// locals, user-defined
	// Main
	_jcode::CsvWriter Main_First_Writer(FileName);
	Main_First_Writer.setFileNameOption("MAIN_1");
	_jcode::Generator Main_First_Gen;

	_jcode::CsvWriter Main_Second_Writer(FileName);
	Main_Second_Writer.setFileNameOption("MAIN_2");
	_jcode::Generator Main_Second_Gen;

	// Sub
	_jcode::CsvWriter Sub_First_Writer(FileName);
	Sub_First_Writer.setFileNameOption("SUB_1");
	_jcode::Generator Sub_First_Gen;

	_jcode::CsvWriter Sub_Second_Writer(FileName);
	Sub_Second_Writer.setFileNameOption("SUB_2");
	_jcode::Generator Sub_Second_Gen;

	// Will used as iterator
	_jcode::CsvWriter* WriterArray[4] = {

		&Main_First_Writer,
		&Main_Second_Writer,
		&Sub_First_Writer,
		&Sub_Second_Writer
	};

	// Generator
	_jcode::Generator* Gen[4] = {

		&Main_First_Gen,
		&Main_Second_Gen,
		&Sub_First_Gen,
		&Sub_Second_Gen
	};

	// Settings
	PRINT_SYSTEM_MSG("Set numbers to of passwords to be generated.");
	COUT << "> ";
	CIN >> PwNumber;


	for (int itor = 0; itor < 4; itor++) {

		WriterArray[itor]->openFileToWrite();


		for (auto StringList : Gen[itor]->getGeneratedStringList(PW_SIZE, PwNumber)) {

			WriterArray[itor]->writeLine(StringList);
			//PRINT_LOG("Writing...");

		};

		Gen[itor]->clear();
		WriterArray[itor]->closeFile();
	}


	// _jcode::ConsoleOut::printLog(CLOCK_COUNT_END());
	PRINT_SYSTEM_MSG("Duration - " + std::to_string(CLOCK_COUNT_END() / 1000.0) + "s.");
	PAUSE();

	return 0;

} catch (...) {

	PRINT_ERROR_MSG("Unknown error. Shutting down the program.");
	PAUSE();
};

#endif
