#include <iostream>
#include <random>
using namespace std;

int randomNumber(){
	random_device rd;
	
	mt19937 gen(rd());
	
	uniform_int_distribution<> distrib(1,100);
	
	int num=distrib(gen);
	
	return num; 
}

void Game2(int num, int guesser,int guess);

void Game1(int num, int guesser,int guess){
	
	cout<<"Enter your guess player number "<<guesser<<" : ";
	cin>>guess;	
	

	
	if(guess==num){
		cout<<"You guess the "<<num<<" correct"<<endl;
		return;
	}
	else if(guess>num){
		cout<<"Your guess is too high "<<endl;
	}
	else{
		cout<<"Your guess is too low "<<endl;
	}

	
	Game2(num,(guesser % 2) + 1,guess);
}

void Game2(int num, int guesser,int guess){
	
	
	
	cout<<"Enter your guess player number: "<<guesser<<" : ";
	cin>>guess;	
	

	
	if(guess==num){
		cout<<"You guess the "<<num<<" correct"<<endl;
		return;
	}
	else if(guess>num){
		cout<<"Your guess is too high "<<endl;
	}
	else{
		cout<<"Your guess is too low "<<endl;
	}

	
	Game1(num,(guesser % 2) + 1,guess);
}



int main(){
	
	int num=randomNumber();
	int guesser=1;
	// consider two players
	cout<<"Welcome To Number Guessing Game from 1 to 100"<<endl;
	int guess=0;
	Game1(num,guesser,guess);
	
	return 0;
}