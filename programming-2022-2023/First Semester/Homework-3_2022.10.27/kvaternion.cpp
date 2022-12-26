#include "kvaternion.hpp"
#include <cmath>

Kvaternion::Kvaternion(const Kvaternion& k){
    re = k.re;
    im_x = k.im_x;
    im_y = k.im_y;
    im_z = k.im_z;
}

Kvaternion::Kvaternion(double re, double im_x, double im_y, double im_z){
    this->re = re;
    this->im_x = im_x;
    this->im_y = im_y;
    this->im_z = im_z;
}

Kvaternion::~Kvaternion(){}

double Kvaternion::getRe(){
    return this->re;
}

double Kvaternion::getIm_x(){
    return this->im_x;
}

double Kvaternion::getIm_y(){
    return this->im_y;
}

double Kvaternion::getIm_z(){
    return this->im_z;
}

void Kvaternion::setRe(double re){
    this->re = re;
}

void Kvaternion::setIm_x(double im_x){
    this->im_x = im_x;
}

void Kvaternion::setIm_y(double im_y){
    this->im_y = im_y;
}

void Kvaternion::setIm_z(double im_z){
    this->im_z = im_z;
}

void Kvaternion::set(double re, double im_x, double im_y, double im_z){
    this->re = re;
    this->im_x = im_x;
    this->im_y = im_y;
    this->im_z = im_z;
}

double Kvaternion::abs(){
    return sqrt(re*re + im_x*im_x + im_y*im_y + im_z*im_z);
}

Kvaternion Kvaternion::conjugate(){
    return Kvaternion(re, -im_x, -im_y, -im_z);
}

Kvaternion Kvaternion::reverse(){
    Kvaternion a = (this->re, this->im_x, this->im_y, this->im_z);
    return Kvaternion(a.conjugate() / (a.abs() * a.abs()));
}

Kvaternion operator+(const Kvaternion& k1, const Kvaternion& k2){
    return Kvaternion(k1.re + k2.re, k1.im_x + k2.im_x, k1.im_y + k2.im_y, k1.im_z + k2.im_z);
}

Kvaternion operator-(const Kvaternion& k1, const Kvaternion& k2){
    return Kvaternion(k1.re - k2.re, k1.im_x - k2.im_x, k1.im_y - k2.im_y, k1.im_z - k2.im_z);
}

Kvaternion operator*(const Kvaternion& k1, const Kvaternion& k2){
    return (k1.re*k2.re - k1.im_x*k2.im_x - k1.im_y*k2.im_y - k1.im_z*k2.im_z,
             k1.re*k2.im_x + k1.im_x*k2.re + k1.im_y*k2.im_z - k1.im_z*k2.im_y,
             k1.re*k2.im_y + k1.im_y*k2.re + k1.im_z*k2.im_x - k1.im_x*k2.im_z,
             k1.re*k2.im_z + k1.im_z*k2.re + k1.im_x*k2.im_y - k1.im_y*k2.im_x);
}

Kvaternion operator/(const Kvaternion& k1, const Kvaternion& k2){
    Kvaternion k = k2;
    return k1 * k.reverse();
}

Kvaternion operator+=(Kvaternion& k1, const Kvaternion& k2){
    k1.re = k1.re + k2.re;
    k1.im_x = k1.im_x + k2.im_x;
    k1.im_y = k1.im_y + k2.im_y;
    k1.im_z = k1.im_z + k2.im_z;
    return k1;
}

Kvaternion operator-=(Kvaternion& k1, const Kvaternion& k2){
    k1.re = k1.re - k2.re;
    k1.im_x = k1.im_x - k2.im_x;
    k1.im_y = k1.im_y - k2.im_y;
    k1.im_z = k1.im_z - k2.im_z;
    return k1;
}

Kvaternion operator*=(Kvaternion& k1, const Kvaternion& k2){
    k1.re = k1.re*k2.re - k1.im_x*k2.im_x - k1.im_y*k2.im_y - k1.im_z*k2.im_z;
    k1.im_x = k1.re*k2.im_x + k1.im_x*k2.re + k1.im_y*k2.im_z - k1.im_z*k2.im_y;
    k1.im_y = k1.re*k2.im_y + k1.im_y*k2.re + k1.im_z*k2.im_x - k1.im_x*k2.im_z;
    k1.im_z = k1.re*k2.im_z + k1.im_z*k2.re + k1.im_x*k2.im_y - k1.im_y*k2.im_x;
    return k1;
}

Kvaternion operator/=(Kvaternion& k1, const Kvaternion& k2){
    Kvaternion k = k2;
    k1 = k1 * k.reverse();
    return k1;
}

Kvaternion operator+(const Kvaternion& k1, double n){
    return Kvaternion(k1.re + n, k1.im_x, k1.im_y, k1.im_z);
}

Kvaternion operator-(const Kvaternion& k1, double n){
    return Kvaternion(k1.re - n, k1.im_x, k1.im_y, k1.im_z);
}

Kvaternion operator*(const Kvaternion& k1, double n){
    return Kvaternion(k1.re * n, k1.im_x * n, k1.im_y * n, k1.im_z * n);
}

Kvaternion operator/(const Kvaternion& k1, double n){
    return Kvaternion(k1.re / n, k1.im_x / n, k1.im_y / n, k1.im_z / n);
}

Kvaternion operator+=(Kvaternion& k1, double n){
    k1.re = k1.re + n;
    return k1;
}

Kvaternion operator-=(Kvaternion& k1, double n){
    k1.re = k1.re - n;
    return k1;
}

Kvaternion operator*=(Kvaternion& k1, double n){
    k1.re = k1.re * n;
    k1.im_x = k1.im_x * n;
    k1.im_y = k1.im_y * n;
    k1.im_z = k1.im_z * n;
    return k1;
}

Kvaternion operator/=(Kvaternion& k1, double n){
    k1.re = k1.re / n;
    k1.im_x = k1.im_x / n;
    k1.im_y = k1.im_y / n;
    k1.im_z = k1.im_z / n;
    return k1;
}

Kvaternion operator+(double n, const Kvaternion& k2){
    return Kvaternion(k2.re + n, k2.im_x, k2.im_y, k2.im_z);
}

Kvaternion operator-(double n, const Kvaternion& k2){
    return Kvaternion(k2.re - n, k2.im_x, k2.im_y, k2.im_z);
}

Kvaternion operator*(double n, const Kvaternion& k2){
    return Kvaternion(k2.re * n, k2.im_x * n, k2.im_y * n, k2.im_z * n);
}

Kvaternion operator/(double n, const Kvaternion& k2){
    Kvaternion k = k2;
    return n * k.reverse();
}

std::ostream& operator<<(std::ostream& stream, const Kvaternion& k){
    stream << "(" << k.re << ", " << k.im_x << ", " << k.im_y << ", " << k.im_z <<")";
    return stream;
}










