#ifndef ANIMATION
#define ANIMATION

class Animation
{
private:
    int timeAnimation;

public:
    Animation(/* args */);
    ~Animation();
    virtual void play();
    bool isFinished();
    void setTimeAnimation(int time);
    int getTimeAnimation();
};

#endif
