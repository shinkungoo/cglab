/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Shape.h                                                         *
*  @brief    Shape class specification                                       *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-19                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_SHAPE_H
#define CGLAB_SHAPE_H
#include "standardLibrary.h"

struct RGB{
    GLfloat r, g, b;
    RGB(GLfloat _r, GLfloat _g, GLfloat _b){
        r = _r;
        g = _g;
        b = _b;
    }
};

struct RGBA : public RGB {
    GLfloat a;
    RGBA(GLfloat _r, GLfloat _g, GLfloat _b, GLfloat _a = 0.0)
    : RGB(_r, _g, _b)
    {
        a = _a;
    }

};

class Shape{
protected:
    string shapeType;
    string shapeName;
public:
    virtual ~Shape() = default;
    virtual void draw(const RGBA & c) const = 0;
    virtual void color(const RGBA & c) const = 0;
    virtual void info() const = 0;
    [[nodiscard]] virtual string type() const = 0;
    [[nodiscard]] virtual string name() const = 0;
};

class Point : public Shape{
public:
    int x, y, z;
    explicit Point(int tx = 0, int ty = 0, int tz = 0);
    Point(const Point & p);
    ~Point() override;
    Point(Point && p) noexcept;
    Point & operator=(const Point & p);
    void draw(const RGBA & c) const override;
    void color(const RGBA & c) const override;
    void info() const override;
    [[nodiscard]] string type() const override;
    [[nodiscard]] string name() const override;
};

//class Line : public Shape{
//private:
//    vector<Point> points;
//public:
//    Line(const Point & a, const Point & b);
//    Line(const Line & l);
//    Line(Line && l) noexcept;
//    Line & operator=(const Line & l);
//    void draw(const RGBA & c) const override;
//    void color(const RGBA & c) const override;
//};

//class LineDDA : public Line{
//private:
//    vector<Point> points;
//public:
//    LineDDA(const Point & a, const Point & b);
//    LineDDA(const LineDDA & l);
//    LineDDA(LineDDA && l) noexcept;
//    LineDDA & operator=(const LineDDA & l);
//    void draw(const RGBA & c) const override;
//    void color(const RGBA & c) const override;
//};
//
//class Polygon : public Shape {
//private:
//    vector<Point> points;
//public:
//    Polygon(const vector<Point> & p);
//    Polygon(const Polygon & g);
//    Polygon(Polygon && g) noexcept;
//    Polygon & operator=(const Polygon & l);
//    void draw(const RGBA & c) const override;
//    void color(const RGBA & c) const override;
//};
//
//class Ellipse : public Shape {
//private:
//    Point c;
//    double rx;
//    double ry;
//public:
//    Ellipse(const Point & a, double rx, double ry);
//    Ellipse(const Ellipse & e);
//    Ellipse(Ellipse && e) noexcept;
//    Ellipse & operator=(const Ellipse & e);
//    void draw(const RGBA & c) const override;
//    void color(const RGBA & c) const override;
//};
//
//class Circle : public Ellipse {
//public:
//    Circle(const Point & a, const Point & b);
//    Circle(const Circle & c);
//    Circle(Circle && c) noexcept;
//    Circle & operator=(const Circle & c);
//};


#endif //CGLAB_SHAPE_H
