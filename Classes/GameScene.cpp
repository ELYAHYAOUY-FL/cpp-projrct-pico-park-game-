#include "GameScene.h"
USING_NS_CC;
int currentLevel;
int repet;
Scene* GameScene::createScene(int curntLevel,int r)
{ 
    currentLevel = curntLevel;
    repet = r;
    auto scene = GameScene::createWithPhysics();
    //scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return  scene;
}

bool   GameScene::init()
{
     
    if (!Scene::init())
    {
        return false;
    }
    continaireNode = Node::create();
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    background = Sprite::create("backgrou.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    continaireNode->addChild(background);
    //log("player");
    player = new Player(this);
    continaireNode->addChild(player->playerSprite);
 
    log("curent"+currentLevel);
    level = new Level(continaireNode, currentLevel);
    level->repet = repet;
    this->addChild(continaireNode);
    auto gameBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 1);
    auto gameNode = Node::create();
    gameNode->setPhysicsBody(gameBody);
    gameNode->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(gameNode);
    floorNode = cocos2d::Node::create();
    floorNode->setPosition(Vec2(0.0f, origin.y));
    floorNode->setContentSize(cocos2d::Size(visibleSize.width, 27.0f));
    floorBody = cocos2d::PhysicsBody::createBox(floorNode->getContentSize());
    floorBody->setDynamic(false);
    floorNode->setPhysicsBody(floorBody);
    this->addChild(floorNode);
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(GameScene::keyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(GameScene::keyReleased, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameScene::contactBegin, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
    return true;

}
void GameScene::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
        log("up");
        this->player->upKey();
        this->upPressed = true;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
        log("left");
        this->player->leftKey();
        this->leftPressed = true;
        if (continaireNode->getPositionX() < 350) {

            this->continaireNode->setPosition(continaireNode->getPositionX() + 15, continaireNode->getPositionY());
        }

    }
    if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        log("right");
        this->player->rightKey();
        this->rightPressed = true;
        logf(continaireNode->getPositionX());
        if(continaireNode->getPositionX()> -350){ 
            
            this->continaireNode->setPosition(continaireNode->getPositionX() - 15, continaireNode->getPositionY());
        }
    }
    if (this->upPressed && this->leftPressed && !this->rightPressed) {
        this->player->upLeftKey();
        log("r");
        if (continaireNode->getPositionX() < 350) {

            this->continaireNode->setPosition(continaireNode->getPositionX() + 25, continaireNode->getPositionY());
        }
    }
    if (this->upPressed && this->rightPressed && !this->leftPressed) {
        this->player->upRightKey();
        log("r");
        if (continaireNode->getPositionX() > -350) {

            this->continaireNode->setPosition(continaireNode->getPositionX() - 25, continaireNode->getPositionY());
        }
    }
}
void GameScene::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
        this->upPressed = false;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
        this->leftPressed = false;

    }
    if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
        this->rightPressed = false;

    }
}
bool  GameScene::contactBegin(cocos2d::PhysicsContact& contact) {
    PhysicsBody* firstBody = contact.getShapeA()->getBody();
    PhysicsBody* secondBody = contact.getShapeB()->getBody();
    if ((firstBody->getCollisionBitmask() == PLAYER_CODE && secondBody->getCollisionBitmask() == PORTE_CODE) || (firstBody->getCollisionBitmask() == PORTE_CODE && secondBody->getCollisionBitmask() == PLAYER_CODE)){
        if (keyContact) {
            log("succes");
            if (currentLevel == LEVEL_1) {
                auto msg = cocos2d::Sprite::create("level2.png");
                msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(msg);
                auto playButton = MenuItemImage::create("pla.png", "playe.png", CC_CALLBACK_1(GameScene::nextLevel, this));
                playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y -65));
                playButton->setScale(0.6);
                auto menu = Menu::create(playButton, NULL);
                menu->setPosition(Point::ZERO);
                this->addChild(menu);
                player->playerSprite->removeFromParentAndCleanup(true);
                player->playerBody->removeFromWorld();
           }
          else if (currentLevel == LEVEL_2) {
                auto msg = cocos2d::Sprite::create("level3.png");
                msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(msg);
                auto playButton = MenuItemImage::create("pla.png", "playe.png", CC_CALLBACK_1(GameScene::nextLevel, this));
                playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 65));
                playButton->setScale(0.6);
                auto menu = Menu::create(playButton, NULL);
                menu->setPosition(Point::ZERO);
                this->addChild(menu);
                player->playerSprite->removeFromParentAndCleanup(true);
                player->playerBody->removeFromWorld();
            }
            else if (currentLevel == LEVEL_3) {
                auto photo = cocos2d::Sprite::create("end.jpg");
                photo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
                this->addChild(photo);
                player->playerSprite->removeFromParentAndCleanup(true);
                player->playerBody->removeFromWorld();
               
            }
        }
        else {
            log("ref");
        }
    }
    if ((firstBody->getCollisionBitmask() == PLAYER_CODE && secondBody->getCollisionBitmask() == CLE_CODE) || (firstBody->getCollisionBitmask() == CLE_CODE && secondBody->getCollisionBitmask() == PLAYER_CODE)) {
        log("CLE");
        level->cle->removeFromParentAndCleanup(true);
        level->cleBody->removeFromWorld();
        keyContact = true;
    }
    if ((firstBody->getCollisionBitmask() == PLAYER_CODE && secondBody->getCollisionBitmask() == DANGER_CODE) || (firstBody->getCollisionBitmask() == DANGER_CODE && secondBody->getCollisionBitmask() == PLAYER_CODE)) {
        log("CLE");
        player->playerSprite->removeFromParentAndCleanup(true);
        player->playerBody->removeFromWorld();
        auto msg = cocos2d::Sprite::create("gam.jpg");
        msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        this->addChild(msg);
        if (level->repet != 0) {
            if (level->repet == 3) {
                auto msg = cocos2d::Sprite::create("couers.png");
                msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+100));
                this->addChild(msg);
            }
            else if (level->repet == 2) {
                auto msg = cocos2d::Sprite::create("couer.png");
                msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+100));
                this->addChild(msg);
            }
            else {
                auto msg = cocos2d::Sprite::create("couer2.png");
                msg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y+100));
                this->addChild(msg);
            }
            --level->repet;
            auto playButton = MenuItemImage::create("pla.png", "playe.png", CC_CALLBACK_1(GameScene::sameLevel, this,level->repet));
            playButton->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 85));
            playButton->setScale(0.6);
            auto menu = Menu::create(playButton, NULL);
            menu->setPosition(Point::ZERO);
            this->addChild(menu);
        }
       
    }

        
    return true;
}
void GameScene::nextLevel(cocos2d::Ref* sinder) {
    if (currentLevel != LEVEL_3) {
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, GameScene::createScene(++currentLevel,level->repet)));
    
    }
}
void GameScene::sameLevel(cocos2d::Ref* sinder,int repet) {
      
        Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, GameScene::createScene(currentLevel,level->repet)));

    }