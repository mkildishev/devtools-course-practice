// Copyright 2017 Kildishev Maxim

#ifndef MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
#define MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_

//За унимодальную функцию примем y = afactor*(x+bfactor)^2 + cfactor
class Dichotomy{
 public:
    double findMin(int afactor, int bfactor, int cfactor,
        double leftBorder, double rightBorder, double eps);
};

#endif  // MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
