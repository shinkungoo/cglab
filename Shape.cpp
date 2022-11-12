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
 * Implementation of Point class
 */