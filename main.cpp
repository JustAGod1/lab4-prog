#include <iostream>
#include "data.h"

using namespace std;

void print_help() {
    cout << "  print-all - prints all stored figures" << endl;
    cout << "  sum-areas - calculate total amount of area consumed by stored figures and prints it" << endl;
    cout << "  sum-perimeters - calculate sum of perimeters and prints it" << endl;
    cout << "  center-of-mass - obviously prints center of mass" << endl;
    cout << "  mem-fp - prints total amount of memory consumed by figures as if we bean in ideal world" << endl;
    cout << "  sort - sorts figures by theirs masses" << endl;
    cout << "  circle - creates circle" << endl;
    cout << "  triangle - creates equilateral triangle" << endl;
    cout << "  exit - terminates program" << endl;
}

int main() {
    ControlPanel panel{};

    string cmd;
    while (true) {
        cout << "Type a command(h for help): ";
        cin >> cmd;

        if (cmd == "exit") break;
        else if (cmd == "h") print_help();
        else if (cmd == "print-all") panel.draw_all();
        else if (cmd == "sum-areas") cout << panel.sum_of_areas() << endl;
        else if (cmd == "sum-perimeters") cout << panel.sum_of_perimeters() << endl;
        else if (cmd == "mem-fp") cout << panel.memory_footprint() << endl;
        else if (cmd == "sort") panel.sort();
        else if (cmd == "center-of-mass") {
            Vector2D v = panel.center_of_mass();
            cout << "{ x: " << v.x << ", y: " << v.y << "}" << endl;
        } else if (cmd == "circle") {
            auto *c = new Circle();
            c->initFromDialog();
            panel.add_item(c);
        } else if (cmd == "triangle") {
            auto *c = new EquilateralTriangle();
            c->initFromDialog();
            panel.add_item(c);
        } else cout << "unknown command" << endl;
    }

    return 0;
}
