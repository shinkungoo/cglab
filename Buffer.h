/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Buffer.h                                                        *
*  @brief    all buffers                                                     *
*  This file define a class Buffer which contains all buffer which will be   *
*  used in this structure. I DO NOT recommend you to modify this part        *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-09                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/
#ifndef CGLAB_BUFFER_H
#define CGLAB_BUFFER_H
#include "standardLibrary.h"
#include "Singleton.h"
#include "Shape.h"
#include "Commands.h"

class Buffer: public Singleton<Buffer> {
    friend class Singleton<Buffer>;
private:
    Buffer() = default;
public:
    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) override = delete;

    vector<Point>                       pointBuffer;
    deque<deque<string>>                commandBuffer;
    map<string, Shape*>                 shapeBuffer;
};


#endif //CGLAB_BUFFER_H
