double square(double x, double value)
{
    return x*x-value;
}

double square_derivative(double x, double value)
{
    return 2*x;
}

double power3(double x, double value)
{
    return x*x*x-value;
}

double power3_derivative(double x, double value)
{
    return 3*x*x;
}

double solve(double fun(double, double), double fun_der(double, double), double x0, double param)
{
    double x = x0;
    double fx;
    double eps = 1e-12;

    do
    {
        fx = fun(x, param);
        double fpx = fun_der(x, param);
        x = x - fx / fpx;
    }
    while(fx>eps || fx<-eps);

    return x;
}

int main()
{
    double x = solve(power3, power3_derivative, 1.0, 8.0);
    return 0;
}