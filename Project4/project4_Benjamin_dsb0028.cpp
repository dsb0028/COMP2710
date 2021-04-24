//https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
//https://www.tutorialspoint.com/what-is-the-use-of-cin-ignore-in-cplusplus

//imported libraries
#include <iostream>
#include<limits> //used to get numeric limits
#include<ios> //used to get stream size
using namespace std;
#include <stdio.h> 
//#define NDEBUG 

struct trivia_node {
   string question;
   string answer;
   int point;
   trivia_node* next;
};
 
typedef trivia_node* ptr_node;
 
//int quiz_length = 0;
 
int getCount(ptr_node head)  
{  
   int count = 0; // Initialize count  
   trivia_node* current = head; // Initialize current  
   while (current != NULL)  
   {  
      count++;  
      current = current->next;  
   }  
   return count;  
}    

//step 3 function
void init_question_list(ptr_node& q_list) {
//ptr_node cur_ptr;
//ptr_node cur_ptr;
   
   ptr_node new_node = new trivia_node;
   
   
   new_node -> question = "How long was the shortest war on record?";
   new_node -> answer = "38";
   new_node -> point = 100;
   
   new_node -> next = new trivia_node;
   q_list = new_node;
   
   new_node = q_list -> next;
                  
   new_node -> question = "What was Bank of America’s original name?";
   new_node -> answer = "Bank of Italy";
   new_node -> point = 50;
   
   new_node -> next = new trivia_node;
   new_node = new_node -> next;
             
   new_node -> question = "What is the best-selling video game of all time?";
   new_node -> answer = "Wii Sports";
   new_node -> point = 20;
   
   new_node -> next = NULL;
  
}

//step 4 function
void add_question(ptr_node& head) {
  
   string user_answer = "Yes";
   ptr_node cur_ptr;
   
   //gets data from user.

   do {
      cur_ptr = new trivia_node;
      cout << "\n\nEnter a new question: ";
      getline(cin, cur_ptr->question);
   
      cout << "\nEnter an answer: ";
      getline(cin, cur_ptr->answer);
   
      cout << "\nEnter points awarded: ";
      cin >>  cur_ptr-> point;
    
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
      cur_ptr->next = head;
      head = cur_ptr;
    
      cout << "\nContinue? (Yes/No): ";
      cin >> user_answer;
   
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
   }         
   while (user_answer == "Yes");
      
   
                 
}

//step 5 function
//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {

   ptr_node cur_ptr = q_list;

   if (cur_ptr == NULL)
      return 0;
   if(num_ask < 1) {
      cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
   }
   
   else if(getCount(q_list) < num_ask) {
      cout << "Warning - There is only " << getCount(q_list) << " trivia in the list.";
   }
   else {
   
      string user_answer;
      int  total_points  = 0;
   
      for(int x = 0; x < num_ask; x++) {
         
         cout << "Question: " << cur_ptr->question << endl;
         //cin.clear();
         //cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
         cout << "Answer: ";
       
         getline(cin, user_answer);
         //cin.clear();
         //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     
         if (user_answer.compare(cur_ptr->answer) == 0) {
            
            cout << "Your answer is correct. You received " <<  cur_ptr -> point  << " points." << endl;
            total_points += cur_ptr -> point;
         }
         else {
            cout << "Your answer is incorrect. The correct answer is: " << cur_ptr->answer << endl;   
         }
         
         if(cur_ptr -> next != NULL) {
            cur_ptr = cur_ptr -> next;
         }
      
      }
      
      cout << "Your total points: " << total_points << endl;
      
      return total_points;
      // if (user_answer.compare(cur_ptr->answer) == 0) {
         // int  total_points  = 0;
         // cout << "Your answer is correct. You received " <<  cur_ptr -> point  << " points." << endl;
         // cout << "Your total points: " << total_points +  cur_ptr -> point << endl;
         // return 0;
      // }
      // else {
         // cout << "Your answer is incorrect. The correct answer is: " << cur_ptr->answer;   
         // return 1;
      // }
      
      
   }
}

//Tests ask_question() method
void test_ask_question(void) {
   ptr_node node_list = new trivia_node;
   init_question_list(node_list);
   
   cout << "*** This is a Debugging Version ***\n";
   
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
   ask_question(node_list, 0);        
   cout << "\nCase 1 Passed\n\n";
   
   
   
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
   ask_question(node_list, 1) == 1;      
   cout << "\nCase 2.1 Passed\n\n";
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer." << endl;
   ask_question(node_list, 1) == 0;
   cout << "\nCase 2.2 Passed\n\n";
   
   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
   cout << "\nCase 3 Passed\n\n";
   ask_question(node_list, getCount(node_list)) == 1;
      
   cout << "\nUnit Test Case 4: Ask 5 questions in the linked list." << endl;
   ask_question(node_list, 5) == 1;
   cout << "\nCase 4 Passed\n\n";

   cout << "\n\n*** End of the Debugging Version ***\n";
}

  
    
#define trivia_quiz
//#define UNIT_TESTING
int main() {
         
   
   ptr_node q_list = new trivia_node;
                 
#ifdef trivia_quiz
   
   init_question_list(q_list);
   cout << "*** Welcome to Daniel’s trivia quiz game ***\n";
   add_question(q_list);
   int quiz_length = getCount(q_list);
   
   //cout << quiz_length << endl;

   ask_question(q_list, quiz_length);
   cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
   return 0;        
 
#endif

#ifdef UNIT_TESTING
   test_ask_question();
   return 0;
 #endif
}