/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Shape.cpp                                                       *
*  @brief    Shape class implementation                                      *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-10-19                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

#include "utilities.h"
#include "Global.h"
#include "Buffer.h"
#include "Shape.h"

// TODO Complete all implementation of class

/*
 * Implementation of Point class
 */
Point::Point(int tx, int ty, int tz) {
    x = tx, y = ty, z = tz;
    shapeType = "point";
    shapeName = "shape" + to_string(Buffer::getInstance().shapeBuffer.size());
}

Point::~Point() = default;
Point::Point(const Point &p) = default;
Point::Point(Point &&p) noexcept = default;

Point
&Point::operator=(const Point &p) = default;

void
Point::draw(const RGBA &c) const {
    setPixel(x, y, z, c);
}

void
Point::color(const RGBA &c) const {
    setPixel(x, y, z, c);
}

void
Point::info() const {
    cout << "Shape name: " << shapeName << "; Shape type: " << shapeType << "; Pos: (" << x << ", " << y << ", " << z << ")" << endl;
}

string
Point::type() const {
    return shapeType;
}

string
Point::name() const {
    return shapeName;
}

/*
 * Implementation of Line class
 */

Line::Line(const Point &a, const Point &b) {
    points.push_back(a);
    points.push_back(b);
    shapeType = "line";
    shapeName = "shape" + to_string(Buffer::getInstance().shapeBuffer.size());
}

Line::~Line() = default;
Line::Line(const Line &l) = default;
Line::Line(Line &&l) noexcept = default;

Line&
Line::operator=(const Line &l) = default;

void
Line::draw(const RGBA & c) const {
    glLineWidth(Global::getInstance().size);
    glColor4f(c.r, c.g, c.b, c.a);
    glBegin(GL_LINES);
    glVertex2i(points[0].x, points[0].y);
    glVertex2i(points[1].x, points[1].y);
    glEnd();
    glFlush();
}

void
Line::color(const RGBA & c) const {
    glLineWidth(Global::getInstance().size);
    glColor4f(c.r, c.g, c.b, c.a);
    glBegin(GL_LINES);
    glVertex2i(points[0].x, points[0].y);
    glVertex2i(points[1].x, points[1].y);
    glEnd();
    glFlush();
}

void
Line::info() const {
    cout << "Shape name: " << shapeName << "; Shape type: " << shapeType << endl;
    cout << "From (" << points[0].x << ", " << points[0].y << ") to (" << points[1].x << ", " << points[1].y << ")" << endl;
}

string
Line::type() const {
    return shapeType;
}

string
Line::name() const {
    return shapeName;
}

/*
 * Implementation of LineDDA class
 */
LineDDA::LineDDA(const Point &a, const Point &b) {
    points.push_back(a);
    points.push_back(b);
    shapeType = "lineDDA";
    shapeName = "shape" + to_string(Buffer::getInstance().shapeBuffer.size());
}

LineDDA::~LineDDA() = default;
LineDDA::LineDDA(const LineDDA &l) = default;
LineDDA::LineDDA(LineDDA &&l) noexcept = default;

LineDDA &
LineDDA::operator=(const LineDDA &l) = default;

void
LineDDA::draw(const RGBA & c) const {
    int x0 = points[0].x,  y0 = points[0].y, xEnd = points[1].x, yEnd = points[1].y;
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if (fabs (dx) > fabs (dy)){
        steps = fabs (dx);
    }else{
        steps = fabs (dy);
    }
    xIncrement = float (dx) / float (steps);
    yIncrement = float (dy) / float (steps);
    setPixel (round (x), round (y), 0, c);
    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel (round (x), round (y), 0, c);
    }
}

void
LineDDA::color(const RGBA & c) const {
    int x0 = points[0].x,  y0 = points[0].y, xEnd = points[1].x, yEnd = points[1].y;
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if (fabs (dx) > fabs (dy)){
        steps = fabs (dx);
    }else{
        steps = fabs (dy);
    }
    xIncrement = float (dx) / float (steps);
    yIncrement = float (dy) / float (steps);
    setPixel (round (x), round (y), 0, c);
    for (k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel (round (x), round (y), 0, c);
    }
}

void
LineDDA::info() const {
    cout << "Shape name: " << shapeName << "; Shape type: " << shapeType << endl;
    cout << "From (" << points[0].x << ", " << points[0].y << ") to (" << points[1].x << ", " << points[1].y << ")" << endl;
}

string
LineDDA::type() const {
    return shapeType;
}

string
LineDDA::name() const {
    return shapeName;
}

/*
 * Implementation of LineBres class
 */
LineBres::LineBres(const Point &a, const Point &b) {
    points.push_back(a);
    points.push_back(b);
    shapeType = "lineBres";
    shapeName = "shape" + to_string(Buffer::getInstance().shapeBuffer.size());
}

LineBres::~LineBres() = default;
LineBres::LineBres(const LineBres &l) = default;
LineBres::LineBres(LineBres &&l) noexcept = default;

LineBres&
LineBres::operator=(const LineBres &l) = default;

void
LineBres::drawForSmall(int x0, int y0, int xEnd, int yEnd, const RGBA & c) const {
    int dx = fabs (xEnd - x0),  dy = fabs(yEnd - y0);
    int yIncrement = 1;
    int p = 2 * dy - dx;
    int twoDy = 2 * dy,  twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
        yEnd = y0;
    }else{
        x = x0;
        y = y0;
    }

    if(y > yEnd ){
        yIncrement = -1;
    }

    setPixel (x, y, 0, c);
    while (x < xEnd) {
        x++;
        if (p < 0){
            p += twoDy;
        }else {
            y = y + yIncrement;
            p += twoDyMinusDx;
        }
        setPixel (x, y, 0, c);
    }
}

void
LineBres::drawForBig(int x0, int y0, int xEnd, int yEnd, const RGBA &c) const {
    int dx = fabs (xEnd - x0),  dy = fabs(yEnd - y0);
    int xIncrement = 1;
    int p = 2 * dx - dy;
    int twoDx = 2 * dx,  twoDxMinusDy = 2 * (dx - dy);
    int x, y;

    if (y0 > yEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
        yEnd = y0;
    }else{
        x = x0;
        y = y0;
    }

    if(x > xEnd){
        xIncrement = -1;
    }

    setPixel (x, y, 0, c);
    while (y < yEnd) {
        y++;
        if (p < 0){
            p += twoDx;
        }else {
            x = x + xIncrement;
            p += twoDxMinusDy;
        }
        setPixel (x, y, 0, c);
    }
}

void
LineBres::draw(const RGBA &c) const {
    int x0 = points[0].x,  y0 = points[0].y, xEnd = points[1].x, yEnd = points[1].y;
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    if(dx > dy){
        drawForSmall(x0, y0, xEnd, yEnd, c);
    }else{
        drawForBig(x0, y0, xEnd, yEnd, c);
    }
}

void
LineBres::color(const RGBA &c) const {
    int x0 = points[0].x,  y0 = points[0].y, xEnd = points[1].x, yEnd = points[1].y;
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    if(dx > dy){
        drawForSmall(x0, y0, xEnd, yEnd, c);
    }else{
        drawForBig(x0, y0, xEnd, yEnd, c);
    }
}

void
LineBres::info() const {
    cout << "Shape name: " << shapeName << "; Shape type: " << shapeType << endl;
    cout << "From (" << points[0].x << ", " << points[0].y << ") to (" << points[1].x << ", " << points[1].y << ")" << endl;
}

string
LineBres::type() const {
    return shapeType;
}

string
LineBres::name() const {
    return shapeName;
}
/*
 * Implementation of Poly class
 */
