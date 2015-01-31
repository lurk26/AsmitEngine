#ifndef __TIMING_H
#define __TIMING_H

#include <stdint.h>

namespace Engine
{
namespace Timing
{
	typedef uint64_t	tick;
	
	bool Initialize();
	
	tick GetCurrentTickCounter();
	float GetTimeDiff_s(tick i_StartTime, tick i_EndTime = GetCurrentTickCounter());
    float GetLastFrameTime_s();

	inline float CvtSecondsToMilliseconds( float i_Seconds );
	inline float CvtPerSecondToPerMillisecond( float i_PerSecond );
	
}
} // namespace Engine

#include "Timing.inl"

#endif // __TIMING_H