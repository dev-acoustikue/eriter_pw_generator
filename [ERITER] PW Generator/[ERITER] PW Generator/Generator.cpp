// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//


#include "ConsoleOut.h"
#include "Generator.h"

void _jcode::Generator::clear() noexcept {
	
	PRINT_NORMAL_MSG("Clearing list.");
	GeneratedString.clear();
};


// interface
const std::string _jcode::Generator::getGeneratedString(const int& argSize) noexcept {

	
	std::random_device Seed;

	std::default_random_engine Gen(Seed());
	std::uniform_int_distribution<> uniformDistribution(33, 126);

	char GeneratedCharacter;
	std::string AppendedString;

	for (auto itor = 0; itor < argSize; itor++) {
		
		GeneratedCharacter = uniformDistribution(Gen);

		while (GeneratedCharacter == 92 || GeneratedCharacter == 44 || GeneratedCharacter == 34)
			GeneratedCharacter = uniformDistribution(Gen);

		AppendedString.push_back(GeneratedCharacter);
	};

	GeneratedString.push_back(AppendedString);

	PRINT_NORMAL_MSG("Generating a string... \t" + AppendedString + " generated.");

	return AppendedString;
};


const std::vector<std::string> _jcode::Generator::getGeneratedStringList(const int& argSize, const int& argListSize) noexcept {

	for (auto itor = 0; itor < argListSize; itor++) 		
		getGeneratedString(argSize);
	
	return GeneratedString;
};