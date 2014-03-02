#include "frame_timer.h"

static float g_avg_time = 0.0001f;
static float g_last_five[5] = { 0.0001f, 0.0001f, 0.0001f, 0.0001f, 0.0001f };
static unsigned char g_idx = 0;

/* limit the max frame time update to 4 frames per second */
#define MAX_TIME_DELTA 0.25f

#include <sys/time.h> /* Linux system clock functions */
#include <time.h>


double g_startframe = 0.0, g_endframe = 0.0;

double current_time() /* request frame time from Linux */
{
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv, &tz);
	return (double)tv.tv_sec + (double)tv.tv_usec/(1000*1000);
}

void  init_frametimer() {
	g_startframe = current_time();
}

void  sort_frame_timer()
{
	++g_idx;
	g_idx %= 0x05;

	do
	{
		g_endframe= current_time();
	}
	while(g_endframe == g_startframe);

	{
		float f = g_endframe - g_startframe;
		if(f > MAX_TIME_DELTA) {
			f = MAX_TIME_DELTA;
		}
		g_last_five[g_idx] = f;
	}
	g_startframe  =  g_endframe ;

	{
		float *p = g_last_five;
		float *e = p + 5;

		g_avg_time = 0.0f;

		for( ; p != e; ++p )
		{
			g_avg_time += *p;
		}

		g_avg_time *= 0.2f;
	}
}

float frame_time()
{
	return g_avg_time;
}

