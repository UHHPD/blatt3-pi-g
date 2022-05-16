#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {  
  return pow(mu, k)*(exp(-mu))/(tgamma(k+1));
}

double c = poisson(1, 2);

int main() {
    using namespace std;


    ifstream fin("datensumme.txt");
    ofstream fout("hist.txt");
    int n_i;
    vector <int> zaehler(11);
    for(int i = 0 ; i < 234 ; ++i) {
        fin >> n_i;
        zaehler[n_i] += 1;
    }
    
    fin.close();
  for ( unsigned int k = 0 ; k < zaehler . size () ; ++ k ) {
  std :: cout << k << " : " << zaehler [ k ] << std :: endl ;
  fout << k << " " << zaehler [ k ] << " " << 234*(poisson(3.11538, k)) << std :: endl;
}
}