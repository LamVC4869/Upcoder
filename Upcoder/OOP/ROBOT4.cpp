#include <iostream>
#include <vector>

using namespace std;

class Robot {
    private:
    string name;
    string UserName;
    int EnergyLevel;
    int LocationX;
    int LocationY;
    public:
    Robot () : name("Robot"), UserName("NoName"), EnergyLevel(100), LocationX(0), LocationY(0) {}
    Robot (string name, string UserName) : name(name), UserName(UserName), EnergyLevel(100), LocationX(0), LocationY(0) {}
    Robot (string name, string UserName, int EnergyLevel, int LocationX, int LocationY) : name(name), UserName(UserName), EnergyLevel(EnergyLevel), LocationX(LocationX), LocationY(LocationY) {}
    Robot (const Robot& robot) {
        this->name = robot.name;
        this->UserName = robot.UserName;
        this->EnergyLevel = robot.EnergyLevel;
        this->LocationX = robot.LocationX;
        this->LocationY = robot.LocationY;
    }
    void setName (string name) {
        this->name = name;
    }
    void setUserName (string UserName) {
        this->UserName = UserName;
    }
    void setEnergyLevel (int EnergyLevel) {
        this->EnergyLevel = EnergyLevel;
    }
    void setLocationX (int LocationX) {
        this->LocationX = LocationX;
    }
    void setLocationY (int LocationY) {
        this->LocationY = LocationY;
    }
    string getName () {
        return name;
    }
    string getUserName () {
        return UserName;
    }
    int getEnergyLevel () {
        return EnergyLevel;
    }
    int getLocationX () {
        return LocationX;
    }
    int getLocationY () {
        return LocationY;
    }
    void Charge () {
        this->EnergyLevel += 10;
    }
    void UnCharge (int index) {
        this->EnergyLevel -= index;
    }
    virtual bool Move (int direction) {
        if (this->EnergyLevel <= 0 || direction < 0 || direction > 3) return false;
        else {
            switch (direction) {
                case 0: this->LocationX--; break;
                case 1: this->LocationX++; break;
                case 2: this->LocationY++; break;
                default: this->LocationY--;
            }
            return true;
        }
    }
    virtual void Display () {
        cout << "{" << this->name << "}:" << "{" << this->UserName << "}" << endl;
        cout << "(" << this->LocationX << ',' << this->LocationY << ")" << endl;
        cout << this->EnergyLevel << endl;
    }
};

class AdaptiveRobot : public Robot {
    public:
    AdaptiveRobot () : Robot () {}
    AdaptiveRobot (string name, string UserName) : Robot (name, UserName) {}
    AdaptiveRobot (string name, string UserName, int EnergyLevel, int LocationX, int LocationY) : Robot (name, UserName, EnergyLevel, LocationX, LocationY) {}
    AdaptiveRobot (const AdaptiveRobot& robot) : Robot (robot) {}
    bool Move (int direction) {
        if (Robot::getEnergyLevel () <= 0 || direction < 0 || direction > 3) return false;
        else {
            switch (direction) {
                case 0: Robot::setLocationX(Robot::getLocationX() - 1); break;
                case 1: Robot::setLocationX(Robot::getLocationX() + 1); break;
                case 2: Robot::setLocationY(Robot::getLocationY() + 1); break;
                default: Robot::setLocationY(Robot::getLocationY() - 1);
                }
            return true;
        }
    }
    void Display () {
        Robot::Display ();
    }
};

int main () {
    int n; cin >> n;
    cin.ignore ();
    vector<Robot*> v;
    for (int i = 0; i < n; i++) {
        string name, UserName;
        int EnergyLevel, LocationX, LocationY;
        getline (cin, name);
        getline (cin, UserName);
        cin >> EnergyLevel >> LocationX >> LocationY;
        if (name[0] == 'A') {
            AdaptiveRobot* a = new AdaptiveRobot (name, UserName, EnergyLevel, LocationX, LocationY);
            v.push_back (a);
        } else {
            Robot* r = new Robot (name, UserName, EnergyLevel, LocationX, LocationY);
            v.push_back (r);
        }
        int direction;
        vector<int> dir;
        while (cin >> direction) {
            if (direction == -1) break;
            dir.push_back (direction);
        }
        for (int j = 0; j < dir.size (); j++) {
            if (dir[j] == 4) {
                v[i]->Charge();
            }
            else {
                v[i]->Move(dir[j]);
                if (v[i]->getName()[0] != 'A') {
                    v[i]->UnCharge (5);
                } else {
                    if (v[i]->getEnergyLevel () > 50) {
                        v[i]->Move(dir[j + 1]);
                        v[i]->Move(dir[j + 2]);
                        v[i]->UnCharge (12);
                        j += 2;
                    } else if (v[i]->getEnergyLevel () > 20) {
                        v[i]->Move(dir[j + 1]);
                        v[i]->UnCharge (9);
                        j++;
                    } else {
                        v[i]->UnCharge (6);
                    }
                }
            }
        }
        cin.ignore ();
    }
    for (int i = 0; i < n; i++) {
        v[i]->Display ();
        delete v[i];
    }
    return 0;
}