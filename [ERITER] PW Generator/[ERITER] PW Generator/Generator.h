// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

#pragma once

#include <random>

#include <string>
#include <vector>

namespace _jcode {
	
	// Refactored
	class Generator {
	private:
		std::vector<std::string> GeneratedString;

	public:
		Generator() = default;
		virtual ~Generator() = default;

		const std::string getGeneratedString(const int&) noexcept;
		const std::vector<std::string> getGeneratedStringList(const int&, const int&) noexcept;

		void clear() noexcept;
		
	};
};