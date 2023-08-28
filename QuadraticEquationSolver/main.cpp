/////////////////////////////////////////////////////////////////////////
/// \file main.cpp
/// \brief File with main().
/////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string.h>

#include "input-output.h"
#include "calculations.h"
#include "test.h"
#include "my_assert.h"
#include "languages.h"


int main(int argc, char * argv[])
{
    EquationRoots solution = {ROOTS_COUNT_ZERO, 0.0, 0.0};
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};

    const OutputLanguage * language = &LANGUAGE_ENGLISH;
    
    int cmd_input_status = RIGHT_CMD_INPUT;
    if ((cmd_input_status = check_cmd_input(argc, argv)) == WRONG_CMD_INPUT ||
         cmd_input_status == PREMATURE_CMD_INPUT)
    {
        return 0;
    }

    show_language_menu();

    int character = 0;
    while ((character = get_one_char("regc", strlen("regc")))
            == WRONG_CHARACTER || character == EXTRA_CHARACTERS)
    {
        puts("Error. Enter language again (\"E\", \"R\", \"G\" or \"C\")");
    }
    language = select_language(character);

    show_menu(language);
    show_request(language); 

    bool coefficients_input_status = true;
    while (!(coefficients_input_status = is_valid_coefficients_input(&coefficients)) || !isspace_extra_characters())
    {
        if (!coefficients_input_status)
        {
            show_error(language);
            skip_input();
        }
        else
        {
            show_error(language);
        }
    }
    solution = solve_equation(&coefficients);
    show_equation(&coefficients, language);
    show_solution(&solution, language);
    show_goodbye(language);

    return 0;
}
 