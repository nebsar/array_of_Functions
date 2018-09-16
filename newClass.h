/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newClass.h
 * Author: Eagleye
 *
 * Created on September 14, 2018, 2:05 AM
 */

#ifndef NEWCLASS_H
#define NEWCLASS_H

class newClass {
protected:
    int i;
    int j;

public:
    newClass();
    newClass(const newClass& orig);
    virtual ~newClass();
private:

};

class Child : public newClass {

};

#endif /* NEWCLASS_H */

