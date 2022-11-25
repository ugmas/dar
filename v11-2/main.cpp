#include "libai.hpp"


class studentas{
  string vardas, pavarde;
  vector <float> paz;
  float egz; 
  float galutinis;
public:
  studentas():vardas{""},pavarde{""},paz{0}, egz{0} { galutinis=0.;}
  studentas(string v, string p, vector<float> pa, float e):vardas{v},pavarde{p},paz{pa}, egz{e} { 
    Gal_(); 
  }
// getters
string Vardas(){return vardas;}
string Pavarde(){return pavarde;} 
vector <float> pazym(){return paz;}
float egzas(){return egz;} 
float galut(){return galutinis;}  
const string Vardas()const {return vardas;}
const string Pavarde()const {return pavarde;} 
const vector <float> pazym()const {return paz;}
const float egzas()const {return egz;} 
const float galut()const{return galutinis;}  

//setters 
void Vardas_() {cin>>vardas;} 
void Pavarde_() {cin>>pavarde;}  
void Paz_(vector <float> vec) {this->paz=vec;}  
void Egz_() {cin>>egz;}  
void Gal_() {float vid=std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size();
      this->galutinis=0.4*vid+0.6*this->egz;}  


studentas(const studentas &temp) { 
    vardas= temp.Vardas();
    pavarde= temp.Pavarde(); 
    paz=temp.pazym();
    egz=temp.egzas();
    galutinis=temp.galut(); 
  }

studentas & operator=(const studentas& temp){
    if (&temp == this) return *this;
    vardas= temp.Vardas();
    pavarde= temp.Pavarde(); 
    paz=temp.pazym();
    egz=temp.egzas();
    galutinis=temp.galut(); 
   return *this;
}

~studentas(){paz.clear();} 
};

void print(studentas);
double mediana(vector<float> &vec);

int main() {
  cout <<"Iveskite studentu skaiciu: "<<endl;
  int n; ///studentu skaicius
  cin>> n;
  vector<studentas> grupe; 
  studentas tempas;
  grupe.reserve(n);
  vector <float> laikinas;
  float sum=0, laik, vid, med;
  for (int i=0; i<n; i++) 
    {
      cout<<"Iveskite "<<i+1<<"-o studento varda ir pavarde:" ;
      tempas.Vardas_(); tempas.Pavarde_();
      sum=0;
      while (cin>>laik)
      {        
        laikinas.push_back(laik); 
        sum+= laik;
      }
      tempas.Paz_(laikinas);
      
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<"Iveskite "<<i+1<<"-o studento egzamino pazymi:" ;
      tempas.Egz_();
      tempas.Gal_(); 
      grupe.push_back(tempas);
      laikinas.clear();  
    }
  
  for (const auto &kint: grupe) {
    print(kint);
  }

}

void print(studentas kint){
  cout<<setw(20)<<kint.Vardas()<<setw(20)<<kint.Pavarde(); 
    for (auto &i: kint.pazym()) cout<<setw(5)<<i; 
    cout<<setw(5)<<kint.egzas()<<setw(5)<<setprecision(2)<<kint.galut()<<endl;
}


double mediana( vector<float> &vec) {
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0) // std::domain_ error deklaruota <stdexcept>
    throw std::domain_error("negalima skaičiuoti medianos tuščiam vektoriui");
  sort(vec.begin(), vec.end()); // surūšiuojame vektorių į variacinę eilutę
  vecSize vid = size / 2; // vidurinis vektoriaus elementas
  return size % 2 == 0 ? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}
