#include <iostream>
using std::cout; using std::endl;
class project1_dsb0028 {
   public:
       void printAstericks() {
      for(int i = 0; i < 58; i++) {
         System.out.print("*");
      }
   }
   
   static double principalAmount(double amount, double rate, int payment) {
      return payment - (amount * monthlyInterestRate(rate));
   }
   
   
   static double totalInterest(double amount, double rate, int payment) {
      return payment - principalAmount(amount, rate, payment);
   }
   
   static double monthlyInterestRate(double rate) {
      return ((rate / 12)) / 100;
   }
   
   void createAmortizationTable(int amount, double rate, int payment) {
      Scanner in = new Scanner(System.in);
      System.out.println("Loan Amount:");
      amount = in.nextInt();
   }
   
   public static void main(String [] args) {
      Scanner in = new Scanner(System.in);
      System.out.print("Loan Amount: ");
      double amount = in.nextDouble();
      System.out.print("Interest Rate (% per year): ");
      double rate = in.nextDouble();
      System.out.print("Monthly payments: ");
      int payment = in.nextInt();
      printAstericks();
      System.out.println("\n" + "\t" + "\t" + "Amortization Table");
      printAstericks();
      System.out.print("\n" + "Month  ");
      System.out.print("Balance     ");
      System.out.print("Payment Rate    ");
      System.out.print("Interest  ");
      System.out.print("Principal");
      int month = 0;
      System.out.print("\n" + month);
      DecimalFormat dollarFormat = new DecimalFormat(" $#,###.00");
      DecimalFormat dollarFormat1 = new DecimalFormat("$#0.00");
      DecimalFormat format2 = new DecimalFormat("##.00");
      System.out.print("\t" + "\t" + dollarFormat.format(amount));
      System.out.print("\t" + " N/A");
      System.out.print("\t" + "\t" + "N/A");
      System.out.print("\t" + "\t" + "N/A");
      System.out.print("\t" + "\t" + "N/A");
      month = 1;
      while (amount > 0) {
         System.out.print("\n" + month);
         double balance = amount - principalAmount(amount, rate, payment);
         System.out.print("\t" + "\t" + dollarFormat.format(balance));
         System.out.print("\t" + "\t" + " " + dollarFormat1.format(payment));
         System.out.print("\t" + format2.format(100 * monthlyInterestRate(rate)));
         System.out.print("\t" + "\t" + dollarFormat1.format(totalInterest(amount, rate, payment)));
         month++;
         amount =  amount - principalAmount(amount, rate, payment);
         if(amount < payment) {
                
         }
      }
};