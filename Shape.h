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
#include "import.h"


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
public:
    virtual void draw(const RGBA & c) const = 0;
    virtual void color(const RGBA & c) const = 0;
};

class Point : public Shape{
public:
    int x, y, z;
    Point(int x = 0, int y = 0, int z = 0);
    Point(const Point & p);
    Point(Point && p) noexcept;
    Point & operator=(const Point & p);
    void draw(const RGBA & c) const override;
};

class Line : public Shape{
private:
    vector<Point> points;
public:
    Line(const Point & a, const Point & b);
    Line(const Line & l);
    Line(Line && l) noexcept;
    Line & operator=(const Line & l);
    void draw(const RGBA & c) const override;
};

class LineDDA : public Line{
private:
    vector<Point> points;
public:
    LineDDA(const Point & a, const Point & b);
    LineDDA(const LineDDA & l);
    LineDDA(LineDDA && l) noexcept;
    LineDDA & operator=(const LineDDA & l);
    void draw(const RGBA & c) const override;
};


#endif //CGLAB_SHAPE_H
