#include "Player.h"
#include "Definition.h"
USING_NS_CC;

 
 
Player::Player(Scene* scene) {
	 visibleSize = Director::getInstance()->getVisibleSize();
	 origin = Director::getInstance()->getVisibleOrigin();
	playerSprite = Sprite::create("player.png");
	playerSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x-220, visibleSize.height / 2 + origin.y -80));
	playerBody = playerSprite->getPhysicsBody();
	auto materiel = cocos2d::PhysicsMaterial(5.0f, 0.0f, 6.0f);
	playerBody = PhysicsBody::createBox(playerSprite->getContentSize(), materiel);
	playerBody->setCollisionBitmask(PLAYER_CODE);
	playerBody->setContactTestBitmask(true);

	playerSprite->setPhysicsBody(playerBody);
	 
}
void Player::upKey() {
	auto action = JumpBy::create(SPEED, Point( 0, 0), 100, 1);
	this->playerSprite->runAction(action);
}
void Player::leftKey(){
	auto action = MoveBy::create(SPEED, Point(-20, 0));
	this->playerSprite->runAction(action);


}
void Player::rightKey(){
	auto action = MoveBy::create(SPEED, Point(20, 0));
	this->playerSprite->runAction(action);

}
void Player::upLeftKey() {
	auto action = JumpBy::create(SPEED, Point(-50,60), 100, 1);
	this->playerSprite->runAction(action);
}
void Player::upRightKey() {
	auto action = JumpBy::create(SPEED, Point(50,60), 100, 1);
	this->playerSprite->runAction(action);
}
