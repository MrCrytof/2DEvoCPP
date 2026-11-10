#include "raylib.h"

#include "render.h"
#include "Struckts.h"

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <limits>

#define MAX_FOOD 20

int main() {

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> positionX(100, 899);
    std::uniform_int_distribution<int> positionY(100, 599);
    std::uniform_int_distribution<int> speedRange(100, 199);
    std::uniform_int_distribution<int> masaRange(10, 29);

    float dt;
    float L;

    float vectx;
    float vecty;

    float deltaX;
    float deltaY;

    int count = 10;

    float DisBet;
    float SlabSize;

    // Создаём вектор еды
    std::vector<Food> food(MAX_FOOD);

    // Генерируем еду
    for (int i = 0; i < MAX_FOOD; i++) {

        food[i].x = positionX(gen);
        food[i].y = positionY(gen);
        food[i].value = 10;
        food[i].alive = true;
    }

    // Создаём вектор организмов
    std::vector<Organism> organisms(count);

    // Генерируем организмы
    for (int i = 0; i < count; i++) {

        organisms[i].x = positionX(gen);
        organisms[i].y = positionY(gen);
        organisms[i].speed = speedRange(gen);
        organisms[i].masa = masaRange(gen);
        organisms[i].alive = true;
        organisms[i].dx = 0;
        organisms[i].dy = 0;
    }

    // Создаём окно
    InitWindow(1000, 700, "2D Evolution Simulator");

    // Ограничиваем FPS
    SetTargetFPS(60);

    // Главный цикл программы
    while (!WindowShouldClose()) {

        dt = GetFrameTime();

        // Проверка столкновений организмов
        for (int i = 0; i < count; i++) {

            for (int j = 0; j < count; j++) {

                if (i != j) {

                    vectx = organisms[j].x - organisms[i].x;
                    vecty = organisms[j].y - organisms[i].y;

                    L = std::sqrt(
                        vectx * vectx + vecty * vecty
                    );

                    DisBet = organisms[i].masa + organisms[j].masa;

                    if (L < DisBet && L > 0) {

                        SlabSize = DisBet - L;

                        organisms[i].dx = vectx / L;
                        organisms[i].dy = vecty / L;

                        deltaX = organisms[i].dx * (SlabSize / 2);
                        deltaY = organisms[i].dy * (SlabSize / 2);

                        organisms[i].x -= deltaX;
                        organisms[i].y -= deltaY;
                    }
                }
            }
        }

        // Поиск ближайшей еды и движение к ней
        for (int i = 0; i < count; i++) {

            int nearestFood = -1;

            float minDistans = std::numeric_limits<float>::max();

            // Ищем ближайшую живую еду
            for (int j = 0; j < MAX_FOOD; j++) {

                if (food[j].alive) {

                    vectx = food[j].x - organisms[i].x;
                    vecty = food[j].y - organisms[i].y;

                    L = std::sqrt(
                        vectx * vectx + vecty * vecty
                    );

                    if (L < minDistans) {

                        minDistans = L;
                        nearestFood = j;
                    }
                }
            }

            // Если еда найдена
            if (nearestFood != -1) {

                vectx = food[nearestFood].x - organisms[i].x;
                vecty = food[nearestFood].y - organisms[i].y;

                L = std::sqrt(
                    vectx * vectx + vecty * vecty
                );

                if (L > 0) {

                    organisms[i].dx = vectx / L;
                    organisms[i].dy = vecty / L;
                }

                // Вычисляем перемещение
                deltaX = organisms[i].dx * organisms[i].speed * dt;
                deltaY = organisms[i].dy * organisms[i].speed * dt;

                organisms[i].x += deltaX;
                organisms[i].y += deltaY;

                // Проверяем поедание еды
                if (L <= organisms[i].masa + food[nearestFood].value) {

                    food[nearestFood].alive = false;
                }
            }
        }

        // Отрисовка
        BeginDrawing();

        ClearBackground(Color{20, 24, 35, 255});

        DrawFood(food);
        DrawCreature(organisms);

        EndDrawing();
    }

    // Закрываем окно
    CloseWindow();

    return 0;
}