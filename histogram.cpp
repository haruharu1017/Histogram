// Implementation starter file for CSCI 60 Homework 2; due Monday 1/23/23
// Comment functions below; list any collaborators and write your name here
// Mengxi He

#include "histogram.h"
#include "cmath"


/* TODO: implement the functions declared in histogram.h here */

Histogram::Histogram(string filename)
{
  for (int i = 0; i <= MAX; i++)
  {
    counts[i] = 0;
  }
  ifstream in(filename); 
  int val; 
  while (in >> val) { 
    counts[val]++;
  }
}

Histogram::Histogram()
{
  for (int i = 0; i <= MAX; i++)
  {
    counts[i] = 0;
  }
}

size_t Histogram::size() const
{
  int sum = 0;
  for(int i = 0; i < MAX;i++)
    sum += counts[i];
  return sum;
}

size_t Histogram::min() const
{
  for (int i = 0; i < MAX; i++)
  {
    if (counts[i] != 0)
    return i;
  }
  return MAX+1;
}

size_t Histogram::max() const
{
  for (int i = MAX; i >= 0; i--)
  {
    if (counts[i] != 0)
    return i;
  }
  return -1;
}

size_t Histogram::mode() const
{
  int maxi = counts[0];

  for (int i = 0; i < MAX; i++)
  {
    if (counts[i] > maxi)
    maxi = counts[i];
  }

  for (int i = 0; i < MAX; i++)
  {
    if (maxi == counts[i])
    return i;
  }
}

size_t Histogram::median() const
{
  int sum = 0;
  int SUM = 0;
  for(int i = 0; i < MAX;i++)
    sum += counts[i];
  int ind = sum/2;
  for (int i = 0; i < MAX; i++)
  {
    SUM += counts[i];
    if (ind < SUM)
    return i;
  }
}

double Histogram::mean() const
{
  Histogram h;
  double sum = 0.0;
  double SUM = 0.0;
  for(int i = 1; i < MAX; i++)
  {
    sum += counts[i] * i;
    SUM += counts[i];
  }
  return double(sum/SUM);
}

double Histogram::variance() const
{
  double sum = 0.0;
  double mean = Histogram::mean();
  double size = Histogram::size();
  for (int i = 1; i < MAX; i++)
  {
    sum += counts[i] * pow((i-mean), 2);
  }
  return sum/size;
}

void Histogram::operator+=(const Histogram& rhs)
{
    for (int i = 0; i < MAX; i++)
    {
        counts[i] += rhs.counts[i];
    }
}

size_t Histogram::operator[](size_t val) const
{
  return counts[val];
}

ostream& operator <<(ostream& out, const Histogram& h)
{
  for (int i = h.min(); i <= h.max(); i++)
  {
    out << i << ": ";
    for (int j = 0; j < h[i]; j++)
    {
      out << "*";
    }
    out << "\n";
  }
  return out;
}

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
  cout << h;

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