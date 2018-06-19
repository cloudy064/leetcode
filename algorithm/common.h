#ifndef COMMON_H
#define COMMON_H

#include "gtest/gtest.h"

#ifdef WIN32

#define GTEST_MAIN

#else

#define GTEST_MAIN 	\
	int main(int argc, char *argv[]) {\
        testing::InitGoogleTest(&argc, argv);\
        return RUN_ALL_TESTS();\
	}

#endif

#endif //COMMON_H