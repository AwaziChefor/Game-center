#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
void instructions(int n)
{
	cout<<"In this game, for every unmatch in value, you will lose 1 coin\n";
	cout<<"And for any win in value, you gain 5 coins\n";
	cout<<"\nHere are the rules:\n";
	cout<<"In this game , you have to select 6 numbers from a 1-"<<n<<" the computer too selects its own numbers\n";
	cout<<"If all your values matches with that of the computer, You win\n";
}
//Function that Generates random numbers for the jackpot
void Gnumber(int Cnumber[6],int n)
{
	int i;
	srand(time(0));
	for(i=0; i<6; i++) {
		Cnumber[i]=(rand()%n)+1;
	}
	//displays jackpot values
	cout<<"\nTHE JACKPOT NUMBERS ARE:";
	for(i=0; i<6; i++) {
		printf("%d-",Cnumber[i]);
	}
}
//Function that allows user to enter its values for the jackpot
void Unumber(int user[6],int n)
{
	cout<<"CANDIDATE, ENTER YOUR VALUES:\n";
	int i;
	for(i=0; i<6; i++) {
		cin>>user[i];
		if(user[i]<1 || user[i]>n) {
			cout<<"RESPECT THE RANGE OF NUMBERS 1-"<<n;
			exit(1);
		}
	}
	cout<<"Your values are:";
	for(i=0; i<6; i++) {
		printf("%d-",user[i]);
	}
}
//Function to determine the winner for the jackpot
void decision(int Cnumber[6],int user[6],int coins)
{
	int i;
	for(i=0; i<6; i++) {
		if(Cnumber[i]==user[i]) {
			printf("\nCONGRATULATIONS, YOUR %dth value is correct\n",i+1);
			coins+=5;
		} else if (Cnumber[i]!=user[i]) {
			printf("\nSORRY BRO, %dth value does not match\n",i+1);
			coins-=1;
		}
	}
	// If all the values matches, the user wins a lot of money
	if(Cnumber[0]==user[0] && Cnumber[1]==user[1] && Cnumber[2]==user[2] && Cnumber[3]==user[3] && Cnumber[4]==user[4] && Cnumber[5]==user[5]) {
		printf("\n\nCONGRATULATIONS, YOU HAVE WON THE JACKPOT. YOU THEREBY WIN 5 MILLION DOLLARS\n");
		coins+=60;
		printf("You have %d coins left\n",coins);
	} else {
		printf("YOU ARE FREE TO RETRY BOY\n");
		if (coins<=0) {
			printf("You are out of coins\n");
			printf("\nI TOLD YOU THIS GAME WAS DIFFICULT\n");
			exit(1);
		}
		cout<<"Do you want to retry?\n";
		cout<<"1-Yes\n";
		cout<<"2-No\n";
		if (coins<=0) {
			printf("You are out of coins\n");

			exit(1);
		}
		int c;
		cin>>c;
		switch(c) {
			case 1: {
				cout<<"\t\t\t WELCOME BACK TO THE CASINO'S JACKPOT \t\t\t\n";
				printf("You have %d coins left\n",coins);
				srand(time(0));
				int Cnumber[6],user[6],n=(rand()%100)+1;
				instructions(n);
				Unumber(user,n);
				Gnumber(Cnumber,n);
				decision(Cnumber,user,coins);
				break;
			}
			case 2: {
				printf("THANKS FOR PLAYING\n");
				exit(1);
				break;
			}
			default: {
				printf("ERROR , PLEASE RESTART THE GAME\n");
				exit(1);
				break;
			}
		}
	}
}
void jackpot(int coins) //fuction for jackpot game
{
	cout<<"\t\t\t WELCOME TO THE CASINO'S JACKPOT \t\t\t\n";
	srand(time(0));
	int Cnumber[6],user[6],n=(rand()%100)+1;
	instructions(n);
	Unumber(user,n);
	Gnumber(Cnumber,n);
	decision(Cnumber,user,coins);
}
void choice(int a,int b,int& coins)
{
	if(a==b) {
		cout<<"IT IS A TIE\n";
		coins+=1;
		printf("You have %d coins left\n");
	}

	else if (b==1 && a==2 || b==2 && a==3 || b==3 && a==1) {
		cout<<"COMPUTER HAS WON,SORRY GUY!\n";
		coins-=5;
		printf("You have %d coins left\n");
	}

	else if (b==1 && a==3 || b==2 && a==1 || b==3 && a==2) {
		cout<<"CONGRATULATIONS,YOU HAVE WON\n";
		coins+=5;
		printf("You have %d coins left\n");
	}

}
void numberguess(int coins)
{
	printf("\t\t WELCOME BACK TO NUMBER GUESS\t\t\n");
	printf("TRY YOUR LUCK AND GET THE HIDDEN NUMBER\n");
	srand(time(0));
	int n=(rand()%100)+1,i;
	do {
		printf("Enter your number:\n");
		scanf("%d",&i);
		if(i<n) {
			printf("This is not correct, Enter a bigger number\n");
		} else if (i>n) {
			printf("This is not correct, Enter a smaller number\n");
			coins-=1;
			if(coins==0) {
				printf("You are ouut of coins\n");
				printf("GOOD BYE\n");
				exit(1);
			}
		}
	} while(i!=n);
	if(i==n) {
		printf("CONGRATULATIONS YOU GOT THE NUMBER\n");
		coins+=10;
		printf("You have %d coins left\n",coins);
		printf("DO YOU WANT TO REPLAY?\n");
		int a;
		printf("1-YES\n");
		printf("2-NO\n");
		scanf("%d",&a);
		if(a==1) {
			numberguess(coins);
		} else {
			printf("THANKS FOR PLAYING THIS GAME\n");
			printf("Do you want to go back to menu?\n");
			printf("1-YES\n");
			printf("2-NO\n");
			cin>>a;
			if(a==1) {
				printf("OPTION IS NOT YET AVAILABLE\n");
			} else {
				printf("THANKS FOR PLAYING GAME CENTER\n");
				printf("You have %d coins left\n",coins);
				exit(1);
			}
			exit(1);
		}
	}
}
void rockpaperscissors(int coins)
{
	//Display of game menu
	cout<<"\t\t\t WELCOME BACK TO THE ROCK-PAPER-SCISSOR GAME\t\t\t\n";
	cout<<"REMEMBER\n";
	cout<<"Here, when you win, you gain 5 coins\n";
	cout<<"Here, when you lose, you lose 5 coins\n";
	cout<<"And when you and the computer have a tie, you gain 1 coin for encouragements\n";
	cout<<"\n1-ROCK\n";
	cout<<"2-PAPER\n";
	cout<<"3-SCISSORS\n";
	int b;
	// User enters their choice
	cout<<"Enter your choice now:\n";
	cin>>b;
	//Condition if a user inputs a number out of the range
	while(b<1 || b>3) {
		cout<<"ERROR IN INPUT\n";
		cout<<"ENTER NUMBER WITHIN RANGE NOW:";
		cin>>b;
	}
	if(b==1) {
		cout<<"You chose ROCK\n";
	} else if(b==2) {
		cout<<"You chose PAPER\n";
	} else if(b==3) {
		cout<<"You chose SCISSORS\n";
	}


	//Computer chooses its value
	int a;
	srand(time(0));
	a=(rand()%3)+1;
	cout<<"COMPUTER CHOSE:\n"<<a<<endl;
	if(a==1) {
		cout<<"Computer chose ROCK\n";
	} else if(a==2) {
		cout<<"Computer chose PAPER\n";
	} else {
		cout<<"Computer chose SCISSORS\n";
	}
//Game section where the computer chooses who wins the game

	choice(a,b,coins);
	printf("\nDO YOU WANT TO REPLAY?\n");
	printf("1-YES\n");
	printf("2-NO\n");
	scanf("%d",&a);
	if(a==1) {
		printf("You have %d coins left\n",coins);
		if (coins==0) {
			printf("You are out of coins\n");
			exit(1);
		}
		rockpaperscissors(coins);
	} else {
		printf("THANKS FOR PLAYING \n");
		exit(1);
	}
}

