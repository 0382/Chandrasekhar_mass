/*
author:         0.382
description:    计算钱德拉塞卡极限质量
enviroment:     MinGW-w64, g++8.1.0
reference:      徐仁新《天体物理导论》（第一版）P142-P151（7.2-7.3）
*/
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//常数来自Google
constexpr double pi = 3.141592653589793;
constexpr double me = 9.10938356e-31;
constexpr double ma = 1.66053904e-27;
constexpr double h = 6.62607004e-34;
constexpr double c = 299792458.0;
constexpr double G = 6.67408e-11;
constexpr double mue = 2.0; //设 mue = 2.0, 取决于星体的物质组成
constexpr double lambda = h / (2. * pi * me * c);
constexpr double lambda_3 = lambda * lambda * lambda;
constexpr double K_1 = me * c * c / lambda_3;
constexpr double K_2 = ma * mue / (3. * pi * pi * lambda_3);
constexpr double K = 9. * pi * pi * K_2 * K_2 * G / K_1;

constexpr double dr = 100.0; // dr 为每次积分的长度

struct MR
{
    double m;
    double r;
};

MR calculate_one_rho(double rho_center){
    double m_prev;
    double rho_prev;
    double m = 0.;
    double r = 0.;
    double rho = rho_center;
    double x;
    double drho;
    while(rho > 0.)
    {
        m_prev = m;
        rho_prev = rho;
        x = pow(rho / K_2, 1./3.);
        r += dr;
        m = m_prev + 4. * pi * r * r * rho * dr;
        drho = -K * x * sqrt(1.+x*x) * m / (r * r) * dr;
        rho = rho_prev + drho;
    }
    return MR{m, r};
}

int main(int argc, char const *argv[])
{
    MR result[100];
    for(int i=0; i<100; ++i)
    {
        result[i] = calculate_one_rho(exp(i/4.) * 1e8);
    }

    ofstream ofs("data.txt");
    for(int i=0; i<100; ++i)
    {
        ofs << result[i].m << ',' << result[i].r << '\n';
    }
    ofs.close();
    return 0;
}
