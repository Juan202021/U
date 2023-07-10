#include <iostream>
#include <cmath>

class Triangulo{
    float firstSide, secondSide, thirdSide;
public:
    Triangulo() {
        firstSide = 0.0;
        secondSide = 0.0;
        thirdSide = 0.0;
    }
    Triangulo(float firstSide, float secondSide, float thirdSide){
        if (firstSide + secondSide > thirdSide && secondSide + thirdSide > firstSide &&
            thirdSide + firstSide > secondSide){
            this -> firstSide = firstSide;
            this -> secondSide = secondSide;
            this -> thirdSide = thirdSide;
        } else {
            this -> firstSide = 0.0;
            this -> secondSide = 0.0;
            this -> thirdSide = 0.0;
            std::cout<<"El objeto se construyo con "
                    <<"parametros por defecto, debido "
                    <<"a que no cumple con la "
                    <<"condicion"<<std::endl;
        }
    }

    float getFirstSide(){ return firstSide; }
    void setFirstSide(float firstSide) {
        this -> firstSide = firstSide;
    }

    float getSecondSide(){ return secondSide; }
    void setSecondSide(float secondSide) {
        this -> secondSide = secondSide;
    }

    float getThirdSide(){ return thirdSide; }
    void setThirdSide(float thirdSide) {
        this -> thirdSide = thirdSide;
    }

    float getPerimeter(){ return firstSide + secondSide
                                    + thirdSide; }
    float getArea(){
        float p, area;
        p = getPerimeter() / 2;
        area = p*(p-firstSide)*(p-secondSide)*(p-thirdSide);
        return sqrt(area);
    }
};

int main() {
    Triangulo t(5,3,1);
    return 0;
}
