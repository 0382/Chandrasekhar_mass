/*
author:         0.382
date:           2018-05-06
description:    计算钱德拉塞卡极限质量
enviroment:     MinGW32, g++6.3.0
bibliography:   徐仁新《天体物理导论》（第一版）P142-P151（7.2-7.3）
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

//常数来自Google
const double Pi = 3.141592653589793;
const double me = 9.10938356e-31;
const double ma = 1.66053904e-27;
const double h = 6.62607004e-34;
const double c = 299792458.0;
const double G = 6.67408e-11;
const double mue = 2.0; //set mue = 2.0, 取决于星体的物质组成，你可以尝试改变
const double step = 100.0; //set step = 100.0m
const double lam = h/(2.0*Pi*me*c);
const double K = me*c*c/(lam*lam*lam);
const double K_x = lam * pow(3*Pi*Pi/(ma*mue), 1./3.);

/*用不上的phi(x)，后面会用到它的导数
double phi(double x){
    return (x*sqrt(1.0+x*x)*(2.0*x*x/3.0-1.0)+log(x+sqrt(1.0+x*x)))/(8.0*Pi*Pi);
}*/

//求当前计算到球的质量
double M_r(vector<double> rho_list){
    double m = 0, r = 0;
    for(int i=0; i<rho_list.size(); i++){
        r = (i+1)*step;
        m += 4*Pi*r*r * rho_list[i] * step;
    }
    return m;
}

//求drho/dr
double K_r(vector<double> rho_list){
    double r = rho_list.size()*step;
    double rho = rho_list[rho_list.size()-1];
    double x = K_x * ( rho > 0.? pow(rho, 1./3.) : -pow(-rho, 1./3.));
    double g_r = M_r(rho_list) * G /(r*r);
    return -9.*Pi*Pi*g_r*rho*rho*sqrt(1.+x*x)/(K*x*x*x*x*x);
}

//设置一个中心密度求质量和半径
double get_a_R(double rho_c){
    vector<double> rho_list;
    double rho = rho_c;
    rho_list.push_back(rho);
    while(rho > 0){
        double drho = K_r(rho_list) * step;
        rho += drho;
        rho_list.push_back(rho);
    }
    ofstream file("data.txt", ios::app);
    file << rho_list.size()*step << '\t' << M_r(rho_list) << endl;
    return rho_list.size()*step;
}

int main(){
    for(int i=0; i<100; i++){
        cout << get_a_R(pow(10.,double(i)/10.)*1e8) <<endl;
    }
    return 0;
}
