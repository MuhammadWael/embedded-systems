#include <stdio.h>

typedef struct Complex
{
    double real;
    double imaginary;
}Complex_t;

Complex_t get_complex(void);
Complex_t add_complex(Complex_t c1,Complex_t c2);

int main()
{
    Complex_t num1,num2,result;
    printf("Enter the real & imaginary part Respicativly for first number\n");
    num1 = get_complex();
    printf("Enter the real & imaginary part Respicativly for second number\n");
    num2 = get_complex();
    result = add_complex(num1,num2);
    printf("Sum = %.2lf + %.2lfi ",result.real,result.imaginary);
    return 0;
}
Complex_t add_complex(Complex_t c1,Complex_t c2)
{
    Complex_t result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;

    return result;
}

Complex_t get_complex(void)
{
    Complex_t c;
    scanf("%lf %lf",&c.real,&c.imaginary);
    return c;
}
