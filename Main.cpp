#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "Player.h"

//Kennett Paramban
//NetID: kdp180002
using namespace std;

//finds the top 3 values for batting average and returns them in a vector
vector<double> battingAvgLeader(unordered_map<string, Player*> umap)
{
    double highest = -1;
    double sec_Highest = -1;
    double third_Highest = -1;
    vector<double> winners;

    for(auto x: umap)//traverses the unordered map and records highest batting average
    {
        if(x.second->getBattingAvg() > highest)
            highest = x.second->getBattingAvg();
    }
    winners.push_back(highest);//stores highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    for(auto x: umap)//traverses the unordered map and records the second highest batting average
    {
        if(x.second->getBattingAvg() > sec_Highest && x.second->getBattingAvg()  < highest)
            sec_Highest = x.second->getBattingAvg();
    }
    winners.push_back(sec_Highest);//stores second highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)


    for(auto x: umap)//traverses the unordered map and records the third highest batting average
    {
        if(x.second->getBattingAvg() > third_Highest && x.second->getBattingAvg()  < sec_Highest)
            third_Highest = x.second->getBattingAvg();
    }
    winners.push_back(third_Highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    return winners;
}

//finds the top 3 values for batting average and returns them in a vector
vector<double> onBaseLeader(unordered_map<string, Player*> umap)
{
    double highest = -1;
    double sec_Highest = -1;
    double third_Highest = -1;
    vector<double> winners;

    for(auto x: umap)//traverses the unordered map and records the highest batting average
    {
        if(x.second->getOnBasePercentage() > highest)
            highest = x.second->getOnBasePercentage();
    }
    winners.push_back(highest);//stores highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the second highest batting average
    {
        if(x.second->getOnBasePercentage() > sec_Highest && x.second->getOnBasePercentage()  < highest)
            sec_Highest = x.second->getOnBasePercentage();
    }
    winners.push_back(sec_Highest);//stores second highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the third highest batting average
    {
        if(x.second->getOnBasePercentage() > third_Highest && x.second->getOnBasePercentage()  < sec_Highest)
            third_Highest = x.second->getOnBasePercentage();
    }
    winners.push_back(third_Highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    return winners;
}

vector<int> hitsLeader(unordered_map<string, Player*> umap)
{
    int highest = -1;
    int sec_Highest = -1;
    int third_Highest = -1;
    vector<int> winners;

    for(auto x: umap)//traverses the unordered map and records the highest batting average
    {
        if(x.second->getHits() > highest)
            highest = x.second->getHits();
    }
    winners.push_back(highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the second highest batting average
    {
        if(x.second->getHits() > sec_Highest && x.second->getHits()  < highest)
            sec_Highest = x.second->getHits();
    }
    winners.push_back(sec_Highest);//stores second highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the third highest batting average
    {
        if(x.second->getHits() > third_Highest && x.second->getHits()  < sec_Highest)
            third_Highest = x.second->getHits();
    }
    winners.push_back(third_Highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    return winners;
}

vector<int> walksLeader(unordered_map<string, Player*> umap)
{
    int highest = -1;
    int sec_Highest = -1;
    int third_Highest = -1;
    vector<int> winners;

    for(auto x: umap)//traverses the unordered map and records the highest batting average
    {
        if(x.second->getWalks() > highest)
            highest = x.second->getWalks();
    }
    winners.push_back(highest);//stores highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the second highest batting average
    {
        if(x.second->getWalks() > sec_Highest && x.second->getWalks()  < highest)
            sec_Highest = x.second->getWalks();
    }
    winners.push_back(sec_Highest);//stores second highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the third highest batting average
    {
        if(x.second->getWalks() > third_Highest && x.second->getWalks()  < sec_Highest)
            third_Highest = x.second->getWalks();
    }
    winners.push_back(third_Highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    return winners;
}

///**Note: strikeout leader works so 0 is first place!
vector<int> strikeoutsLeader(unordered_map<string, Player*> umap)
{
    int lowest = 100;
    int sec_Lowest = 100;
    int third_Lowest = 100;
    vector<int> winners;

    for(auto x: umap)//traverses the unordered map and records the lowest batting average
    {
        if(x.second->getWalks() < lowest)
            lowest = x.second->getWalks();
    }
    winners.push_back(lowest);//stores lowest score into winners vector (if there is none defaults to 100, which can't be found as there is no second place)

    for(auto x: umap)//traverses the unordered map and records the second lowest batting average
    {
        if(lowest ==100)//if there was no lowest value then there won't be a second lowest either so exit for loop
            break;
        if(x.second->getWalks() < sec_Lowest && x.second->getWalks() > lowest)
            sec_Lowest = x.second->getWalks();
    }
    winners.push_back(sec_Lowest);//stores second lowest score into winners vector (if there is none defaults to 100, which can't be found as there is no second place)

    for(auto x: umap)//traverses the unordered map and records the third lowest batting average
    {
        if(sec_Lowest ==100)
            break;
        if(x.second->getWalks() < third_Lowest && x.second->getWalks() > sec_Lowest)
            third_Lowest = x.second->getWalks();
    }
    winners.push_back(third_Lowest);//stores third lowest score into winners vector (if there is none defaults to 100, which can't be found as there is no second place)

    return winners;
}

vector<int> hitByPitchLeader(unordered_map<string, Player*> umap)
{
    int highest = -1;
    int sec_Highest = -1;
    int third_Highest = -1;
    vector<int> winners;

    for(auto x: umap)//traverses the unordered map and records the highest batting average
    {
        if(x.second->getHitByPitch() > highest)
            highest = x.second->getHitByPitch();
    }
    winners.push_back(highest);//stores highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the second highest batting average
    {
        if(x.second->getHitByPitch() > sec_Highest && x.second->getHitByPitch()  < highest)
            sec_Highest = x.second->getHitByPitch();
    }
    winners.push_back(sec_Highest);//stores second highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)
    for(auto x: umap)//traverses the unordered map and records the third highest batting average
    {
        if(x.second->getHitByPitch() > third_Highest && x.second->getHitByPitch()  < sec_Highest)
            third_Highest = x.second->getHitByPitch();
    }
    winners.push_back(third_Highest);//stores third highest score into winners vector (if there is none defaults to -1, which can't be found as there is no second place)

    return winners;
}

//returns an unordered list containing keys that are plays and values that are what the play means (eg. play[1-3] = "HITS")
unordered_map<string, string> playMeaning(ifstream& keyfile)
{
    unordered_map<string, string> play;
    string input;
    string word;
    cout<<input;
    if(keyfile)
    {
        while(!keyfile.eof())
        {
            getline(keyfile, input);//store the first line into string input
            if(input[input.length()-1] == '\r')//if there is a \r left in the string due to line being read linux
                input = input.substr(0, input.length()-1);//removes the last character, '\r', from the string

            if(input[0] == '#')//if the line is a new section header (which we know because it starts with a '#' character)
            {
                word ="";
                for(int i =3; i< (int)input.length()-3;i++)// removes "## " from beginnign of input and " ##" from the end
                {
                    word.push_back(input[i]);//read the word for what type of play it was
                }
            }
            else if(input != "")//if not header line and not an empty line
            {
                play[input] = word;//store iput as the key and word as the value in unordered map
            }
        }
    }
    return play;//return unordered map
}

//This function outputs the league leaders
void printLeaders(unordered_map<string, Player*> umap, ofstream& ofile)
{
    vector<string> away;//stores all away team members in alphabetical order
    vector<string> home;//stores all home team members in alphabetical order

    for (auto x : umap)//traverses umap and
    {
        if(umap[x.first]->getTeamType() == "A")// fills away vector with away team member names
            away.push_back(x.first);
        else // fills home vector with away team member names
            home.push_back(x.first);
    }
    sort(away.begin(), away.end());//sorts away vector in alphabetical order
    sort(home.begin(), home.end());//sorts home vector in alphabetical order

    ofile<<endl<<"LEAGUE LEADERS";
    ofile<<endl<<"BATTING AVERAGE"<<endl;
    vector<double> batAvg = battingAvgLeader(umap);//batAvg stores the best 3 batting average scores

    bool first;
    int count =0;

    while(count<3)//loop ends when 3 or more winners have been found
    {
        ofile << std::fixed<<std::setprecision(3) << (double)batAvg.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all "nth" place winners in the away team
        {
            if(first && umap[away[i]]->getBattingAvg() == batAvg.front())
                {
                    ofile<<away[i];//output the first team member with winning score from away team
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getBattingAvg() == batAvg.front())
                {
                    ofile<<", " <<away[i];//output a comma and team members with winning score from away team
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all "nth" place winners in home team
        {
            if(first && umap[home[i]]->getBattingAvg() == batAvg.front())
            {
                ofile<<home[i];//output the first team member with winning score from home team
                first=false;
                count++;
            }
            else if(umap[home[i]]->getBattingAvg() == batAvg.front())
            {
                ofile<<", " <<home[i];//output a comma and team members with winning score from away team
                count++;
            }
        }
        ofile<<endl;
        batAvg.erase(batAvg.begin());
    }

    ///same logic as batting average leaders
    ofile<<endl<<"ON-BASE PERCENTAGE"<<endl;
    vector<double> onBase = onBaseLeader(umap);

    first =true;
    count =0;

    while(count<3)
    {
        ofile << std::fixed<<std::setprecision(3) << (double)onBase.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all 1st place winners in the away team
        {
            if(first && umap[away[i]]->getOnBasePercentage() == onBase.front())
                {
                    ofile<<away[i];
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getOnBasePercentage() == onBase.front())
                {
                    ofile<<", " <<away[i];
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all 1st place winners in home team
        {
            if(first && umap[home[i]]->getOnBasePercentage() == onBase.front())
                {
                    ofile<<home[i];
                    first=false;
                     count++;}
            else if(umap[home[i]]->getOnBasePercentage() == onBase.front())
                {
                    ofile<<", " <<home[i];
                    count++;
                }
        }
        ofile<<endl;
        onBase.erase(onBase.begin());
    }

    ///same logic as batting average leaders
    ofile<<endl<<"HITS"<<endl;
    vector<int> vHits = hitsLeader(umap);

    first =true;
    count =0;


    while(count<3)
    {
        ofile << vHits.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all 1st place winners in the away team
        {
            if(first && umap[away[i]]->getHits() == vHits.front())
                {
                    ofile<<away[i];
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getHits() == vHits.front())
                {
                    ofile<<", " <<away[i];
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all 1st place winners in home team
        {
            if(first && umap[home[i]]->getHits() == vHits.front())
                {
                    ofile<<home[i];
                    first=false;
                     count++;}
            else if(umap[home[i]]->getHits() == vHits.front())
                {
                    ofile<<", " <<home[i];
                    count++;
                }
        }
        ofile<<endl;
        vHits.erase(vHits.begin());
    }

    ///same logic as batting average leaders
    ofile<<endl<<"WALKS"<<endl;
    vector<int> vWalks = walksLeader(umap);

    first =true;
    count =0;

    while(count<3)
    {
        ofile << vWalks.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all 1st place winners in the away team
        {
            if(first && umap[away[i]]->getWalks() == vWalks.front())
                {
                    ofile<<away[i];
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getWalks() == vWalks.front())
                {
                    ofile<<", " <<away[i];
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all 1st place winners in home team
        {
            if(first && umap[home[i]]->getWalks() == vWalks.front())
                {
                    ofile<<home[i];
                    first=false;
                     count++;}
            else if(umap[home[i]]->getWalks() == vWalks.front())
                {
                    ofile<<", " <<home[i];
                    count++;
                }
        }
        ofile<<endl;
        vWalks.erase(vWalks.begin());
    }

    ///same logic as batting average leaders
    ofile<<endl<<"STRIKEOUTS"<<endl;
    vector<int> vStrikeouts = strikeoutsLeader(umap);
    first =true;
    count =0;

    while(count<3)
    {
        ofile << vStrikeouts.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all 1st place winners in the away team
        {
            if(first && umap[away[i]]->getStrikeouts() == vStrikeouts.front())
                {
                    ofile<<away[i];
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getStrikeouts() == vStrikeouts.front())
                {
                    ofile<<", " <<away[i];
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all 1st place winners in home team
        {
            if(first && umap[home[i]]->getStrikeouts() == vStrikeouts.front())
                {
                    ofile<<home[i];
                    first=false;
                     count++;
                }
            else if(umap[home[i]]->getStrikeouts() == vStrikeouts.front())
                {
                    ofile<<", " <<home[i];
                    count++;
                }
        }
        ofile<<endl;
        vStrikeouts.erase(vStrikeouts.begin());
    }

    ///same logic as batting average leaders
    ofile<<endl<<"HIT BY PITCH"<<endl;
    vector<int> vPitch = hitByPitchLeader(umap);

    first =true;
    count =0;

    while(count<3)
    {
        ofile << vPitch.front() <<"\t";
        first = true;
        for(int i =0; i< (int)away.size();i++)//first for loop to find all 1st place winners in the away team
        {
            if(first && umap[away[i]]->getHitByPitch() == vPitch.front())
                {
                    ofile<<away[i];
                    first=false;
                    count++;
                }
            else if(umap[away[i]]->getHitByPitch() == vPitch.front())
                {
                    ofile<<", " <<away[i];
                    count++;
                }
        }
        for(int i =0; i< (int)home.size();i++)//second for loop to find all 1st place winners in home team
        {
            if(first && umap[home[i]]->getHitByPitch() == vPitch.front())
                {
                    ofile<<home[i];
                    first=false;
                     count++;}
            else if(umap[home[i]]->getHitByPitch() == vPitch.front())
                {
                    ofile<<", " <<home[i];
                    count++;
                }
        }
        ofile<<endl;
        vPitch.erase(vPitch.begin());
    }
    ofile<<endl;
}


int main()
{
    unordered_map<string, Player*> umap;
    string inputFile= "";
    cin>>inputFile;

    ifstream infile(inputFile);
    ifstream keyfile("keyfile.txt");

    unordered_map<string, string> play = playMeaning(keyfile);//stores an unordered map with keys being the play and values being OUTS, HITS, etc.
    keyfile.close();

    if(infile) //checks if file opened properly
    {
        while(!infile.eof())
        {
            string teamType;
            string name;

            getline(infile, teamType, ' ');// used to store the 'A' or 'H' char from input
            getline(infile, name, ' ');
            if(name == "") //if empty line, loop ends and rest of program executes the output for the batters up until this line
                break;

            string batRecord;
            getline(infile, batRecord);//stores  the list of letters into string batRecord

            if(umap.find(name) == umap.end())//if the player isn't already in umap, add player to umap
                umap[name] = new Player(teamType, name/*, hits, outs, strikeouts, walks, hitByPitch, sacrifice, errors*/);

            if(batRecord[batRecord.length()-1] == '\r')
                batRecord = batRecord.substr(0, batRecord.length()-1);
            if(play[batRecord] == "OUTS")//if the play was an out
            {
                umap[name]->setOuts(umap[name]->getOuts() + 1);
            }
            else if(play[batRecord] == "HITS")//if the play was hit
            {
                umap[name]->setHits(umap[name]->getHits() + 1);
            }
            else if(play[batRecord] == "STRIKEOUT")//if the play was strikeout
            {
                umap[name]->setStrikeouts(umap[name]->getStrikeouts() + 1);
            }
            else if(play[batRecord] == "WALK")//if the play was a walk
            {
                umap[name]->setWalks(umap[name]->getWalks() + 1);
            }
            else if(play[batRecord] == "SACRIFICE")//if the play was a sacrifice
            {
                umap[name]->setSacrifice(umap[name]->getSacrifice() + 1);
            }
            else if(play[batRecord] == "HIT BY PITCH")//if the play was a hit by pitch
            {
                umap[name]->setHitByPitch(umap[name]->getHitByPitch() + 1);
            }
            else if(play[batRecord] == "ERRORS")//if the play was an error
            {
                umap[name]->setErrors(umap[name]->getErrors() + 1);
            }

        }
    }
    infile.close();
    vector<string> away;//a vector made with the purpose of storing the names of the away team members (as strings)
    vector<string> home;//a vector made with the purpose of storing the names of the home team members (as strings)

    for (auto x : umap)//an enhanced for loop to traverse the umap using an Iterator x
    {
        if(x.second->getTeamType() == "A")//if the current player is an away team member
        {
            away.push_back(x.first);//add the current player to the away vector
        }
        else //otherwise if the current player is a home team member
        {
            home.push_back(x.first);//add the current player to the away vector
        }
    }
    sort(away.begin(), away.end());//sort the team members of the away team in alphabetical order
    sort(home.begin(), home.end());//sort the team members of the away team in alphabetical order

    ofstream ofile("leaders.txt");//where we want to send the output to

    ofile<<"AWAY"<<endl;
    while(!away.empty())
    {//we extract the info from the players on away team once players are sorted
        Player* temp = umap[away.front()];
        away.erase(away.begin());//this removes the head of the vector so that on second iteration of while loop we move to next player

        //outputs each away team player's name followed by that player's stats with a tab between each stat
        ofile<< temp->getName()<<"\t";
        ofile << temp->getAtBats() << "\t";
        ofile << temp->getHits() << "\t";
        ofile << temp->getWalks() << "\t";
        ofile << temp->getStrikeouts() << "\t";
        ofile << temp->getHitByPitch() << "\t";
        ofile << temp->getSacrifice() << "\t";
        ofile << std::fixed<<std::setprecision(3)<< temp->getBattingAvg()<<"\t";
        ofile << std::fixed<<std::setprecision(3)<< temp->getOnBasePercentage()<<endl;
    }
    ofile<<endl<<"HOME"<<endl;
    while(!home.empty())
    {//we extract the info from the players on home team once players are sorted
        Player* temp = umap[home.front()];
        home.erase(home.begin());//this sets up the head of the vector as the next name until vector is empty

        //outputs each home team player's name followed by that player's stats with a tab between each stat
        ofile<< temp->getName()<<"\t";
        ofile << temp->getAtBats() << "\t";
        ofile << temp->getHits() << "\t";
        ofile << temp->getWalks() << "\t";
        ofile << temp->getStrikeouts() << "\t";
        ofile << temp->getHitByPitch() << "\t";
        ofile << temp->getSacrifice() << "\t";
        ofile << std::fixed<<std::setprecision(3)<< temp->getBattingAvg()<<"\t";
        ofile << std::fixed<<std::setprecision(3)<< temp->getOnBasePercentage()<<endl;
    }

    //calls the printLeaders function which outputs the league leaders into ofile
    printLeaders(umap, ofile);

    ofile.close();
    return 0;
}
