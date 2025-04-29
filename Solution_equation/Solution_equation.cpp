#include <iostream>
#include <conio.h>
#include <math.h>


double* solution(const double* A)
{
    static double x[2];
    double D;
    D = A[1] * A[1] - 4 * A[0] * A[2];

    if (D < 0)
    {
        return NULL;
    }
    D = sqrt(D);
    x[0] = (-A[1] - D) / (2 * A[0]);
    x[1] = (-A[1] + D) / (2 * A[0]);

    return x;
}

void enter_coeff(double* coef)
{
    std::cout << "Enter coefficients using enter.\n";
    for (int i = 0; i < 3;)
    {
        std::cin >> coef[i];
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << "Incorrect data. Please try again.\n";
        }
        else
        {
            i++;
        }
        
    }
   
}

int menu()
{ 
    int ch;
    std::cout << "Press E to continue.\n";
    std::cout << "Press ESC to end.\n";
    for (;;)
    {
        ch = _getch();
        ch = toupper(ch);
        switch (ch)
        {
        case 27:
            return 0;
        case 69:
            return 1;
        default:
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    double coef[3];
    double* x;
    if ( (argc != 4)&&(argc !=1))
    {
        std::cerr << "Error 1:Incorrect number of coefficients.\n";
        return 1;

    }
    if (argc == 4)
    {
        bool res = 1;
        for (int i = 0; i < 3; i++)
        {
            if (sscanf_s(argv[i+1], "%lf", &coef[i]) != 1)
            {
                std::cerr << "Error 2:Incorrect type of data.\n";
                res = 0;
            }

        }
        if (res != 0)
        {
            x = solution(coef);
            if (x == NULL)
            {
                std::cerr << "Error 3:Don't have real roots.\n";
            }
            else
            {
                std::cout << "Coefficients:\n";
                for (int i = 0; i < 3; i++)
                {
                    std::cout << coef[i] << "\t";
                }
                std::cout << "\n";
                std::cout << "Roots:\n";
                for (int i = 0; i < 2; i++)
                {
                    std::cout << x[i] << "\t";
                }
                std::cout << "\n";
            }
        }
        
        
    }
    
    for (;;)
    {
        if (menu()!=1)
        {
            return 0;
        }
        else
        {
            enter_coeff(coef);
            x = solution(coef);
            if (x == NULL)
            {
                std::cerr << "Error 3:Don't have real roots.\n";
            }
            else
            {
                std::cout << "Coefficients:\n";
                for (int i = 0; i < 3; i++)
                {
                    std::cout << coef[i] << "\t";
                }
                std::cout << "\n";
                std::cout << "Roots:\n";
                for (int i = 0; i < 2; i++)
                {
                    std::cout << x[i] << "\t";
                }
                std::cout << "\n";
            }
        }
    }
    

    return 0;
   
}

