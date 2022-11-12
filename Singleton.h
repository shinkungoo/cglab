/*****************************************************************************
*  Lab Platform for Computer Graphics                                        *
*  Copyright (C) 2022 Junhao Shen                                            *
*                                                                            *
*  @file     Singleton.h                                                     *
*  @brief    Singleton class declaration                                     *
*  This class is designed to implement singleton pattern for other class like*
*  Global and so on.                                                         *
*                                                                            *
*  @author   Junhao Shen                                                     *
*  @email    shinkungoo133500@gmail.com                                      *
*  @version  2.0.0                                                           *
*  @date     2022-11-17                                                      *
*  @license  GNU General Public License (GPL)                                *
*****************************************************************************/

#ifndef CGLAB_SINGLETON_H
#define CGLAB_SINGLETON_H

template<typename T>
class Singleton {
public:
    static T& getInstance()
    {
        static T instance;
        return instance;
    }

    Singleton(T &&) = delete;
    Singleton(const T &&) = delete;
    virtual T& operator=(const T&) = delete;
protected:
    Singleton() = default;
    virtual ~Singleton() = default;
};

#endif //CGLAB_SINGLETON_H
