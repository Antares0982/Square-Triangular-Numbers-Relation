# 三角数表示与平方数表示之间的代数关系
Describe the relations between N(a1, ..., ak; n) and t(a1, ..., ak; n+m)
定义N(a1, ..., ak;n)为n=a1\*x1^2+a2\*x2^2+...+ak\*xk^2的解(x1, ..., xk)的个数，其中a1, a2, ..., ak是正整数，x1, x2, ..., xk是任意整数。
类似地，定义t(a1, ..., ak;n)为n=a1\*x1\*(x1+1)/2+a2\*x2\*(x2+1)/2+...+ak\*xk*(xk+1)/2的解的个数。
本程序目的是研究它们之间的某些代数关系。
### Mathematica
输入一个数组a与一个数字n即可得到N(a1, ..., ak; n)以及t(a1, ..., ak; n)，程序简短效率较高，使用的是多项式理论。

### C++
目前版本算法是暴力计算。一般情况下需要考虑的是n模module余residueSquare和余residueTriangular的情形，所以程序设计时仅考虑了这一情形。后续可能会加入用多项式理论来计算的算法。
