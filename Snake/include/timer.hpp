#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL3/SDL.h>


class Timer 
{
    private:
		Uint64 last_frame_tick{};
		Uint64 tick_delay{};

		int to_seconds{};
		double delta_time{};
		float fps{};

		Uint64( *GetTicks64 )() = nullptr;
		
    public:
		enum class Scale {
			Milli,
			Nano
		};
		Scale scale_type;

		Timer( Scale scale_type_ ) 
		{
			scale_type = scale_type_;
			switch ( scale_type )
			{
				case Scale::Milli:
					GetTicks64 = SDL_GetTicks;
					to_seconds = 1e4;
					break;
				
				case Scale::Nano:
					GetTicks64 = SDL_GetTicksNS;
					to_seconds = 1e9;
					break;
			}
		}

		void init( float refresh_rate );
		void calc_DeltaTime();
		void frameLimiter();
		double deltaTime();


		

};

#endif
