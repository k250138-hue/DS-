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

void Game(int num, int guesser){
	
	int guess=0;
	
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

	
	Game(num,(guesser % 2) + 1);
}

int main(){
	
	int num=randomNumber();
	int guesser=1;
	
	cout<<"___Welcome To Number Guessing Game from 1 to 100___"<<endl;
	Game(num,guesser);
	
	return 0;
}