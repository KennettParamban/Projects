#ifndef PLAYER_H
#define PLAYER_H
#include <string>

//Kennett Paramban
//NetID: kdp180002

class Player
{
    public:

        Player(std::string team, std::string n){teamType=team; name = n; hits=0; walks=0; strikeouts=0; outs=0; sacrifice=0; errors=0;hitByPitch=0;}
        Player(std::string team, std::string name, int h, int o, int k, int w, int p, int s, int e);

        int getAtBats();//calculates and returns atBats
        double getBattingAvg();//calculates and returns battingAvg
        double getOnBasePercentage(); //calculates and returns onBasePercentage

        void operator+(Player p)//used to add on the stats of Player p to current Node's player
        {
            hits = hits + p.getHits();
            outs = outs + p.getOuts();
            strikeouts = strikeouts + p.getStrikeouts();
            walks = walks + p.getWalks();
            hitByPitch = hitByPitch + p.getHitByPitch();
            sacrifice = sacrifice + p.getSacrifice();

        }

        //used in ListFindInsertionPosition method of class LinkedList
        //compares current player's name with player p's name to see if current name is greater than p's name(eg z>a)
        bool operator<(Player* p)
        {
            std::string thisName = "";
            std::string pName = "";//p->getName();
            for(int i =0; i<static_cast<int>(this->getName().length()); i++)//makes thisName store this player's name but as all uppercase
            {
                thisName+= toupper(this->getName()[i]);
            }
            for(int i =0; i<static_cast<int>(p->getName().length()); i++)//makes pName store player p's name but as all uppercase
            {
                pName+= toupper(p->getName()[i]);
            }

                return(thisName.compare(pName)) <0;//true if thisName comes after pName alphabetically
        }

        //accessors for all variables
        std::string getTeamType() {return teamType;}
        std::string getName(){return name;}
        int getHits(){return hits;}
        int getOuts(){return outs;}
        int getStrikeouts(){return strikeouts;}
        int getWalks(){return walks;}
        int getHitByPitch(){return hitByPitch;}
        int getSacrifice(){return sacrifice;}
        int getErrors(){return errors;}

        //mutators for all variables
        void setTeamType(std::string team) {teamType = team;}
        void setName(std::string n){name =n;}
        void setHits(int h){hits=h;}
        void setOuts(int o){outs=o;}
        void setStrikeouts(int k){strikeouts=k;}
        void setWalks(int w){walks=w;}
        void setHitByPitch(int p){hitByPitch=p;}
        void setSacrifice(int s){sacrifice=s;}
        void setErrors(int e) {errors = e;}
    protected:

    private:
        std::string teamType;
        std::string name;
        int hits;
        int outs;
        int strikeouts;
        int walks;
        int hitByPitch;
        int sacrifice;
        int errors;
};

#endif // PLAYER_H
