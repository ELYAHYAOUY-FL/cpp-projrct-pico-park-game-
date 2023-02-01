 
#include "AppDelegate.h"
#include "SplashScene.h"
 

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
     
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("MyCppGame", cocos2d::Rect(0, 0,1400, 1000));
#else
        glview = GLViewImpl::create("MyCppGame");
#endif
        director->setOpenGLView(glview);
        
    }

     
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

    auto fileUtils = FileUtils::getInstance();
    auto screenSize = glview->getFrameSize();
    std::vector<std::string> resDirOrders;

    // check which assets the devices requires
    if (2048 == screenSize.width || 2048 == screenSize.height)
    {
        resDirOrders.push_back("ipadhd");
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");

        glview->setDesignResolutionSize(2048, 1536, ResolutionPolicy::NO_BORDER);
    }
    else if (1024 == screenSize.width || 1024 == screenSize.height)
    {
        resDirOrders.push_back("ipad");
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");

        glview->setDesignResolutionSize(1024, 768, ResolutionPolicy::NO_BORDER);
    }
    else if (1136 == screenSize.width || 1136 == screenSize.height)
    {
        resDirOrders.push_back("iphonehd5");
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");

        glview->setDesignResolutionSize(1136, 640, ResolutionPolicy::NO_BORDER);
    }
    else if (960 == screenSize.width || 960 == screenSize.height)
    {
        resDirOrders.push_back("iphonehd");
        resDirOrders.push_back("iphone");

        glview->setDesignResolutionSize(960, 640, ResolutionPolicy::NO_BORDER);
    }
    else
    {
        resDirOrders.push_back("iphone");

        glview->setDesignResolutionSize(480, 320, ResolutionPolicy::NO_BORDER);
    }

    fileUtils->setSearchPaths(resDirOrders);

    // create a scene. it's an autorelease object
    auto scene = SplashScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}



