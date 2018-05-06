# Chandrasekhar_mass
计算钱德拉塞卡极限质量

参考自徐仁新《天体物理导论》（第一版）P142-P151（7.2-7.3）

考虑费米子星的零温近似，考虑一般相对论效应，费米子气体的压强与密度的关系为：

![](http://latex.codecogs.com/gif.latex?P=\frac{mc^2}{\lambda_e^3}\phi(x))

![](http://latex.codecogs.com/gif.latex?\phi(x)=(8\pi^2)^{-1}(x(1+x^2)^{1/2}(2x^2/3-1)+ln[x+(1+x^2)^{1/2}]))

![](http://latex.codecogs.com/gif.latex?n=\frac{\rho}{m_a\mu_e}=\frac{x^3}{3\pi^2\lambda_e^3})

具体的推导和参数解释参见《天体物理导论》，程序中，为简化计算，令：

![](http://latex.codecogs.com/gif.latex?P=K\phi(K_x\rho^{1/3}))

另一方面，星体内部压强和温度的关系为：

![](http://latex.codecogs.com/gif.latex?\frac{dP}{dr}=\frac{dP}{d\rho}\frac{d\rho}{dr}=-g\rho(r))

![](http://latex.codecogs.com/gif.latex?g(r)=\frac{G}{r^2}\int_0^r{4{\pi}r'^2\rho(r')dr'})

消去P，得到只有![](http://latex.codecogs.com/gif.latex?\rho)和r的方程：

![](http://latex.codecogs.com/gif.latex?\frac{d\rho}{dr}=-\frac{9\pi^2g\rho^2\sqrt{1+x^2}}{Kx^5})

程序就是要解这个方程，基本思路是，任取一个星体中心的密度，从中心开始积分，直到某处密度小于零，这里就是星体的表面，此时记录下星体的质量和半径，进行一系列这样的计算，就可以得到白矮星的质量和半径的关系，计算数据见data.txt，下图为Mathematica画的结果图。

![result.jpg](https://github.com/0382/Chandrasekhar_mass/blob/master/result.jpg?raw=true)

计算结果中的最大质量为![](http://latex.codecogs.com/gif.latex?2.88511\times10^{30})kg，约合1.45个太阳质量。
