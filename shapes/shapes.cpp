#include "shapes.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

void DemoShapes() {
    // ── Forma antigua: arreglo de raw pointers ──────────────────────────────
    cout << "=== Raw pointers ===\n";
    Shape* arr[] = {
        new Circle   (0.0, 0.0, 5.0),
        new Triangle (6.0, 4.0),
        new Rectangle(8.0, 3.0, "MyRect"),
        new Square   (4.0)
    };
    const size_t n = sizeof(arr) / sizeof(arr[0]);

    for (size_t i = 0; i < n; i++)
        cout << arr[i]->GetName() << " -> area = " << arr[i]->GetArea() << "\n";

    for (size_t i = 0; i < n; i++)
        delete arr[i];

    // ── Con vector<unique_ptr> + lambdas ────────────────────────────────────
    cout << "\n=== vector + lambdas ===\n";
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>   (0.0, 0.0, 5.0));
    shapes.push_back(make_unique<Triangle> (6.0, 4.0));
    shapes.push_back(make_unique<Rectangle>(8.0, 3.0, "MyRect"));
    shapes.push_back(make_unique<Square>   (4.0));

    // Lambda guardada en variable — se puede reutilizar
    auto imprimir = [](const unique_ptr<Shape>& s) {
        cout << s->GetName() << " -> area = " << s->GetArea() << "\n";
    };

    // Opción A: range-for con la lambda
    cout << "-- range-for --\n";
    for (const auto& s : shapes)
        imprimir(s);

    // Opción B: for_each — conecta con el patrón ApplyFunctionToAll del curso
    cout << "-- for_each --\n";
    for_each(shapes.begin(), shapes.end(), imprimir);

    // Lambda inline con captura: imprime solo las que superan un área mínima
    cout << "-- filtro area > 20 --\n";
    Area minArea = 20.0;
    for_each(shapes.begin(), shapes.end(), [minArea](const unique_ptr<Shape>& s) {
        if (s->GetArea() > minArea)
            cout << s->GetName() << " -> area = " << s->GetArea() << "\n";
    });
}
