#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
  return pow(mu, k)*(exp(-mu))/(tgamma(k+1));
}



double prob(std::vector<int> daten, double mu = 3.11538) {
  double product = 1;  
  for(int i = 0 ; i < 234 ; ++i) {
       
      product *= poisson(mu, daten[i]);
  }
  return product;
}


double Lambda(std::vector<int> daten, double mu = 3.11538) {
  double product2 = 1;  
  double product3 = 1; 
  for(int i = 0 ; i < 234 ; ++i) {
       
      product2 *= poisson(mu, daten[i]);
      product3 *= poisson(daten[i], daten[i]);
    
  }
  return product2/product3;
}

int main() {
    using namespace std;

    vector <int> daten;  
    ifstream fin("datensumme.txt");

    int n_i;
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        daten.push_back(n_i);
    }
    fin.close();

double n_dof = 233;
double z = (-2*log(Lambda(daten))-n_dof)/(sqrt(2*n_dof));
  
  std :: cout << prob(daten) << std :: endl ;
  std :: cout << -2*log(Lambda(daten)) << std :: endl ;
  std :: cout << z << std :: endl ;

  ofstream fout("likelihood.txt");
  for (double mu = 0; mu < 6; mu=mu+0.01){
      fout << mu << " " << prob(daten,mu) << std :: endl;
  }
  
  ofstream fout2("nll.txt");
  for (double mu = 0; mu < 6; mu=mu+0.01){
      fout2 << mu << " " << -2*log(prob(daten,mu)) << std :: endl;
  }
  
   ofstream fout3("deltanll.txt");
  for (double mu = 0; mu < 6; mu=mu+0.01){
      fout3 << mu << " " << -2*log(prob(daten,mu)) + 2*log(prob(daten)) << std :: endl;
  } 

  
  }