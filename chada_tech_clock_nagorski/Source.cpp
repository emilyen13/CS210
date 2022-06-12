/*Emily Nagorski 
UID: 1969938
CS210 T5407*/


#include<iostream>
#include<ctime>
#include<locale>
#pragma warning(disable : 4996)

using namespace std;

tm* timeVariable() { //gets time, hour/min/sec and stores it as a variable
	time_t ttime = time(0);
	tm* local_time = localtime(&ttime);
	return local_time;
	}

	void twelveHour() { //displays my 12 hour clock from system time
		locale::global(locale(""));
		time_t t = time(nullptr);
		char mbstr[100];
		strftime(mbstr, sizeof(mbstr), "%r", localtime(&t));
		{
		cout << "**************************     **************************" << endl;
		cout << "*     12-Hour Clock      *     *      24-Hour Clock     *" << endl;
		cout << "*      " << mbstr << "        *     ";
		}
		
	}
	void twentyfourHour() { //displays my 24 hour clock from system time
		locale::global(locale(""));
		time_t t = time(nullptr);
		char mbstr[100];
		strftime(mbstr, sizeof(mbstr), "%H:%M:%S", localtime(&t));
		{
			cout << "*       " << mbstr << "         *" << endl;
			cout << "**************************     **************************" << endl;
		}
	}
	
	int changeHourTwelve(int hour) { //changes the hour for 12 hour clock
		if (hour == 11) {
			hour = 12;
			return hour;
		}
		else {
			hour += 1;
			return hour;
		}
	}

	int changeMinuteTwelve(int minute) { //changes the minute for 12 hour clock
		if (minute == 59) {
			minute = 0;
			changeHourTwelve(0);
			return minute;
		}
		else {
			minute += 1;
			return minute;
		}
	}

	int changeSecondTwelve(int second) { //changes the second for 12 hour clock
		if (second == 59) {
			second = 0;
			changeMinuteTwelve(0);
			return second;
		}
		else {
			second += 1;
			return second;
		}
	}

	int changeHourTwentyfour(int hour) { //changes the hour for 24 hour clock
		if (hour == 23) {
			hour = 1;
			return hour;
		}
		else {
			hour += 1;
			return hour;
		}
	}

	int changeMinuteTwentyfour(int minute) { //changes the minute for 24 hour clock 
		if (minute == 59) {
			minute = 0;
			changeHourTwentyfour(0);
			return minute;
		}
		else {
			minute += 1;
			return minute;
		}
	}

	int changeSecondTwentyfour(int second) { //changes the msecond for 24 hour clock
		if (second == 59) {
			second = 0;
			changeMinuteTwentyfour(0);
			return second;
		}
		else {
			second += 1;
			return second;
		}
	}



	int main() {
		int userInput; //accepts input from user
		bool runMenu = true; //keeps menu running until user exists program
		twelveHour(); //calls half of time display 
		twentyfourHour(); //calls the half of the time display
		tm* localTime = timeVariable();
		int adjustedHour = localTime->tm_hour;

		if (localTime->tm_hour > 12) //takes the variable time that is in 24 hor format and adjusts it for the 12 hour clock
		{
			adjustedHour = localTime->tm_hour - 12;
		}

		int hourTwelve = adjustedHour; //calls the time variable
		int minuteTwelve = localTime->tm_min; //calls time variable
		int secondTwelve = localTime->tm_sec; //calls time variable

		int hourTwentyfour = localTime->tm_hour; //calls time variable
		int minuteTwentyfour = localTime->tm_min; //calls time variable
		int secondTwentyfour = localTime->tm_sec; //calls time variable


		while (runMenu == true) { //menu display
			cout << "**************************" << endl;
			cout << "* 1- Add One Hour        *" << endl;
			cout << "* 2- Add One Minute      *" << endl;
			cout << "* 3- Add One Second      *" << endl;
			cout << "* 4- Exit Program        *" << endl;
			cout << "**************************" << endl;


			cin >> userInput; //intake user selection
			switch (userInput) { //switch statement to error handle menu options
			case 1: //add hour
				cout << "********************* Your New Time *********************" << endl; 
				cout << "**************************     **************************" << endl;
				cout << "*     12-Hour Clock      *     *      24-Hour Clock     *" << endl;
				cout << "*      " << changeHourTwelve(hourTwelve) << ":" << minuteTwelve << ":" << secondTwelve << "          *     ";
				cout << "*       " << changeHourTwentyfour(hourTwentyfour) << ":" << minuteTwentyfour << ":" << secondTwentyfour << "         *" << endl;
				cout << "**************************     **************************" << endl;
				cout << endl;
				
				break;

			case 2: //add minute
				cout << "********************* Your New Time *********************" << endl;
				cout << "**************************     **************************" << endl;
				cout << "*     12-Hour Clock      *     *      24-Hour Clock     *" << endl;
				cout << "*      " << hourTwelve << ":" << changeMinuteTwelve(minuteTwelve) << ":" << secondTwelve << "          *     ";
				cout << "*       " << hourTwentyfour << ":" << changeMinuteTwentyfour(minuteTwentyfour) << ":" << secondTwentyfour << "         *" << endl;
				cout << "**************************     **************************" << endl;
				cout << endl;
		
				break;

			case 3: //add second
				cout << "********************* Your New Time *********************" << endl;
				cout << "**************************     **************************" << endl;
				cout << "*     12-Hour Clock      *     *      24-Hour Clock     *" << endl;
				cout << "*      " << hourTwelve << ":" << minuteTwelve << ":" << changeSecondTwelve(minuteTwelve) << "          *     ";
				cout << "*       " << hourTwentyfour << ":" << minuteTwentyfour << ":" << changeSecondTwentyfour(secondTwentyfour) << "         *" << endl;
				cout << "**************************     **************************" << endl;
				cout << endl;
				
				break;

			case 4: //exit program
				cout << "Thank you for visiting. Goodbye." << endl;
				runMenu = false;
				break;

			default: //invalid input
				cout << "Invalid number selection, please try 1, 2, 3, or 4." << endl;
				twelveHour();
				twentyfourHour();
				break;
			}
		}

	}
