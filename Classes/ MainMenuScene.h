

#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"

class  MainMenuScene : public cocos2d::Scene
{
public:
     
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MainMenuScene);
private:
    void goToGameScene(cocos2d::Ref *s);
    
};

#endif // __MAIN_MENU_SCENE_H__
     