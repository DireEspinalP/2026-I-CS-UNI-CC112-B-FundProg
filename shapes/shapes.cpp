#include "shapes.h"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

void DemoShapes() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>   (0.0, 0.0, 5.0));
    shapes.push_back(make_unique<Triangle> (6.0, 4.0));
    shapes.push_back(make_unique<Rectangle>(8.0, 3.0, "MyRect"));
    shapes.push_back(make_unique<Square>   (4.0));

    for (const auto& s : shapes)
        cout << s->GetName() << " -> area = " << s->GetArea() << "\n";
}
