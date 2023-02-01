

#ifndef __LEVEL_H__
#define __LEVEL_H__

#include "cocos2d.h"


class Level
{
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
   
public:
    int myLevel;
    int repet = 3;
    cocos2d::Sprite* porte;
    cocos2d::Sprite* cle;
    cocos2d::PhysicsBody* cleBody;
    cocos2d::Sprite* danger;
    cocos2d::Sprite* danger2;
    cocos2d::PhysicsBody* dangerBody;
    cocos2d::PhysicsBody* danger2Body;
    Level(cocos2d::Node* scene, int myLevel);
    void createLvel(cocos2d:: Node* scene);
 
};

#endif // __LEVEL_H__
     