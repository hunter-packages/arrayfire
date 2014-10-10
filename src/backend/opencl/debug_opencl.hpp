#pragma once
#include <err_opencl.hpp>
#include <iostream>
#include <stdio.h>
#include <errorcodes.hpp>

// FIXME: Add a special flag for debug
// #ifndef NDEBUG
#if 1
#define CL_DEBUG_FINISH(Q) Q.finish()

#define SHOW_BUILD_INFO(PROG) do {                              \
    std::cout << PROG.getBuildInfo<CL_PROGRAM_BUILD_LOG>(       \
        PROG.getInfo<CL_PROGRAM_DEVICES>()[0]) << std::endl;    \
                                                                \
    std::cout << PROG.getBuildInfo<CL_PROGRAM_BUILD_OPTIONS>(   \
        PROG.getInfo<CL_PROGRAM_DEVICES>()[0]) << std::endl;    \
    } while(0)                                                  \

#else

#define CL_DEBUG_FINISH(Q)
#define SHOW_BUILD_INFO(PROG)

#endif
