#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <float.h>
#include <windows.h>
#include "QuadraticEquation.h"

BOOL setcolor(WORD color)
{
   static HANDLE handle = NULL;
 
   if (handle == NULL)
   {
      handle = GetStdHandle(STD_OUTPUT_HANDLE);
   }
 
   return SetConsoleTextAttribute(handle, color);
}


void show_equation_format(void)
{
    setcolor(10);
    puts("ax^2 + bx + c = 0.");
    setcolor(15);
}


void show_menu(const char language)
{
    switch(language)
    {
        case 'e':
        puts("Hello, Ruslan Alekseyevich.");
        puts("This program can solve quadratic equation.");
        printf("Equation must looks like: ");
        show_equation_format();
        break;

        case 'r':
        puts("Здравствуйте, Руслан Алексеевич.");
        puts("Эта программа преднозначена для решения квадратных уравнений.");
        printf("Уравнение должно выглядеть следующим образом: ");
        show_equation_format();
        break;

        case 'g':
        puts("Hallo, Ruslan Alekseevich.");
        puts("Dieses Programm dient zur Lösung quadratischer Gleichungen.");
        printf("Die Gleichung sollte so aussehen: ");
        show_equation_format();
        break;

        case 'c':
        puts("你好，鲁斯兰·阿列克谢耶维奇。");
        puts("该程序旨在求解二次方程。");
        printf("等式应如下所示： ");
        show_equation_format();
        break;

        default:
        puts("LANGUAGE ERROR");
        break;
    }
}


EquationCoefficients get_coefficients(const char language)
{
    EquationCoefficients coefficients = {0.0, 0.0, 0.0};
    
    switch(language)
    {
        case 'e':
        puts("Enter coeficients a, b, c:");
        while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
        {
            puts("Error. Enter 3 real numbers");
            puts("like 12, -1.5, 3.14 or 1.618.");
            scanf("%*s");
        }
        break;

        case 'r':
        puts ("Введите коэффициенты a, b и c:");
        while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
        {
            puts("Ошибка. Введите 3 вещественных числа");
            puts("таких как 12, -1.5, 3.14 или 1.618.");
            scanf("%*s");
        }
        break;

        case 'g':
        puts ("Geben Sie die Quoten ein a, b, c:");
        while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
        {
            puts("Fehler. Geben Sie 3 reelle Zahlen ein");
            puts("Zum Beispiel 12, -1.5, 3.14, 1.618.");
            scanf("%*s");
        }
        break;

        case 'c':
        puts ("输入赔率 a, b, c:");
        while (scanf("%f%f%f", &coefficients.a, &coefficients.b, &coefficients.c) != 3)
        {
            puts("错误。输入三个实数");
            puts("例如 12, -1.5, 3.14, 1.618.");
            scanf("%*s");
        }
        break;

        default:
        puts("LANGUAGE ERROR");
        break;
    }
    return coefficients;
}


EquationRoots solve_equation(const EquationCoefficients * coeffs)
{
    EquationRoots solution = {0, 0.0, 0.0};
    float discriminant = calculate_discriminant(coeffs);

    if (check_equality_float(coeffs->a, 0.0))
    {
        if (check_equality_float(coeffs->b, 0.0))
        {
            if (check_equality_float(coeffs->c, 0.0))
            solution.count = -1;
            else 
            solution.count = 0;
        }    
        else 
        {
            solution.count = 1;
            solution.first_root = - (coeffs->c / coeffs->b);
        }       
    }
    else if (discriminant < 0)
    {
        solution.count = 0;
    }
    else if (abs(discriminant) < FLT_EPSILON)
    {
        solution.count = 1;
        solution.first_root = calculate_root1(coeffs, discriminant);
    }
    else 
    {
        solution.count = 2;
        solution.first_root = calculate_root1(coeffs, discriminant);
        solution.second_root = calculate_root2(coeffs, discriminant);
    }
    return solution;
}


void show_user_equation(const EquationCoefficients * coeffs)
{
    setcolor(10);
    printf("%.3g*x^2 + %.3g*x + %.3g = 0.\n", coeffs->a, coeffs->b, coeffs->c);
    setcolor(15);
}


void show_equation(const EquationCoefficients * coeffs, const char language)
{
    switch (language)
    {
        case 'e':
        printf("Your equation: ");
        show_user_equation(coeffs);
        break;

        case 'r':
        printf("Ваше уравнение: ");
        show_user_equation(coeffs);
        break;

        case 'g':
        printf("Hier ist deine Gleichung: ");
        show_user_equation(coeffs);
        break;

        case 'c':
        printf("这是你的等式： ");
        show_user_equation(coeffs);
        break;

        default:
        puts("LANGUAGE ERROR");
        break;
    }
}


