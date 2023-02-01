 

#include "SplashScene.h"
#include " MainMenuScene.h"
#include "Definition.h"
 
USING_NS_CC;

Scene* SplashScene::createScene()
{
    
    auto scene = Scene::create();

    
    auto layer = SplashScene::create();

    scene->addChild(layer);
    return scene;
}
 
bool SplashScene::init()
{
    
    if (!Scene::init())
    {
        return false;
    }
    this->scheduleOnce(CC_SCHEDULE_SELECTOR(SplashScene::goToMainMenuScene), DISPLAY_TIME);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("ino.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);
    return true;
}

void SplashScene::goToMainMenuScene(float dt) {
    auto scene = MainMenuScene::createScene();
    
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
 
 