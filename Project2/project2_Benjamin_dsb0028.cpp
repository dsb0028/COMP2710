/**
 * File Name: 	project2_Benjamin_dsb0028.cpp
 * Author:    	Daniel Benjamin
 * AU UserID: 	dsb0028
 * Description: COMP 2710 - Project2.cpp
 * Compile:     g++ project2_Benjamin_dsb0028.cpp -o Project2.out
 * Run:		./Project2.out         
 *
 */
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
//#define NDEBUG
using namespace std;



//COUNTER VARIABLES BEING DEFINED
int AARON_WINS = 0;
int BOB_WINS = 0;
int CHARLIE_WINS = 0;
int AARON2_WINS = 0;

bool at_least_two_alive (bool A_alive, bool B_alive, bool C_alive) {
	 
   return (A_alive && B_alive) || (A_alive & C_alive) || (B_alive && C_alive);
}

void Aaron_shoots1 (bool& B_alive, bool& C_alive) {
 
   double shoot_target_result;
   if (at_least_two_alive (true, B_alive, C_alive) == true) {

      if (C_alive == true) {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 33) {
          C_alive = false;
          cout << "Hit the target";
      }

      }
   else {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 33) {
         B_alive = false;
         cout << "Hit the target";
      }
    
   }
 }
}

void Bob_shoots (bool& A_alive, bool& C_alive) {
   double shoot_target_result;
      if (at_least_two_alive (A_alive, true, C_alive) == true) {

      if (C_alive == true) {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 50) {
         C_alive = false;
         
         cout << "Hit the target";
      }

      }

   else {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 50) {
         A_alive = false;
         cout << "Hit the target";
      }
    
   }
      }
}

void Charlie_shoots (bool& A_alive, bool& B_alive) {

       
    
      if (B_alive == true) {
      B_alive = false;
      cout << "Hit the target";
     
      }
  
      if (A_alive == true) {
      A_alive = false;
      cout << "Hit the target";
     
      }

}

void Aaron_shoots2 (bool& B_alive, bool& C_alive) {
if (at_least_two_alive(true, B_alive, C_alive)) {
   if (B_alive && C_alive) {
      return;   
   }
  
   int shoot_target_result;
   int AARON2_WINS = 0;
   
   if (C_alive == true) {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 33) {
         C_alive = false;
         ++AARON2_WINS;
      }
   }
   
   else {
      srand(time(0));
      shoot_target_result = rand() % 100;
      if (shoot_target_result <= 33) {
         B_alive = false;
         ++AARON2_WINS;
      }
    
   }
}
  
}

void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true , false));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false , true));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false ,true , false));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true , false , false));
   cout << "\tCase passed ...\n";
	
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false , false , false));
   cout << "\tCase passed ...\n";
	
   cout << "Press any key to continue...";
   cin.ignore().get();
} 

void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\tAaron is shooting at Charlie\n";

   cout << "\tCase 2: Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\tAaron is shooting at Charlie\n";
	
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\tAaron is shooting at Bob\n";

   cout << "Press any key to continue...";
   cin.ignore().get();
}


void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   cout << "\tCase 1: Aaron alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\tBob is shooting at Charlie\n";

   cout << "\tCase 2: Aaron dead, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\tBob is shooting at Charlie\n";
	
   cout << "\tCase 3: Aaron alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\tBob is shooting at Aaron\n";

   cout << "Press any key to continue...";
   cin.ignore().get();
}

void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   cout << "\tCase 1: Aaron alive, Bob alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\tCharlie is shooting at Bob\n";

   cout << "\tCase 2: Aaron dead, Bob alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\tCharlie is shooting at Bob\n";
	
   cout << "\tCase 3: Aaron alive, Bob dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\tCharlie is shooting at Aaron\n";

   cout << "Press any key to continue...";
   cin.ignore().get();
}

void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

   cout << "\tCase 1: Bob alive, Charlie alive\n";
   cout << "\t\tAaron intentionally misses his first shot\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\tBoth Bob and Charlie are alive\n";

   cout << "\tCase 2: Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\tAaron is shooting at Charlie\n";
	
   cout << "\tCase 3: Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\tAaron is shooting at Bob\n";

   cout << "Press any key to continue...";
   cin.ignore().get();
}

void test_Strategy1() {
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

cout << "Ready to test strategy 1 (run 10000 times):\n";
cout << "Press any key to continue...";
cin.ignore().get();

bool A_alive = true;
bool B_alive = true;
bool C_alive = true;

double AARON_WINNING_PERCENTAGE = (double) ((AARON_WINS / 10000) * 100);
double BOB_WINNING_PERCENTAGE = (double) ((BOB_WINS / 10000) * 100);
double CHARLIE_WINNING_PERCENTAGE =  (double) ((CHARLIE_WINS/ 10000) * 100);

int trials = 10000;

while(trials > 0) {
Aaron_shoots1(B_alive, C_alive);
Bob_shoots(A_alive, C_alive);
Charlie_shoots(A_alive, B_alive);

if (A_alive == true) {
  ++AARON_WINS;
}

else if (B_alive == true) {
   ++BOB_WINS;
}

else if (C_alive == true) {
   ++CHARLIE_WINS;
}
trials--;
}




cout << "Aaron won " << AARON_WINS << "/10000 duels or " << AARON_WINNING_PERCENTAGE << "%" << endl;
cout << "Bob won " << BOB_WINS << "/10000 duels or " << BOB_WINNING_PERCENTAGE << "%" << endl;
cout << "Charlie won " << CHARLIE_WINS << "/10000 duels or " << CHARLIE_WINNING_PERCENTAGE << "%" << endl;
}



int main() {

   cout << "*** Welcome to Daniel Benjamin's Duel Simulator ***" << "\n";

   test_at_least_two_alive();
   test_Aaron_shoots1();
   test_Bob_shoots();
   test_Charlie_shoots();
   test_Aaron_shoots2();
   test_Strategy1();



   return 0;
}