int main()
{
	cout<<"\t\t\t\t GAME CENTER \t\t\t\t\n";
	cout<<"This games allows you to win various prices in terms of coins, When you lose a game,You lose coins depending on the games\n";
	int coins=10;
	cout<<"You now have:"<<coins<<" coins\n";
	cout<<"Once your coins are finished, you cannot play again\n";
	cout<<"\nWhich game do you want to play?\n";
	int i,a;
	cout<<"1-NUMBER GUESS\n";
	cout<<"2-ROCK-PAPER-SCISSOR GAME\n";
	cout<<"3-JACKPOT GAME, you can never win!\n";
	cout<<"4-EXIT\n";
	cout<<"Select between these alternatives\n";
	cin>>i;
	switch(i) {
		case 1: {
			printf("\t\t WELCOME TO THE NUMBER GUESS\t\t\n");
			printf("TRY YOUR LUCK AND GET THE HIDDEN NUMBER\n");
			srand(time(0));
			int n=(rand()%100)+1,i;
			do {
				printf("Enter your number:\n");
				scanf("%d",&i);
				if(i<n) {
					printf("This is not correct, Enter a bigger number\n");
				} else if (i>n) {
					printf("This is not correct, Enter a smaller number\n");
				}
				coins-=1;
				if(coins==0) {
					printf("You are out of coins\n");
					printf("The right number was %d\n",n);
					printf("GOOD BYE\n");
					exit(1);
				}
			} while(i!=n);
			if(i=n) {
				printf("CONGRATULATIONS YOU GOT THE NUMBER\n");
				coins+=10;
				printf("You have %d coins left\n",coins);
				printf("DO YOU WANT TO REPLAY?\n");
				printf("1-YES\n");
				printf("2-NO\n");
				scanf("%d",&a);
				if(a==1) {
					numberguess(coins);
					printf("You have %d coins left\n",coins);
				} else {
					printf("THANKS FOR PLAYING THIS GAME\n");
					printf("Do you want to go back to menu?\n");
					printf("1-YES\n");
					printf("2-NO\n");
					cin>>a;
					if(a==1) {
						main();
					} else {
						printf("THANKS FOR PLAYING GAME CENTER\n");
						printf("You have %d coins left\n",coins);
						exit(1);
					}
				}
				break;
			}
		}
		case 2: {
			//Display of game menu
			cout<<"\t\t\t WELCOME TO THE ROCK-PAPER-SCISSOR GAME\t\t\t\n";
			cout<<"Here, when you win, you gain 5 coins\n";
			cout<<"Here, when you lose, you lose 5 coins\n";
			cout<<"And when you and the computer have a tie, you gain 1 coin for encouragements\n";
			cout<<"\n1-ROCK\n";
			cout<<"2-PAPER\n";
			cout<<"3-SCISSORS\n";
			int b;
			// User enters their choice
			cout<<"Enter your choice now:\n";
			cin>>b;
			//Condition if a user inputs a number out of the range
			while(b<1 || b>3) {
				cout<<"ERROR IN INPUT\n";
				cout<<"ENTER NUMBER WITHIN RANGE NOW:";
				cin>>b;
			}
			if(b==1) {
				cout<<"You chose ROCK\n";
			} else if(b==2) {
				cout<<"You chose PAPER\n";
			} else if(b==3) {
				cout<<"You chose SCISSORS\n";
			}


			//Computer chooses its value
			int a;
			srand(time(0));
			a=(rand()%3)+1;
			cout<<"COMPUTER CHOSE:\n"<<a<<endl;
			if(a==1) {
				cout<<"Computer chose ROCK\n";
			} else if(a==2) {
				cout<<"Computer chose PAPER\n";
			} else {
				cout<<"Computer chose SCISSORS\n";
			}
//Game section where the computer chooses who wins the game

			choice(a,b,coins);
			printf("\nDO YOU WANT TO REPLAY?\n");
			printf("1-YES\n");
			printf("2-NO\n");
			scanf("%d",&a);
			if(a==1) {
				rockpaperscissors(coins);
			} else {
				printf("THANKS FOR PLAYING \n");
				printf("Do you want to go back to the menu?\n");
					printf("1-YES\n");
				printf("2-NO\n");
				scanf("%d",&a);
					if(a==1) {
			main();}
			else{
				printf("THANKS FOR USING GAME CENTER\n");
			}
				exit(1);
			}
			break;
		}
		case 3: {
			jackpot(coins);
			break;
		}
		case 4: {
			printf("YOU ARE NOW LEAVING\n");
			printf("THANKS FOR USING GAME CENTER\n");
			exit(1);
			break;
		}
		default: {
			printf("INVALID INPUT\n");
			main();
			exit(1);
			break;
		}
	}
}
