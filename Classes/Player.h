

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player
{
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
   
public:
    cocos2d::Sprite* playerSprite;
    cocos2d::PhysicsBody* playerBody;
    Player(cocos2d::Scene *scene);
    void upKey();
    void leftKey();
    void rightKey();
    void upLeftKey();
    void upRightKey();
 
};

#endif // __PLAYER_H__
     