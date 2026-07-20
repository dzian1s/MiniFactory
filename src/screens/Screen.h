#pragma once

class Screen
{
    public:
        enum class Type
        {
            Menu,
            Game,
            None,
        };
    public:
        virtual ~Screen() = default;

        virtual Type update(float dt) = 0;
        virtual void render() const = 0;
};
