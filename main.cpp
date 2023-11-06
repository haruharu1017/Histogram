// Test program starter file for CSCI 60 Homework 2; due Monday 1/23/23
// Give a program description, list any collaborators, and write your name here

#include <iostream>
#include "histogram.h"

using namespace std;

int main() {

  Histogram h = Histogram("data.txt");

  cout << "size: " << h.size() << endl;
  cout << "min: " << h.min() << endl;  
  cout << "max: " << h.max() << endl;
  cout << "mode: " << h.mode() << endl;
  cout << "median: " << h.median() << endl;
  cout << "mean: " << h.mean() << endl;
  cout << "variance: " << h.variance() << endl;
  // cout << h;

  // int total = 0; // var to store total
  // ifstream in("data.txt"); // open a file called data.txt as an input stream in
  // int val; // var to store one int at a time
  // while (in >> val) { // read int tokens from stream 1-by-1 until end of file
  //   total += val; // add value of each token to total
  // }
  // in.close(); // close file
  // cout << "Sum of all ints in a file = " << total << endl; // report total

  //Histogram h("data.txt");
  //cout << h; // after stage 5, compare this to the sample run in hw2.pdf

  return 0;
}