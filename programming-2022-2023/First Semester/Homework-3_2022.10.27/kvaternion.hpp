#pragma once
#include <iostream>

class Kvaternion{
private:
    double re;
    double im_x;
    double im_y;
    double im_z;
public:
    Kvaternion(const Kvaternion& k);
    Kvaternion(double re=0, double im_x=0, double im_y=0, double im_z=0);
    ~Kvaternion();
    double getRe();
    double getIm_x();
    double getIm_y();
    double getIm_z();
    void setRe(double re);
    void setIm_x(double im_x);
    void setIm_y(double im_y);
    void setIm_z(double im_z);
    void set(double re, double im_x, double im_y, double im_z);
    double abs();
    Kvaternion conjugate();
    Kvaternion reverse();
    friend Kvaternion operator+(const Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator-(const Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator*(const Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator/(const Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator+=(Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator-=(Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator*=(Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator/=(Kvaternion& k1, const Kvaternion& k2);
    friend Kvaternion operator+(const Kvaternion& k1, double n);
    friend Kvaternion operator-(const Kvaternion& k1, double n);
    friend Kvaternion operator*(const Kvaternion& k1, double n);
    friend Kvaternion operator/(const Kvaternion& k1, double n);
    friend Kvaternion operator+=(Kvaternion& k1, double n);
    friend Kvaternion operator-=(Kvaternion& k1, double n);
    friend Kvaternion operator*=(Kvaternion& k1, double n);
    friend Kvaternion operator/=(Kvaternion& k1, double n);
    friend Kvaternion operator+(double n, const Kvaternion& k2);
    friend Kvaternion operator-(double n, const Kvaternion& k2);
    friend Kvaternion operator*(double n, const Kvaternion& k2);
    friend Kvaternion operator/(double n, const Kvaternion& k2);
    friend std::ostream& operator<<(std::ostream& stream, const Kvaternion& k);
};
