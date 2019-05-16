// [eriter_extended] Password_Random_Generator
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2015, VS Platform Tool 15
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.23. updated.
//

#pragma once

#include <chrono> // Application ticker
#include <string>
// customized.


// Extra utils.
// namespace eriter {
namespace _jcode {

	// in namespace.
	namespace ch = std::chrono;

	class OpTimer final {
	private:
		static ch::steady_clock::time_point Timer_Start; // Starting line.
		static ch::steady_clock::time_point Timer_End; // Finishing line.

	public:
		static inline void operationCount() {
			
			Timer_Start = ch::steady_clock::now();
		};

		static inline const long long operationEnd() {
		
			Timer_End = ch::steady_clock::now();

			return ch::duration_cast<ch::milliseconds>(Timer_End - Timer_Start).count();
		};
	};

	// static
	ch::steady_clock::time_point OpTimer::Timer_Start;
	ch::steady_clock::time_point OpTimer::Timer_End;

};
// };

#define CLOCK_COUNT_START()	_jcode::OpTimer::operationCount()
#define CLOCK_COUNT_END()	_jcode::OpTimer::operationEnd()
