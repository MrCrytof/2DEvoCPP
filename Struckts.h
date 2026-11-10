#ifndef INC_2D_EVO_STRUCTS_H
#define INC_2D_EVO_STRUCTS_H

// Структура организма
struct Organism {
    float x;
    float y;
    int speed;
    int masa;
    bool alive;
    float dx;
    float dy;
};

// Структура еды
struct Food {
    float x;
    float y;
    int value;
    bool alive;
};

#endif // INC_2D_EVO_STRUCTS_H