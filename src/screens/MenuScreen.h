#pragma once

#include "screens/Screen.h"
class MenuScreen : public Screen
{
    public:
        Screen::Type update(float dt) override;
        void render() const override;
};
