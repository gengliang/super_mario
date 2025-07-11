#include "mario.h"
#include "image.h"
#include <stdio.h>
#include "utility.h"
#include <stdlib.h>
#include "vector.h"
#include "direction.h"
#include "flipimage.h"
#include "spritetype.h"

const char* marioFormStrs[] = {
    "small",
    "super",
    "fire"
};

const char* marioActionStrs[] = {
    "brake",
    "jump",
    "run0",
    "run1",
    "run2",
    "stand"
};

void marioDraw(struct mario* m)
{
    IMAGE *pImage = m->imgArrMario[m->form][m->action];
    IMAGE* pImageMask = m->imgArrMarioMask[m->form][m->action];
    if (m->dir & direction_right)
    {
        putTransparentImage(m->super.x, m->super.y, pImageMask, pImage);
    }
    else
    {
        IMAGE imgFlip, imgMaskFlip;
        imgFlip = *pImage;
        imgMaskFlip = *pImageMask;
        flipImage(&imgFlip);
        flipImage(&imgMaskFlip);
        putTransparentImage(m->super.x, m->super.y, &imgMaskFlip, &imgFlip);
    }
}

void marioSpeedUpdate(struct mario* m)
{
    //  马里奥加速度
    //  水平方向
    //  ra, run acc跑步加速度
    //  fa, friction acc摩擦力加速度
    int runAcc = 0;
    int frictionAcc = 0;

    //  垂直方向
    //  ga, gravity acceleration重力加速度
    int ga = 0;

    //  run acc跑步加速度
    //  left
    if (m->isLeftKeyDown == true && m->isRightKeyDown == false)
    {
        runAcc = -MARIO_RUN_ACCELERATION;
    }
    //  right
    else if (m->isLeftKeyDown == false && m->isRightKeyDown == true)
    {
        runAcc = MARIO_RUN_ACCELERATION;
    }

    //  friction acc摩擦力加速度
    if (m->status == mario_status_run)
    {
        if (abs(m->super.vx) < MARIO_MAX_SPEED)
            frictionAcc = MARIO_FRICTION_ACCELERATION;
        else
            frictionAcc = MARIO_RUN_ACCELERATION;
        //  摩擦力方向与水平速度方向相反
        frictionAcc *= -sign(m->super.vx);
    }

    //  gravity acc重力加速度
    //  重力加速度在未触及地面时出现
    if (!(m->super.collisionDirs & direction_bottom))
        ga = GRAVITY_ACCELERATION;

    //  水平方向合加速度ax
    int ax = runAcc + frictionAcc;
    //  垂直方向合加速度
    int ay = ga;

    //  计算速度
    //  vx
    m->super.vx += ax;
    //  vy
    m->super.vy += ay;

    //  保存runAcc
    m->runAcc = runAcc;
}

void marioToJumpStatus(struct mario* m)
{
    m->status = mario_status_jump;
    m->super.vy = MARIO_JUMP_SPEED;
    m->super.collisionDirs &= ~direction_bottom;
    m->isSpaceKeyDown = false;
}

