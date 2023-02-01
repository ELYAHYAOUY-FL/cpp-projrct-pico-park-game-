#include "Level.h"
#include "Definition.h"
 
USING_NS_CC;

 
 
Level::Level(Node* scene,int myLevel) {
	 visibleSize = Director::getInstance()->getVisibleSize();
	 origin = Director::getInstance()->getVisibleOrigin();
	 this->myLevel = myLevel;
     porte = Sprite::create("port.png");
     cle = Sprite::create("key.png");
     danger = Sprite::create("coli3.png");
     danger2 = Sprite::create("coli4.png");
     
	 createLvel(scene);
}
void Level::createLvel(Node* scene) {
    if (this->myLevel == LEVEL_1) {
        porte->setPosition(Vec2(visibleSize.width / 2 + origin.x + 570, visibleSize.height / 2 + origin.y -75 ));
        auto porteBody = PhysicsBody::createBox(porte->getContentSize());
        porteBody->setCollisionBitmask(PORTE_CODE);
        porteBody->setContactTestBitmask(true);
        porteBody->setDynamic(false);
        porte->setPhysicsBody(porteBody);
        scene->addChild(porte);
        cle->setPosition(Vec2(visibleSize.width / 2 + origin.x + 270, visibleSize.height / 2 + origin.y + 90));
        cleBody = PhysicsBody::createBox(cle->getContentSize());
        cleBody->setCollisionBitmask(CLE_CODE);
        cleBody->setContactTestBitmask(true);
        cleBody->setDynamic(false);
        cle->setPhysicsBody(cleBody);
        scene->addChild(cle);
        auto etageSprite = cocos2d::Sprite::create("etage.png");
        etageSprite->setPosition(Vec2(300.0f, 120.0f));
        auto etageBody = cocos2d::PhysicsBody::createBox(etageSprite->getContentSize());
        etageBody->setDynamic(false);
        etageSprite->setPhysicsBody(etageBody);
        scene->addChild(etageSprite);
        auto tageSprite = cocos2d::Sprite::create("tage.png");
        tageSprite->setPosition(Vec2(450.0f, 180.0f));
        auto tageBody = cocos2d::PhysicsBody::createBox(tageSprite->getContentSize());
        tageBody->setDynamic(false);
        tageSprite->setPhysicsBody(tageBody);
        scene->addChild(tageSprite);
        auto etagSprite = cocos2d::Sprite::create("etage.png");
        etagSprite->setPosition(Vec2(500.0f, 120.0f));
        auto etagBody = cocos2d::PhysicsBody::createBox(etagSprite->getContentSize());
        etagBody->setDynamic(false);
        etagSprite->setPhysicsBody(etagBody);
        scene->addChild(etagSprite);
       
	}
    else if (this->myLevel == LEVEL_2) {
        porte->setPosition(Vec2(visibleSize.width / 2 + origin.x +570, visibleSize.height / 2 + origin.y + 70));
        auto porteBody = PhysicsBody::createBox(porte->getContentSize());
        porteBody->setCollisionBitmask(PORTE_CODE);
        porteBody->setContactTestBitmask(true);
        porteBody->setDynamic(false);
        porte->setPhysicsBody(porteBody);
        scene->addChild(porte);
        cle->setPosition(Vec2(visibleSize.width / 2 + origin.x + 320, visibleSize.height / 2 + origin.y + 70));
        cleBody = PhysicsBody::createBox(cle->getContentSize());
        cleBody->setCollisionBitmask(CLE_CODE);
        cleBody->setContactTestBitmask(true);
        cleBody->setDynamic(false);
        cle->setPhysicsBody(cleBody);
        scene->addChild(cle);
        danger->setPosition(Vec2(visibleSize.width / 2 + origin.x -25, visibleSize.height / 2 + origin.y - 72));
        dangerBody = PhysicsBody::createBox(danger->getContentSize());
        dangerBody->setCollisionBitmask(DANGER_CODE);
        dangerBody->setContactTestBitmask(true);
        dangerBody->setDynamic(false);
        danger->setPhysicsBody(dangerBody);
        scene->addChild(danger);
        auto danger3 = cocos2d::Sprite::create("danger.png");
        danger3->setPosition(Vec2(visibleSize.width / 2 + origin.x +280, visibleSize.height / 2 + origin.y - 72));
        auto danger3Body = PhysicsBody::createBox(danger3->getContentSize());
        danger3Body->setCollisionBitmask(DANGER_CODE);
        danger3Body->setContactTestBitmask(true);
        danger3Body->setDynamic(false);
        danger3->setPhysicsBody(danger3Body);
        danger3->setScale(0.8);
        scene->addChild(danger3);
        auto tageSprite = cocos2d::Sprite::create("etag.png");
        tageSprite->setPosition(Vec2(690.0f, 200.0f));
        auto tageBody = cocos2d::PhysicsBody::createBox(tageSprite->getContentSize());
        tageBody->setDynamic(false);
        tageSprite->setPhysicsBody(tageBody);
        scene->addChild(tageSprite);
        auto tagSprite = cocos2d::Sprite::create("tage3.png");
        tagSprite->setPosition(Vec2(370.0f, 70.0f));
        auto tagBody = cocos2d::PhysicsBody::createBox(tagSprite->getContentSize());
        tagBody->setDynamic(false);
        tagSprite->setPhysicsBody(tagBody);
        scene->addChild(tagSprite);
        auto etageSprite = cocos2d::Sprite::create("tage2.png");
        etageSprite->setPosition(Vec2(430.0f, 170.0f));
        auto etageBody = cocos2d::PhysicsBody::createBox(etageSprite->getContentSize());
        etageBody->setDynamic(false);
        etageSprite->setPhysicsBody(etageBody);
        scene->addChild(etageSprite);

      
    }
    else if (this->myLevel == LEVEL_3) {
        porte->setPosition(Vec2(visibleSize.width / 2 + origin.x + 550, visibleSize.height / 2 + origin.y - 30));
        auto porteBody = PhysicsBody::createBox(porte->getContentSize());
        porteBody->setCollisionBitmask(PORTE_CODE);
        porteBody->setContactTestBitmask(true);
        porteBody->setDynamic(false);
        porte->setPhysicsBody(porteBody);

        scene->addChild(porte);
        cle->setPosition(Vec2(visibleSize.width / 2 + origin.x + -120, visibleSize.height / 2 + origin.y + 100));
        cleBody = PhysicsBody::createBox(cle->getContentSize());
        cleBody->setCollisionBitmask(CLE_CODE);
        cleBody->setContactTestBitmask(true);
        cleBody->setDynamic(false);
        cle->setPhysicsBody(cleBody);
        scene->addChild(cle);
        danger->setPosition(Vec2(visibleSize.width / 2 + origin.x + 350, visibleSize.height / 2 + origin.y - 42));
        dangerBody = PhysicsBody::createBox(danger->getContentSize());
        dangerBody->setCollisionBitmask(DANGER_CODE);
        dangerBody->setContactTestBitmask(true);
        dangerBody->setDynamic(false);
        danger->setPhysicsBody(dangerBody);
        scene->addChild(danger);
       // danger->setScale(0.5);
        auto etageSprite = cocos2d::Sprite::create("etage.png");
        etageSprite->setPosition(Vec2(660.0f, 100.0f));
        auto etageBody = cocos2d::PhysicsBody::createBox(etageSprite->getContentSize());
        etageBody->setDynamic(false);
        etageSprite->setPhysicsBody(etageBody);
        scene->addChild(etageSprite);
        auto tage2Sprite = cocos2d::Sprite::create("coli5.png");
        tage2Sprite->setPosition(Vec2(-12.0f, 140.0f));
        auto tage2Body = cocos2d::PhysicsBody::createBox(tage2Sprite->getContentSize());
        tage2Body->setDynamic(false);
        tage2Sprite->setPhysicsBody(tage2Body);
        scene->addChild(tage2Sprite);
        auto tageSprite = cocos2d::Sprite::create("tage3.png");
        tageSprite->setPosition(Vec2(160.0f, 85.0f));
        auto tageBody = cocos2d::PhysicsBody::createBox(tageSprite->getContentSize());
        tageBody->setDynamic(false);
        tageSprite->setPhysicsBody(tageBody);
        scene->addChild(tageSprite);
        auto tagSprite = cocos2d::Sprite::create("tage3.png");
        tagSprite->setPosition(Vec2(-250.0f, 80.0f));
        auto tagBody = cocos2d::PhysicsBody::createBox(tagSprite->getContentSize());
        tagBody->setDynamic(false);
        tagSprite->setPhysicsBody(tagBody);
        scene->addChild(tagSprite);
        danger2->setPosition(Vec2(visibleSize.width / 2 + origin.x + 200, visibleSize.height / 2 + origin.y - 72));
        danger2Body = PhysicsBody::createBox(danger2->getContentSize());
        danger2Body->setCollisionBitmask(DANGER_CODE);
        danger2Body->setContactTestBitmask(true);
        danger2Body->setDynamic(false);
        danger2->setPhysicsBody(danger2Body);
        scene->addChild(danger2);
        auto danger3 = cocos2d::Sprite::create("coli4.png");
        danger3->setPosition(Vec2(visibleSize.width / 2 + origin.x - 260, visibleSize.height / 2 + origin.y + 30));
        auto danger3Body = PhysicsBody::createBox(danger3->getContentSize());
        danger3Body->setCollisionBitmask(DANGER_CODE);
        danger3Body->setContactTestBitmask(true);
        danger3Body->setDynamic(false);
        danger3->setPhysicsBody(danger3Body);
        danger3->setScale(0.8);
        scene->addChild(danger3);
        auto danger4 = cocos2d::Sprite::create("coli4.png");
        danger4->setPosition(Vec2(visibleSize.width / 2 + origin.x + 200, visibleSize.height / 2 + origin.y -42));
        auto danger4Body = PhysicsBody::createBox(danger4->getContentSize());
        danger4Body->setCollisionBitmask(DANGER_CODE);
        danger4Body->setContactTestBitmask(true);
        danger4Body->setDynamic(false);
        danger4->setPhysicsBody(danger4Body);
        danger4->setScale(0.5);
        scene->addChild(danger4);
        
    }
}
 