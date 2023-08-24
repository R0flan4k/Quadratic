/////////////////////////////////////////////////////////////////////////
/// file test.h
/////////////////////////////////////////////////////////////////////////
#ifndef TEST_H
    #define TEST_H

    #include "calculations.h"

/////////////////////////////////////////////////////////////////////////
/// \brief enumiration of all kind of test results
/////////////////////////////////////////////////////////////////////////
    enum test_results {
        TEST_CANT_OPEN_FILE,
        TEST_SUCCESS,
        TEST_COUNT_FAILURE,
        TEST_ROOTS_FAILURE
    };

/////////////////////////////////////////////////////////////////////////
/// \brief check the program's calculations
/// \param[in] test_file name of test file
/// \return results of test
/////////////////////////////////////////////////////////////////////////
    test_results test_program(const char * test_file);

#endif