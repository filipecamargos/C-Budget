/***********************************************************************
* Program:
*    Project 04, Monthly Budget  
*    Brother Christensen, CS124
* Author:
*    Filipe Ferreira
* Summary: 
*    This program manage personal finances for a month. This program will
*    ask you for your budget income and expenditures, then the program
*    will make the caculation and display a report.
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult was understand parametes of fuctions
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;


/**********************************************
* This fuction was meant to collect the data
* of the person's income and send to the main
* function so it cam be computated
***********************************************/
double income()
{
   double monInc;
   cout << "\tYour monthly income: ";
   cin  >> monInc;
   return monInc;
}

/*********************************************
* THis fuction was meant to  get the data of
* the person's budgeted living expenses.
**********************************************/
double budgetLiving()
{
   double bugLiv;
   cout << "\tYour budgeted living expenses: ";
   cin  >> bugLiv;

   return bugLiv;
}   

/*******************************************
* This fuction was meant to get the actual
* living expenses.
********************************************/
double actualLiving()
{
   double livExp;
   cout << "\tYour actual living expenses: ";
   cin  >> livExp;

   return livExp;
}

/******************************************
* This fuction is meant to get taxes data
*******************************************/
double taxes()
{
   double tax;
   cout << "\tYour actual taxes withheld: ";
   cin  >> tax;

   return tax;
}

/*******************************************
* This fuction is meant to get data of the
* tithing of the person.
********************************************/
double tithing()
{
   double titOff;
   cout << "\tYour actual tithe offerings: ";
   cin  >> titOff;

   return titOff;
}

/******************************************
 * This fuction is meant to get the data of
 * other expenses.
 ******************************************/
double others()
{
   double actExp;
   cout << "\tYour actual other expenses: ";
   cin  >> actExp;

   return actExp;
}

/******************************************
* This function make the tithing caculation
* based on the person's income.
*******************************************/
double computTithing(double income)
{
   double realT;
   realT = income * 0.10;
   return realT;
}

/******************************************
* This fuction compute the difference of the
* income and all the expenses, which give the
* actual difference.
*******************************************/
double computDiff(double income, double tax,
                  double titOff, double actExp,
                  double livExp)
{
   double diff;
   diff = income - (tax + titOff + actExp + livExp);
   return diff;
}   

/**********************************************
* This fuction computer the difference of  other
* budgets expenses and  the income, which give
* the others.
**********************************************/
double computOthers(double income, double realT,
                    double budLiv, double taxcal)
{
   double budOth;
   budOth = income - (realT + budLiv + taxcal);
   return budOth;
}         

/**************************************************
* This fuction is meant caculate the amount of
* of taxes.
*************************************************/
double taxComp(double income)
{
   double taxpay;
   double taxbase;
   taxbase = income * 12;
   
   if (taxbase <= 15100 && taxbase > 0)
      taxpay = (taxbase * 0.10) / 12 ;
   else if (taxbase > 15100 && taxbase <= 61300)
      taxpay = (1510 + ((taxbase - 15100) * 0.15)) / 12;
   else if (taxbase > 61300 && taxbase <= 123700)
      taxpay = (8440 + ((taxbase - 61300) * 0.25)) / 12;
   else if (taxbase > 123700 && taxbase <= 188450)
      taxpay = (24040 + ((taxbase - 123700) * 0.28)) / 12;
   else if (taxbase > 188450 && taxbase <= 336550)
      taxpay = (42170 + ((taxbase - 188450) * 0.33)) / 12;
   else if (taxbase > 336550)
      taxpay = (91043 + ((taxbase - 336550) * 0.35)) / 12;

   return taxpay;
}   

/********************************************
* This fuction was meant to receive all the
* information and display in a nice way the
* collection and the computation of the data
* however this fuction must be called due to
* be a void fuction that does not give return
********************************************/
void display(double monInc, double taxcal, double tax,
             double realT, double titOff, double bugLiv,
             double livExp, double budOth, double actExp,
             double diff)
{                  
   cout << "\nThe following is a report on your monthly expenses\n";

   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $" << setw(11) << monInc << setw(5)
        << "$" << setw(11) <<  monInc << endl;
   cout << "\tTaxes           $" << setw(11) << taxcal << setw(5)
        << "$" << setw(11) << tax << endl;
   cout << "\tTithing         $" << setw(11) << realT << setw(5)
        << "$" << setw(11) << titOff << endl;
   cout << "\tLiving          $" << setw(11) << bugLiv << setw(5)
        << "$" << setw(11) << livExp << endl;
   cout << "\tOther           $" << setw(11) << budOth << setw(5)
        << "$" << setw(11) << actExp << endl;
   cout << "\t=============== =============== ===============\n";
   cout << "\tDifference      $" << setw(11) << 0.00 << setw(5)
        << "$" << setw(11) << diff << endl; 
}

/*********************************************
* This is our main fuction that will gather
* all the information that will come in and out
* including our display and run our program.
*********************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "This program keeps track of your monthly budget\n";
   cout << "Please enter the following:\n";
   
   double monInc = income();
   double bugLiv = budgetLiving();
   double livExp = actualLiving();
   double tax = taxes();
   double titOff = tithing();
   double actExp = others();
   double realT = computTithing(monInc);
   double diff = computDiff(monInc, tax, titOff, actExp, livExp);
   double taxcal = taxComp(monInc);
   double budOth = computOthers(monInc, realT, bugLiv, taxcal);
   
   display(monInc,taxcal, tax, realT, titOff, bugLiv,
           livExp, budOth,actExp, diff);

   return 0;
}