void marioStatusUpdate(struct mario* m)
{
    bool isOnGround = false;
    if (m->super.collisionDirs & direction_bottom)
        isOnGround = true;
    switch (m->status)
    {
        //  stand
        case mario_status_stand:
        {
            m->action = mario_action_stand;
            //  to jump
            if (m->isSpaceKeyDown == true && isOnGround)
            {
                marioToJumpStatus(m);
                break;
            }
            //  to run
            if (m->super.vx != 0)
                m->status = mario_status_run;
            break;
        }
        //  run
        case mario_status_run:
        {
            //  action
            if (m->action < mario_action_run0 || m->action > mario_action_run2)
            {
                //  不在范围内
                m->action = mario_action_run0;
            }
            else
            {
                //  在范围内
                if (m->runFreqDevider >= 2)
                {
                    m->action = (enum marioAction)(m->action + 1);
                    if (m->action > mario_action_run2)
                        m->action = mario_action_run0;
                    m->runFreqDevider = 0;
                }
                m->runFreqDevider++;
            }

            //  to stand
            if (m->super.vx == 0)
            {
                m->status = mario_status_stand;
                break;
            }
                
            //  to jump
            if (m->isSpaceKeyDown == true && isOnGround)
            {
                marioToJumpStatus(m);
                break;
            }

            //  to brake
            int raDir, vDir;
            raDir = sign(m->runAcc);
            vDir = sign(m->super.vx);
            if (raDir + vDir == 0 && raDir != 0 && vDir != 0)
            {
                m->status = mario_status_brake;
                break;
            }
            break;
        }
        //  brake
        case mario_status_brake:
        {
            m->action = mario_action_brake;
            //  to jump
            if (m->isSpaceKeyDown == true && isOnGround)
            {
                marioToJumpStatus(m);
                break;
            }

            //  to run
            int raDir, vDir;
            raDir = sign(m->runAcc);
            vDir = sign(m->super.vx);
            if (!(raDir + vDir == 0 && raDir != 0 && vDir != 0))
                m->status = mario_status_run;
            break;
        }
        //  jump
        case mario_status_jump:
        {
            m->action = mario_action_jump;
            if (isOnGround)
            {
                //  to stand
                if (m->super.vx == 0)
                {
                    m->status = mario_status_stand;
                    break;
                }
                //  to run
                else
                {
                    m->status = mario_status_run;
                    break;
                }
            }
            break;
        }
    }

    if (m->super.vx > 0)
        m->dir = direction_right;
    else if (m->super.vx < 0)
        m->dir = direction_left;
}

void marioUpdate(struct mario* m)
{
	//  马里奥速度更新
    marioSpeedUpdate(m);
	//  马里奥状态更新
    marioStatusUpdate(m);
}

void marioControl(struct mario* m, ExMessage* msg)
{
    if (msg->message == WM_KEYDOWN)
    {
        if (msg->vkcode == VK_LEFT)
        {
            m->isLeftKeyDown = true;
        }
        else if (msg->vkcode == VK_RIGHT)
        {
            m->isRightKeyDown = true;
        }
        else if (msg->vkcode == VK_SPACE)
        {
            m->isSpaceKeyDown = true;
        }
    }
    else if (msg->message == WM_KEYUP)
    {
        if (msg->vkcode == VK_LEFT)
        {
            m->isLeftKeyDown = false;
        }
        else if (msg->vkcode == VK_RIGHT)
        {
            m->isRightKeyDown = false;
        }
    }
}

void marioDestroy(struct mario* m)
{
    for (int form = 0; form < num_of_mario_form; form++)
    {
        for (int action = 0; action < num_of_mario_action; action++)
        {
            delete m->imgArrMario[form][action];
            delete m->imgArrMarioMask[form][action];
        }
    }
}

void marioInit(struct mario* m)
{
    spriteInit((sprite*)m);
    m->super.draw = (void (*)(struct sprite*))marioDraw;
    m->super.update = (void (*)(struct sprite*))marioUpdate;
    m->super.destroy = (void (*)(struct sprite*))marioDestroy;
    m->super.globalX = MARIO_INIT_GLOBAL_X;
    m->super.globalY = MARIO_INIT_GLOBAL_Y;
    m->super.zOrder = 2;
    m->super.width = GRID_HEIGHT;
    m->super.height = 1 * GRID_HEIGHT;
    m->super.isCollisionable = true;
    m->super.spriteType = sprite_type_mario;

    //  members
    m->control = marioControl;
    m->form = mario_form_small;
    m->status = mario_status_stand;
    m->dir = direction_right;
    m->isLeftKeyDown = false;
    m->isRightKeyDown = false;
    m->isSpaceKeyDown = false;
    m->runAcc = 0;
    m->runFreqDevider = 0;

    for (int form = 0; form < num_of_mario_form; form++)
    {
        for (int action = 0; action < num_of_mario_action; action++)
        {
            //  拼接图片路径字符串
            char imgPath[50];
            sprintf(imgPath, "img/mario/%s/%s.png", marioFormStrs[form], marioActionStrs[action]);
            //  创建image并加载图片
            m->imgArrMario[form][action] = new IMAGE;
            loadimage(m->imgArrMario[form][action], imgPath);

            //  拼接图片掩码路径字符串
            sprintf(imgPath, "img/mario/%s/%s_mask.png", marioFormStrs[form], marioActionStrs[action]);
            //  创建image并加载图片
            m->imgArrMarioMask[form][action] = new IMAGE;
            loadimage(m->imgArrMarioMask[form][action], imgPath);
        }
    }
}
