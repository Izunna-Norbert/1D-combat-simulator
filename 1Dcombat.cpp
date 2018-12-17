#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int main (){
	float attackresult; 
	default_random_engine randomnumber(time(0));
	uniform_real_distribution <float> attack(0.0f,1.0f);
	char turn = 'k';


	cout << "******A 1D COMBAT SIMMULATOR********" << endl << endl;
	cout << "*********SPARTANS VS KNIGHTS OF CAMELOT********" << endl << endl;
	

	// spartans attributtes.
	int spartans;
	int numspartans;
	float spattack = 0.6f;
	float sphealth = 100.0f;
	float spdamage = 200.0f;
	float currentsphealth = sphealth;

	//knights of camelot attributtes.
	int knights_of_camelot;
	int numknights;
	float knattack = 0.8f;
	float knhealth = 200.0f;
	float kndamage = 250.0f;
	float currentknhealth = knhealth;

	//get the number of spartans and the number of knights of camelot.
	cout << "ENTER THE NUMBER OF SPARTANS: ";
	cin >> spartans;
	numspartans = spartans;

	cout <<endl<< "ENTER THE NUMBER OF KNIGHTS OF CAMELOT: ";
	cin >> knights_of_camelot;
	numknights = knights_of_camelot;
	cout << "\n\n ***BEGINING COMBAT*** " << endl;

	while((spartans>0) &&(knights_of_camelot>0)){
		//get the attack result
		attackresult = attack(randomnumber);
		
		if (turn == 'k' ){
			
			//check if attack was successful 
			if (attackresult<=knattack){
				currentsphealth -= kndamage;
				if(currentsphealth<0){
					spartans--;
					currentsphealth = sphealth;
				}
  
			}
			turn = 's';
		}
		else {
			//check if attack was successful 
			if(attackresult<=spattack){
				currentknhealth -= spdamage;
				if(currentknhealth<0){
					knights_of_camelot--;
					currentknhealth = knhealth;
				}
			
			}
			turn = 'k';
		}
	}
	cout << "\n ***THE BATTLE IS OVER***" << endl;
	if (knights_of_camelot>0){
		cout << "the knights of camelot won " << endl;
		cout << "There are " << knights_of_camelot << " knights of camelot left" << endl;
		cout << (numknights - knights_of_camelot) << " lost their lives " << endl;
	}
	else{
		cout << "Spartans won " << endl;
		cout << "There are " << spartans << " spartan warriors left" << endl;
		cout << (numspartans - spartans) << " lost their lives " << endl;
	}


	system("pause");
	return 0;
}