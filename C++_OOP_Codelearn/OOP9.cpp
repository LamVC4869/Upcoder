#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Score {
    private:
    double math;
    double literature;
    double english;
    public:
    Score () {}
    Score (double math, double literature, double english) {
        this->math = math;
        this->literature = literature;
        this->english = english;
    }
    double getMath () {
        return math;
    }
    double getLiterature () {
        return literature;
    }
    double getEnglish () {
        return english;
    }
    virtual double pointA () = 0;
    virtual double pointB () = 0;
    virtual double pointC () = 0;
    virtual double pointD () {
        return math + literature + english;
    }
    virtual double avgPoint () = 0;
    static double getMaxAvg (vector<Score*> vt) {
        double max = vt[0]->avgPoint ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->avgPoint () > max) max = vt[i]->avgPoint ();
        return max;
    }
    static double getMinAvg (vector<Score*> vt) {
        double min = vt[0]->avgPoint ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->avgPoint () < min) min = vt[i]->avgPoint ();
        return min;
    }
    bool isPass () {
        return avgPoint () > 5;
    }
    static double getMaxPointA (vector<Score*> vt) {
        double max = vt[0]->pointA ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->pointA () > max) max = vt[i]->pointA ();
        return max;
    }
    static double getMaxPointB (vector<Score*> vt) {
        double max = vt[0]->pointB ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->pointB () > max) max = vt[i]->pointB ();
        return max;
    }
    static double getMaxPointC (vector<Score*> vt) {
        double max = vt[0]->pointC ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->pointC () > max) max = vt[i]->pointC ();
        return max;
    }
    static double getMaxPointD (vector<Score*> vt) {
        double max = vt[0]->pointD ();
        for (int i = 1; i < vt.size (); i++) if (vt[i]->pointD () > max) max = vt[i]->pointD ();
        return max;
    }
};

class ScoreNatural : public Score {
    private:
    double physic;
    double chemistry;
    double biology;
    public:
    ScoreNatural () {}
    ScoreNatural (double math, double literature, double english, double physic, double chemistry, double biology) : Score (math, literature, english) {
        this->physic = physic;
        this->chemistry = chemistry;
        this->biology = biology;
    }
    double getPhysic () {
        return physic;
    }
    double getChemistry () {
        return chemistry;
    }
    double getBiology () {
        return biology;
    }
    double pointA () {
        return getMath () + physic + chemistry;
    }
    double pointB () {
        return getMath () + chemistry + biology;
    }
    double pointNatural () {
        return physic + chemistry + biology;
    }
    double avgPoint () {
        return (getMath () + getLiterature () + getEnglish () + physic + chemistry + biology) / 6;
    }
};

class ScoreSocial : public Score {
    private:
    double ce;
    double geography;
    double history;
    public:
    ScoreSocial () {}
    ScoreSocial (double math, double literature, double english, double ce, double geography, double history) : Score (math, literature, english) {
        this->ce = ce;
        this->geography = geography;
        this->history = history;
    }
    double getCe () {
        return ce;
    }
    double getGeography () {
        return geography;
    }
    double getHistory () {
        return history;
    }
    double pointC () {
        return getLiterature () + history + geography;
    }
    double pointNatural () {
        return ce + geography + history;
    }
    double avgPoint () {
        return (getMath () + getLiterature () + getEnglish () + ce + geography + history) / 6;
    }
};