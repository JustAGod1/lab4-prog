//
// Created by justagod on 3/14/20.
//

#include <iostream>
#include "data.h"

using namespace std;

void ControlPanel::add_item(GeometricFigure *item) {
    data.push_back(item);
}

void ControlPanel::draw_all() {
    if (data.size() <= 0) {
        cout << "such empty..." << endl;
    }
    int c = 1;
    for (auto & i : data) {
        cout << c << ") ";
        i->draw();
        cout << endl;
        c++;
    }
}

float ControlPanel::sum_of_areas() {
    float result = 0;
    for (auto & i : data) {
        result += i->square();
    }

    return result;
}

float ControlPanel::sum_of_perimeters() {
    float result = 0;
    for (auto & i : data) {
        result += i->perimeter();
    }

    return result;
}

Vector2D ControlPanel::center_of_mass() {
    float x_denominator = 0, x_numerator = 0;
    for (auto &x : data) {
        x_numerator += x->mass() * x->position().x;
        x_denominator += x->mass();
    }
    float y_denominator = 0, y_numerator = 0;
    for (auto &x : data) {
        y_numerator += x->mass() * x->position().y;
        y_denominator += x->mass();
    }

    Vector2D result;

    result.x = x_numerator / x_denominator;
    result.y = y_numerator / y_denominator;

    return result;
}

long ControlPanel::memory_footprint() {
    float result = 0;
    for (auto & i : data) {
        result += i->size();
    }

    return result;
}

void ControlPanel::sort() {
    cout << "sorting..." << endl;
    for (int i = 0; i < data.size(); i++) {
        GeometricFigure *e = data[i];
        int j = i - 1;
        while (j >= 0 && data[j]->mass() > e->mass()) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = e;
    }
    cout << "done" << endl;
}
