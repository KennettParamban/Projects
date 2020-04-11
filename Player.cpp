#include "Player.h"

//Kennett Paramban
//NetID: kdp180002

//calculates and returns atBats
int Player::getAtBats()
{
    return (hits+outs+strikeouts);
}

//calculates and returns battingAvg
double Player::getBattingAvg()
{   //if denominator is 0, then return 0, else return proper value
    if(getAtBats()==0)
        return 0;
    return ((static_cast<double>(hits))/getAtBats());
}

//calculates and returns onBasePercentage
double Player::getOnBasePercentage()
{   //if denominator is 0, then return 0, else return proper value
    if(hits +outs +strikeouts +walks +hitByPitch +sacrifice ==0)
        return 0;

    return static_cast<double>(hits +walks +hitByPitch)/(hits +outs +strikeouts +walks +hitByPitch +sacrifice + errors);
}

//constructor that initializes the name and each stat of Player to respective parameter
Player::Player(std::string team, std::string n, int h, int o, int k, int w, int p, int s, int e)
{
    teamType = team;
    name = n;
    hits = h;
    outs = o;
    strikeouts = k;
    walks = w;
    hitByPitch = p;
    sacrifice = s;
    errors = e;
}
