#ifndef ANIMATION
#define ANIMATION

#include <vector>
#include "../core/Game.h"
#include "../core/Case.h"
class Animation
{
protected:
    int timeAnimation;

public:
    Animation(/* args */);
    ~Animation();
    virtual void play(){};
    bool isFinished() { return timeAnimation == 0; };
    void setTimeAnimation(int time) { timeAnimation = time; }
    int getTimeAnimation() { return timeAnimation; }
};

class AnimationGravity : public Animation
{
private:
    AnimationGravity(/* args */) : Animation(){};
    ~AnimationGravity(){};
    std::vector<int> tab;
    std::vector<int> countProfondeur(Game game)
    {
        std::vector<int> tab;
        Grid grid = game.getGrid(game.getCurrentPlayer().getCurrentGrid());
        for (int i = 0; i < grid.getGridHeight(); i++)
        {
            int count = 0;
            for (int j = 0; j < grid.getGridWidth(); j++)
            {
                if (grid.getCase(j, i)->isPiecesEmpty())
                {
                    count++;
                }
            }
            tab.push_back(count);
        }
        return tab;
    }
    void play() override
    {
    }
};

#endif
