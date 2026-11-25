#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

// Example of modifying MenuLayer to show a notification when the game starts
class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        // Display a popup/notification on the main menu
        FLAlertLayer::create(
            "iOS Mod Menu",
            "Hello <cG>Galaxy2005</c>! Your Geode v6 mod is working successfully!",
            "OK"
        )->show();

        return true;
    }
};
