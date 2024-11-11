#ifndef BASE_PROFILER_H
#define BASE_PROFILER_H

#if defined(BUILD_SPALL)
#include "spall.h"

global SpallProfile spall_ctx;
global SpallBuffer spall_buffer;

// Spall Profiling Backend Macros
#define ProfBeginCapture() spall_buffer_init(&spall_ctx, &spall_buffer)
#define ProfEndCapture() spall_buffer_quit(&spall_ctx, &spall_buffer)
#define ProfilerQuit() spall_quit(&spall_ctx);

#if defined(DWT)
#define ProfBegin(NAME) const char *prof_name = NAME; U32 start_cycle = DWT->CYCCNT;
#define ProfEnd() U32 end_cycle = DWT->CYCCNT; \
spall__buffer_profile(&spall_ctx, &spall_buffer, start_cycle, end_cycle, prof_name, strlen(prof_name));
#endif

#else // BACKEND not defined
// No-op Definitions When Spall Profiling is Disabled
#define ProfBeginCapture()
#define ProfEndCapture()
#define ProfBegin(...) (0)
#define ProfEnd()
#define ProfilerQuit()
#endif

#endif // BASE_PROFILER_H
