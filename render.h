#ifndef INC_2D_EVO_RENDER_H
#define INC_2D_EVO_RENDER_H

#include "raylib.h"
#include "Struckts.h"

#include <vector>

// Рисуем организмы
void DrawCreature(const std::vector<Organism>& organisms);

// Рисуем еду
void DrawFood(const std::vector<Food>& food);

#endif // INC_2D_EVO_RENDER_H