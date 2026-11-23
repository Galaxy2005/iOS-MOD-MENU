#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayerObject.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

// 1. Noclip Hook
class $modify(PlayerObject) {
    void playerDestroyed(bool p0) {
        if (Mod::get()->getSettingValue<bool>("noclip")) {
            return; // Ignore death when Noclip is enabled
        }
        PlayerObject::playerDestroyed(p0);
    }
};

// 2. Practice Music & Speedhack Hooks
class $modify(PlayLayer) {
    void startMusic() {
        if (m_isPracticeMode && Mod::get()->getSettingValue<bool>("practice-music")) {
            // Skip switching to the practice song
            return;
        }
        PlayLayer::startMusic();
    }

    void update(float dt) {
        float speed = Mod::get()->getSettingValue<double>("speedhack");
        CCDirector::sharedDirector()->getScheduler()->setTimeScale(speed);
        PlayLayer::update(dt);
    }
};

// 3. Add a quick-access Mod Menu button to the Main Menu
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto menu = this->getChildByID("bottom-menu");
        if (menu) {
            auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
            spr->setScale(0.8f);
            auto btn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(MyMenuLayer::onOpenModMenu)
            );
            btn->setID("ios-mod-menu-btn"_spr);
            menu->addChild(btn);
            menu->updateLayout();
        }
        return true;
    }

    void onOpenModMenu(CCObject*) {
        // Opens Geode's built-in interactive settings popup for this mod
        openSettingsPopup(Mod::get());
    }
};

// 4. Add the same quick-access Mod Menu button to the In-Level Pause Menu
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = this->getChildByID("right-button-menu");
        if (menu) {
            auto spr = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
            spr->setScale(0.7f);
            auto btn = CCMenuItemSpriteExtra::create(
                spr,
                this,
                menu_selector(MyPauseLayer::onOpenModMenu)
            );
            menu->addChild(btn);
            menu->updateLayout();
        }
    }

    void onOpenModMenu(CCObject*) {
        openSettingsPopup(Mod::get());
    }
};
