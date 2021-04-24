import java.util.Scanner;
import java.text.DecimalFormat;
public class Project1 {
   private static double principalAmount;
   
   

   public static void printAstericks() {
      for(int i = 0; i < 58; i++) {
         System.out.print("*");
      }
   }
   
   public static double principalAmount(double amount, double rate, double payment) {
      return principalAmount = payment - (amount * monthlyInterestRate(rate));
   }
   
   public static double totalInterest(double amount, double rate, double payment) {
      return payment - principalAmount(amount, rate, payment);
   }
   
   public static double monthlyInterestRate(double rate) {
      return ((rate / 12)) / 100;
   }
   
   public void createAmortizationTable(int amount, double rate, double payment) {
      Scanner in = new Scanner(System.in);
      System.out.println("Loan Amount:");
      amount = in.nextInt();
      System.out.print("Interest Rate (% per year): ");
      rate = in.nextDouble();
      System.out.print("Monthly payments: ");
      payment = in.nextDouble();
      printAstericks();
      System.out.println("\n" + "\t" + "\t" + "Amortization Table");
      printAstericks();
      System.out.print("\n" + "Month  ");
      System.out.print("Balance     ");
      System.out.print("Payment Rate    ");
      System.out.print("Interest  ");
      System.out.print("Principal");
   }
   
   public static void main(String [] args) {
      Scanner in = new Scanner(System.in);
      System.out.print("Loan Amount: ");
      double amount = in.nextDouble();
      System.out.print("Interest Rate (% per year): ");
      double rate = in.nextDouble();
      System.out.print("Monthly payments: ");
      double payment = in.nextDouble();
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
      DecimalFormat format3 = new DecimalFormat("$##.00");
      System.out.print("\t" + "\t" + dollarFormat.format(amount));
      System.out.print("\t" + " N/A");
      System.out.print("\t" + "\t" + "N/A");
      System.out.print("\t" + "\t" + "N/A");
      System.out.print("\t" + "\t" + "N/A");
      double balance = amount;
      while (amount > 0 || amount >= payment) {
         month++;
         System.out.print("\n" + month);
         amount =  amount - principalAmount(amount, rate, payment); 
         System.out.print("\t" + "\t" + dollarFormat.format(amount));
         System.out.print("\t" + "\t" + " " + dollarFormat1.format(payment));
         System.out.print("\t" + format2.format(100 * monthlyInterestRate(rate)));
         System.out.print("\t" + "\t" + dollarFormat1.format(totalInterest(balance, rate, payment)));
         System.out.print("\t" + format3.format(principalAmount));
      }
      if(amount < payment) {
         amount = 0;
         System.out.print("\t" + "\t" + dollarFormat.format(amount));
         payment = principalAmount(amount, rate, payment) + totalInterest(amount, rate, payment); 
         System.out.print("\t" + "\t" + " " + dollarFormat1.format(payment));
      
                      
      }  
   }
}