void show_one_root(const float root)
{
    setcolor(14);
    printf("%5.5g\n", root);
    setcolor(15);
}


void show_solution(const EquationRoots * solution, const char language)
{
    switch (language)
    {
        case 'e':
        if (solution->count == -1)
        {
            puts("This equation has infinite number of roots.");
        }
        else if (solution->count == 0)
        {
            puts("This equation hasn't roots.");
        }
        else if (solution->count == 1)
        {
            puts("This equation has one root.");
            printf("This root: ");
            show_one_root(solution->first_root);
        }
        else
        {
            puts("This equation has two roots.");
            printf("First root: ");
            show_one_root(solution->first_root);
            printf("Second root: ");
            show_one_root(solution->second_root);
        }
        break;

        case 'r':
        if (solution->count == -1)
        {
            puts("Это уравнение имеет бесконечное количество корней.");
        }
        else if (solution->count == 0)
        {
            puts("Это уравнение не имеет корней.");
        }
        else if (solution->count == 1)
        {
            puts("Это уравнение имеет всего один корень.");
            printf("Этот корень: ");
            show_one_root(solution->first_root);
        }
        else
        {
            puts("Это уравнение имеет два корня.");
            printf("Первый корень: ");
            show_one_root(solution->first_root);
            printf("Второй корень: ");
            show_one_root(solution->second_root);
        }
        break;

        case 'g':
        if (solution->count == -1)
        {
            puts("Diese Gleichung hat unendlich viele Wurzeln.");
        }
        else if (solution->count == 0)
        {
            puts("Diese Gleichung hat keine Wurzeln.");
        }
        else if (solution->count == 1)
        {
            puts("Diese Gleichung hat nur eine Wurzel.");
            printf("das ist die Wurzel: ");
            show_one_root(solution->first_root);
        }
        else
        {
            puts("Diese Gleichung hat zwei Wurzeln.");
            printf("erste Wurzel: ");
            show_one_root(solution->first_root);
            printf("zweite Wurzel: ");
            show_one_root(solution->second_root);
        }
        break;

        case 'c':
        if (solution->count == -1)
        {
            puts("这个方程有无数个根。");
        }
        else if (solution->count == 0)
        {
            puts("该方程没有实根。");
        }
        else if (solution->count == 1)
        {
            puts("这个方程只有一个根。");
            printf("这是根 ");
            show_one_root(solution->first_root);
        }
        else
        {
            puts("这个方程有两个根。");
            printf("第一个根：  ");
            show_one_root(solution->first_root);
            printf("第二根： ");
            show_one_root(solution->second_root);
        }
        break;

        default:
        puts("LANGUAGE ERROR");
        break;
    }
}


float calculate_discriminant(const EquationCoefficients * coefficients)
{
    return coefficients->b * coefficients->b - 4 * (coefficients->a) * (coefficients->c);
}


float calculate_root1(const EquationCoefficients * coefficients, const float discriminant)
{
    return (-coefficients->b - sqrtf( discriminant ) ) / ( 2 * coefficients->a );
}


float calculate_root2(const EquationCoefficients * coefficients, const float discriminant)
{
    return (-coefficients->b + sqrtf( discriminant ) ) / ( 2 * coefficients->a );
}


char get_language(void)
{
    int ch = 0;
    puts("Enter language:");
    puts("\"R\" - Russian,      \"E\" - English,");
    puts("\"G\" - Germany,      \"C\" - Chinese.");

    do
    {
        ch = getchar();
        ch = tolower(ch);
        while (getchar() != '\n') 
        continue;
        if (ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c')
        puts("Error. Enter language again (\"R\", \"E\", \"G\" or \"C\".)");
    } while (ch != 'r' && ch != 'e' && ch != 'g' && ch != 'c');

    return (char) ch;
}


void show_goodbye(const char language)
{
    switch (language)
    {
        case 'e':
        puts("Have a good day! End.");
        break;

        case 'r':
        puts("Всего доброго! Конец.");
        break;

        case 'g':
        puts("Auf Wiedersehen! Ende.");
        break;

        case 'c':
        puts("再见！结尾。");
        break;

        default:
        puts("LANGUAGE ERROR");
        break;
    }
}


int check_equality_float(const float num1, const float num2)
{
    if (abs(num1 - num2) < FLT_EPSILON)
    return 1;
    else
    return 0;
}