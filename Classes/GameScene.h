

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "Level.h"
#include "Definition.h"

class   GameScene : public cocos2d::Scene
{
private:
    bool upPressed = false;
    bool  leftPressed = false;
    bool rightPressed = false;
    bool keyContact = false;
    //int currentLevel;



public:
    cocos2d::Node *floorNode;
    cocos2d::PhysicsBody *floorBody;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Sprite* background;
    cocos2d::Node* continaireNode;
    static cocos2d::Scene* createScene(int currentLevel,int repet);
    Player *player;
    Level* level;
   
    virtual bool init();
    CREATE_FUNC(GameScene);
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event); 
    void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);/*ajouter boutton*/
    bool contactBegin(cocos2d::PhysicsContact& contact);
    void nextLevel(cocos2d::Ref* sinder);
    void sameLevel(cocos2d::Ref* sinder,int repet);
};

#endif // __GAME_SCENE_H__
     