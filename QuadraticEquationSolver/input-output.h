/////////////////////////////////////////////////////////////////////////
/// file input-output.h
/////////////////////////////////////////////////////////////////////////
#ifndef INPUT_OUTPUT_H
    #define INPUT_OUTPUT_H

    #include "languages.h"
    #include "calculations.h"
/////////////////////////////////////////////////////////////////////////
/// \brief constatnts for cmd input result return
/////////////////////////////////////////////////////////////////////////
    const int WRONG_CMD_INPUT = 1;
    const int RIGHT_CMD_INPUT = 0;
    const int TRIVIAL_CMD_INPUT = 2;
    
/////////////////////////////////////////////////////////////////////////
/// \brief constants for get_one_char() return
/////////////////////////////////////////////////////////////////////////
    const int EXTRA_CHARACTERS = -2;
    const int WRONG_CHARACTER = -3;

/////////////////////////////////////////////////////////////////////////
/// \brief user greeting and telling program abillity
/// \param[in] language language that program using
/////////////////////////////////////////////////////////////////////////    
    void show_menu(const OutputLanguage * language);

/////////////////////////////////////////////////////////////////////////
/// \brief show user available languages
/////////////////////////////////////////////////////////////////////////
    void show_language_menu(void);
    
/////////////////////////////////////////////////////////////////////////
/// \brief show user format of equation
/////////////////////////////////////////////////////////////////////////
    void show_equation_format(void);

/////////////////////////////////////////////////////////////////////////
/// \brief show user equation that he input
/// \param coeffs inputed coefficients of equation
/// \param language language that program using
/////////////////////////////////////////////////////////////////////////
    void show_equation(const EquationCoefficients * coeffs, const OutputLanguage * language);

/////////////////////////////////////////////////////////////////////////
/// \brief show  user solution of inputed equatiin
/// \param[in] solution solution of inputed equation
/// \param[in] language language that program using
/////////////////////////////////////////////////////////////////////////
    void show_solution(const EquationRoots * solution, const OutputLanguage * language);

/////////////////////////////////////////////////////////////////////////
/// \brief say goodebye to user
/// \param[in] language language that program using
/////////////////////////////////////////////////////////////////////////
    void show_goodbye(const OutputLanguage * language);
    

/////////////////////////////////////////////////////////////////////////
/// \brief let user input coefficients of equation and check if input valid  
/// \param[in] language language that program using
/// \return coefficients of equation that user inputed
/////////////////////////////////////////////////////////////////////////
    EquationCoefficients get_coefficients(const OutputLanguage * language);

/////////////////////////////////////////////////////////////////////////
/// \brief get from stdin first non-space allowed character, and then skip anything after the character
/// \param[in] str list of allowed characters
/// \param[in] n number of allowed characters
/// \return is character alone or is it wrong character
/////////////////////////////////////////////////////////////////////////
    int get_one_char(const char * str, int n);

/////////////////////////////////////////////////////////////////////////
/// \brief check if user enter flags running the program
/// \param[in] argc number of words inputed in cmd
/// \param[in] argv array of words that inputed
/// \return is cmd inputs was right or is it there
/////////////////////////////////////////////////////////////////////////
    int check_cmd_input(int argc, char ** argv);


#endif