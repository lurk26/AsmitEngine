#include <windows.h>

#include <assert.h>
#include <limits.h>

#include "Timing.h"

namespace Engine
{
namespace Timing
{
	float LastFrame_s;

	LARGE_INTEGER PerformanceFrequency;

	bool Initialize()
	{
		if( !QueryPerformanceFrequency( & PerformanceFrequency ) )
			return false;
	
		return true;
	}

	tick GetCurrentTickCounter()
	{
		assert(PerformanceFrequency.QuadPart > 0);

		LARGE_INTEGER CurrentFrameCounter;

		BOOL success = QueryPerformanceCounter( &CurrentFrameCounter );
		assert( success == TRUE );

		return CurrentFrameCounter.QuadPart;
	}

	float GetTimeDiff_s(tick i_StartTime, tick i_EndTime)
	{
		assert(PerformanceFrequency.QuadPart > 0);

		return static_cast<float>(i_EndTime - i_StartTime) / PerformanceFrequency.QuadPart;
	}

    float GetLastFrameTime_s()
    {
        static tick lastTick;

        float frameTime = GetTimeDiff_s(lastTick);

        lastTick = GetCurrentTickCounter();

        return frameTime;
    }

    
} // Timing
} // Engine