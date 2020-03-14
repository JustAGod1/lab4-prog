//
// Created by justagod on 3/14/20.
//

#ifndef LAB4_PROG_PRIMITIVES_H
#define LAB4_PROG_PRIMITIVES_H

class IGeoFig {
public:
// Площадь.
    virtual double square() const = 0;
// Периметр.
    virtual double perimeter() const = 0;
};
// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
public:
    virtual void initFromDialog() = 0;
};

// Вектор
class Vector2D : public IDialogInitiable {
public:
    double x = 0, y = 0;

    Vector2D();

    void initFromDialog() override;
};

// Интерфейс "Физический объект".
class PhysObject {
public:
// Масса, кг.
    virtual double mass() const = 0;

// Координаты центра масс, м.
    virtual Vector2D position() const = 0;

// Сравнение по массе.
    virtual bool operator==(const PhysObject &ob) const = 0;

// Сравнение по массе.
    virtual bool operator<(const PhysObject &ob) const = 0;
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
// Отобразить на экране
// (выводить в текстовом виде параметры фигуры).
    virtual void draw() const = 0;
};



// Интерфейс "Класс"
class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char *classname() = 0;

// Размер занимаемой памяти.
    virtual unsigned int size() = 0;
};

class GeometricFigure : public PhysObject, public IPrintable, public IDialogInitiable, public BaseCObject, public IGeoFig {

protected:
    Vector2D pos {};
public:
    double mass() const override;

    Vector2D position() const override;

    bool operator==(const PhysObject &ob) const override;

    bool operator<(const PhysObject &ob) const override;


};

class Circle : public GeometricFigure {
private:
    float r = 0;
public:
    double square() const override;

    double perimeter() const override;

    void draw() const override;

    const char *classname() override;

    unsigned int size() override;

    void initFromDialog() override;
};

class EquilateralTriangle : public GeometricFigure {
private:
    float a = 0;

public:
    double square() const override;

    double perimeter() const override;

    void initFromDialog() override;

    void draw() const override;

    const char *classname() override;

    unsigned int size() override;
};


#endif //LAB4_PROG_PRIMITIVES_H
