#include " MainMenuScene.h"
#include <GameScene.h>
#include <Definition.h>


USING_NS_CC;

Scene* MainMenuScene::createScene()
{ 
    return MainMenuScene::create();
}
bool MainMenuScene::init()
{
    
    if (!Scene::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("level1.jpg");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);
    auto playButton = MenuItemImage::create("pla.png", "playe.png", CC_CALLBACK_1(MainMenuScene::goToGameScene, this));
    playButton->setScale(0.6);
    playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y -55));
    auto menu = Menu::create(playButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    return true;

}
void MainMenuScene::goToGameScene(cocos2d::Ref* s) {
    auto scene = GameScene::createScene(LEVEL_1,3);
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
