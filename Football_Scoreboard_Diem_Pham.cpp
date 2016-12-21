//Football score board created by Diem Pham

#include <iostream>
#include <string>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <csignal>


using namespace std;
class ScoreBoard;
void TeamInfo();
void DisplayBoard();
void Start();
void Update(int);
void Watch();
int validInteger();
int validDownQuarter();
int validScore();
int validToGo();

class Team {
	//Team attributes
private:
	string name;
	string coach_name;
	string home_city;
	bool home_status;
	int score;
	int timeout_count;

	//Team behaviors
public:

	string getName();
	string getCoachName();
	string getHomeCity();
	bool getHomeStatus();
	int getScore();
	int getTimeoutCount();

	void setName(string n);
	void setCoachName(string cn);
	void setHomeCity(string hc);
	void setHomeStatus(bool st);
	void setScore(int s);
	void setTimeoutCount(int t);
	void setAllZero();

};

string Team::getName() {
	return name;
}

string Team::getCoachName(){
	return coach_name;
}

string Team::getHomeCity(){
	return home_city;
}

bool Team::getHomeStatus(){
	return home_status;
}

int Team::getScore(){
	return score;
}

int Team::getTimeoutCount(){
	return timeout_count;
}

void Team::setAllZero(){
	score = 0;
	timeout_count = 0;
}

void Team::setName(string n){
	name = n;
}
void Team::setCoachName(string cn){
	coach_name = cn;
}
void Team::setHomeCity(string hc){
	home_city = hc;
}
void Team::setHomeStatus(bool st){
	home_status = st;		
}
void Team::setScore(int s){
	score = s;
}
void Team::setTimeoutCount(int t){
	timeout_count = t;
}






class ScoreBoard {
	//Team attributes
public: 
	int quarter;
	int toGo;
	int down;
	Team T1;
	Team T2;

	//Team behaviors
public:
	int getQuarter();
	int getToGo();
	int getDown();

	void setQuarter(int q);
	void setToGo(int tg);
	void setDown(int d);

};


int ScoreBoard::getQuarter() {
	return quarter;
}

int ScoreBoard::getToGo(){
	return toGo;
}

int ScoreBoard::getDown(){
	return down;
}

void ScoreBoard::setQuarter(int q){
	quarter = q;
}
void ScoreBoard::setToGo(int tg) {
	toGo = tg;
}
void ScoreBoard::setDown(int d) {
	down = d;
}



	














//Team T1;
//Team T2;
ScoreBoard SB;
string name;
string coach_name;
string home_city;
string input;
string homeTeam;
string visitor;
int homeScore;
int visitorScore;
int down;
int quarter;
int toGo;
int mins;
int secs;
int t;
int status;
int value;
int offense;

int main(){
	TeamInfo();
	DisplayBoard();
	cout << "Enter to start the game!" << endl;
	cin.ignore().get();
	system("CLEAR");
	Start();

	do {
		signal(SIGINT, Update);

	   	while(1) {
	      Watch();
	   	}
	   	return EXIT_SUCCESS;
	
	} while (input == "hs" || input == "vs" || input =="d" || input == "tg");
	
	
	
return 0;
}

void TeamInfo() {
	cout << "Please submit Team 1's info: " << endl;
	cout << "Name: ";
	cin >> name;
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	SB.T1.setName(name);
	
	cout << "Coach Name: ";
	cin >> coach_name;
	SB.T1.setCoachName(coach_name);

	cout << "Home City: ";
	cin >> home_city;
	SB.T1.setHomeCity(home_city);

	cout << "Please submit Team 2's info: " << endl;
	cout << "Name: ";
	cin >> name;
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	SB.T2.setName(name);
	
	cout << "Coach Name: ";
	cin >> coach_name;
	SB.T2.setCoachName(coach_name);

	cout << "Home City: ";
	cin >> home_city;
	SB.T2.setHomeCity(home_city);

	cout << "What team is home team? " << endl;
	cout << "Type 1 to choose Team 1. Type 2 to choose Team 2 ";
	status = validInteger();		

	if (status == 1) {
		SB.T1.setHomeStatus(1);
		SB.T2.setHomeStatus(0);
		homeTeam = SB.T1.getName();
		visitor = SB.T2.getName();
		homeScore = SB.T1.getScore();
		visitorScore = SB.T2.getScore();
	} else if (status == 2) {
		SB.T1.setHomeStatus(0);
		SB.T2.setHomeStatus(1);
		homeTeam = SB.T2.getName();
		visitor = SB.T1.getName();
		homeScore = SB.T2.getScore();
		visitorScore = SB.T1.getScore();
	}
}

int validInteger()
{
    int x;
    std::cin >> x;
    while(std::cin.fail() || x > 2) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

int validDownQuarter()
{
    int x;
    std::cin >> x;
    while(std::cin.fail() || x > 4) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

int validToGo()
{
    int x;
    std::cin >> x;
    while(std::cin.fail() || x > 10) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

int validScore()
{
    int x;
    std::cin >> x;
    while(std::cin.fail() || x > 6) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Your value is invalid. Re-enter your value: ";
        std::cin >> x;
    }
    return x;
}

void DisplayBoard(){
	cout << "\t\t\033[1;31m HOME" << "\t\t\t\t\t\tVISITOR\033[0m" << endl;
	cout << "\t\t\033[1;35m" << homeTeam << "\t\t\t\t\t\t" << visitor << "\033[0m" <<endl;
	cout << "\t\t" << homeScore << "\t\t\t\t\t\t" << visitorScore << endl;
	cout << "\t\t\t\033[1;33mDOWN" << "\t\tQTR" << "\t\tTO GO\033[0m" << endl;
	cout << "\t\t\t" << SB.getDown() << "\t\t" << SB.getQuarter() << "\t\t" << SB.getToGo() << endl;
	
}

void Start() {
	SB.setQuarter(1);
	SB.setDown(1);
	SB.setToGo(10);
}


void Update(int u) {
	do {
		cout << "\nType command to update the score board. " << endl;
		cout << "hs: Home Score" << endl;
		cout << "vs: Visistor Score" << endl;
		cout << "d: Down" << endl;
		cout << "qt: QTR" << endl;
		cout << "tg: To Go" << endl;
		cout << "done: done editing the score board. Resume the game." << endl;

		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input == "hs") {
			cout << "The " << homeTeam << " gains ... points ";
			value = validScore();
			homeScore += value;
		} else if (input == "vs") {
			cout << "The " << visitor << " gains ... points ";
			value = validScore();
			visitorScore += value;
		} else if (input == "d") {
			cout << "This is ...th down ";
			value = validDownQuarter();
			SB.setDown(value);
		} else if (input == "qt"){
			cout << "This is ...th quarter ";
			value = validDownQuarter();
			SB.setQuarter(value);
		}
		else if (input == "tg") {
			cout << " ... yards to go ";
			value = validToGo();
			SB.setToGo(value);
		} else if (input == "done"){
			break;
		}
	} while (input == "hs" || input == "vs" || input =="d" || input == "tg");
	
}

void Watch() { 
	for (int i = 900; i > 0; i--) {
		system("CLEAR");
	cout << "\t\t\t\t\t\033[1;34m" << i/60 << " : " << i % 60 << "\033[0m" << endl; 
	DisplayBoard(); 
	cout << " CTRL + C: pause the game and edit the score board." << endl;	
	this_thread::sleep_for (std::chrono::seconds(1));
	}  	
}







