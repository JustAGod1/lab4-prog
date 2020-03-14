//
// Created by justagod on 3/14/20.
//

#ifndef LAB4_PROG_DATA_H
#define LAB4_PROG_DATA_H

#include <vector>
#include "primitives.h"

class ControlPanel {
private:
    std::vector<GeometricFigure*> data;
public:
    void add_item(GeometricFigure *item);
    void draw_all();
    float sum_of_areas();
    float sum_of_perimeters();
    Vector2D center_of_mass();
    long memory_footprint();
    void sort();
};

#endif //LAB4_PROG_DATA_H
