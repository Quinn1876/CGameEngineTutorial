#pragma once

#include "types.h"

typedef struct time_state {
    f32 delta;              /* <!-- Time between frames */
    f32 now;                /* <!-- Time of the current frame */
    f32 last;               /* <!-- Time of the last frame */

    f32 frame_last;         /* <!-- Last time the fps was calculated */
    f32 frame_delay;        /* <!-- Time maximum amount of time a frame should take */
    f32 frame_time;         /* <!-- How long the current frame took */

    u32 frame_rate;         /* <!-- Number of Frames per second that we are running at */
    u32 frame_count;        /* <!-- Helps us calculate the frame_rate */
} Time_State;


void time_init(u32 frame_rate);
void time_update(void);
void time_update_late(void);
