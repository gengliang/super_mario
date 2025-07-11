#pragma once

#include <easyx.h>
#include "define.h"
#include "sprite.h"

#define MARIO_RUN_ACCELERATION 2
#define MARIO_FRICTION_ACCELERATION 1
#define MARIO_MAX_SPEED 20
#define MARIO_INIT_GLOBAL_X (2 * GRID_WIDTH)
#define MARIO_INIT_GLOBAL_Y (10 * GRID_HEIGHT)
#define MARIO_JUMP_SPEED (-50)

enum marioForm {
    mario_form_small,
    mario_form_super,
    mario_form_fire,
    num_of_mario_form
};

enum marioStatus {
    mario_status_brake,
    mario_status_jump,
    mario_status_run,
    mario_status_stand,
    num_of_mario_status
};

enum marioAction {
    mario_action_brake,
    mario_action_jump,
    mario_action_run0,
    mario_action_run1,
    mario_action_run2,
    mario_action_stand,
    num_of_mario_action
};

struct mario {
    struct sprite super;
    void (*control)(struct mario* m, ExMessage* msg);

    enum marioForm form;
    enum marioStatus status;
    enum marioAction action;
	
	IMAGE* imgArrMario[num_of_mario_form][num_of_mario_action];
    IMAGE* imgArrMarioMask[num_of_mario_form][num_of_mario_action];

	enum direction dir;

	bool isLeftKeyDown;
    bool isRightKeyDown;
    bool isSpaceKeyDown;
	
	int runAcc;

    int runFreqDevider;
};

void marioInit(struct mario*);
void marioDestroy(struct mario*);