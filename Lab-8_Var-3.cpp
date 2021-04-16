/* Напишите программу, которая создает абстрактный класс, а затем использует этот класс в процессе наследования и полностью ее реализовывает. Приведите также пример полиморфизма.

3)	Длина Геометрических Фигур (длина, ширина, абстрактный метод длина()) и производные классы Длина Прямоугольника и Длина Равнобедренного Треугольника. */

#include <iostream>

class Figure
{
public:
    virtual double length;
    virtual double width;
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void showFigureType() = 0;
};

class Rectangle : public Figure
{
private:
        double width;
        double height;

public:
        Rectangle(double w, double h) : width(w), height(h)
    
    {
            
    }
        double getArea() override
    
    {
                return width * height;
            
    }
        double getPerimeter() override
    
    {
                return (2 * (width * height));
            
    }
        void showFigureType()
    
    {
                std::cout << "Rectangle" << std::endl;
            
    }
};

class Triangle : public Figure
{
private:
        double side;

public:
        Triangle(double r) : side(r)
    
    {
            
    }
        double getArea() override
    
    {
                return side * (sqrt(side ^ 2) - ((0.5 * side) ^ 2));
            
    }
        double getPerimeter() override
    
    {
                return 3 * side;
            
    }
        void showFigureType()
    
    {
                std::cout << "Triangle" << std::endl;
            
    }
};
  int main()
{
        Rectangle rect(30, 50);
        Triangle triang(30);
         
    std::cout << "Rectangle lenght: " << rect.getPerimeter() << std::endl;
        std::cout << "Triangle length: " << triang.getPerimeter() << std::endl;
     
    return 0;
}