#include "render.h"

// Рисуем организмы
void DrawCreature(const std::vector<Organism>& organisms) {

    for (const Organism& organism : organisms) {

        if (organism.alive) {
            DrawCircle(
                organism.x,
                organism.y,
                organism.masa,
                GREEN
            );
        }
    }
}

// Рисуем еду
// Рисуем еду
void DrawFood(const std::vector<Food>& food) {

    for (const Food& item : food) {

        if (item.alive) {
            DrawCircle(
                item.x,
                item.y,
                item.value,
                RED
            );
        }
    }
}