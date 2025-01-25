#pragma once
#include "Arduino.h"
#include "hardware/display/display.h"

#define GOLDIEGULP_GRAVITY 4
#define GOLDIEGULP_JUMP -30
#define GOLDIEGULP_MAX_SPEED -10
#define GOLDIEGULP_X 40

#define GOLDIEGULP_OBSTICLE_WIDTH 20
#define GOLDIEGULP_OBSTICLE_MIN_GAP 80
#define GOLDIEGULP_OBSTICLE_SPEED 8

struct Obsticle
{
    int16_t x;
    uint8_t opening_start;
    uint8_t opening_end;
};

class GoldieGulp
{
private:
    static uint8_t current_frame, oldY, frame_direction;
    static int16_t y;
    static int16_t speed;
    static Obsticle obsticle;
    static void eraseOldFish();
    static void renderGameGoldie();
    static void renderObsticle();
    static void checkCollision();
    static void renderScore();
    static void (*gameOverCallback)();

public:
    static uint16_t score;
    static void onGameOver(void (*callback)());
    GoldieGulp();
    static void loop();
    static void setup();
    static void jump();
};
