#include "tree.h"
#include "afn.h"
#include "afdx.h"
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>
#include <algorithm>


using namespace std;

int AFDX::state;
vertex* AFDX::init_vertex;
vertex* AFDX::final_vertex;
ofstream AFDX::AFDX_file;
ostringstream AFDX::AFDX_output_t;

AFDX::AFDX(){
  result = NULL;
}

void AFDX::tran_to_text(int from, int to, char a){
  /*agrego a temp en forma ordena la informacion brindada y la devuelvo como string*/
  ostringstream temp;
  temp << "(" << from << ", " << a << ", " << to << ")";
  AFDX_output_t << temp.str();
}

string AFDX::states_to_text(){
  /*agrego a temp en forma ordena la informacion brindada y la devuelvo como string*/
  ostringstream temp;
  temp << "{";
  for(unsigned int i = 1; i<=state; i++){
    temp << i << ", ";
  }
  temp << "}";
  return temp.str();
}

string AFDX::symbols_to_text(){
  /*agrego a temp en forma ordena la informacion brindada y la devuelvo como string*/
  ostringstream temp;
  temp << "{";
  copy(this->L.begin(), this->L.end(), ostream_iterator<char>(temp, ", "));
  temp << "}";
  return temp.str();
}

string AFDX::final_to_text(){
  /*agrego a temp en forma ordena la informacion brindada y la devuelvo como string*/
  ostringstream temp;
  temp << "{";
  for(unsigned int i = 0; i<states_afdx.size(); i++){
    bool final_state_t = false;
    for(unsigned int j = 0; j<states_afdx[i]->afdx_set.size(); j++){
      if(states_afdx[i]->afdx_set[j] == final_vertex->number_of){
        final_state_t = true;
      }
      if(final_state_t){
        temp << states_afdx[i]->number_of << ", ";
      }
    }
  }
  temp << "}";
  return temp.str();
}

string AFDX::init_to_text(){
  /*agrego a temp en forma ordena la informacion brindada y la devuelvo como string*/
  ostringstream temp;
  temp << "{" << init_vertex->number_of << "}";
  return temp.str();
}

int AFDX::get_new_state(){
  state+=1;
  //cout <<"new state "<< state << endl;
  return state;
}

void AFDX::createAFDX(vertex* vertex_init, vector<char> L){
  /*Guardo atributos e inicializo la construccion de subconjuntos*/
  this->L = L;
  vector<char>::iterator pos = find(this->L.begin(), this->L.end(), char(238));
  if(pos != this->L.end()){
    this->L.erase(pos);
  }
  result = new AFDX;
  result = subset_const(vertex_init, this->L);
}

void AFDX::simulationAFDX(string exprsn){
  /*Agrego un caracter que denota que es el final de leer caracteres, en este caso es el f*/
  vector<vertex*> s0, S;
  vector<char> expression(exprsn.begin(), exprsn.end());
  expression.push_back(char(254));
  s0.push_back(init_vertex);
  S = s0;//eclosure(s0);
  char c = expression[0];
  expression.erase(expression.begin());
  /*mientras no sea f... */
  bool all_belongs = true;
  while(c!=char(254)){
    if (find(this->L.begin(), this->L.end(), c) != this->L.end()){
      S = move(S, c);
      c = expression[0];
      expression.erase(expression.begin());
    } else {
      S = move(S, c);
      c = expression[0];
      expression.erase(expression.begin());
      all_belongs = false;
    }
  };
  final_state = false;
  //cout << final_vertex->number_of << endl;
  /*Si el estado resultante no tiene el estado final, entonces respondo NO; pero si lo tiene entonces SI*/
  if(!S.empty()){
    for(unsigned int i = 0; i < S[0]->afdx_set.size(); i++){
      if (S[0]->afdx_set[i] == final_vertex->number_of && all_belongs){
        final_state = true;
      };
    }
  }
  if(final_state){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  /*Guardo en el archivo segun la rubrica*/
  AFDX_file.open("AFDX.txt", ios::out);
  if (AFDX_file.is_open()) {
    AFDX_file << "ESTADOS = ";
    AFDX_file << states_to_text() << endl;
    AFDX_file << "SIMBOLOS = ";
    AFDX_file << symbols_to_text() << endl;
    AFDX_file << "INICIO = ";
    AFDX_file << init_to_text() << endl;
    AFDX_file << "ACEPTACION = ";
    AFDX_file << final_to_text() << endl;
    AFDX_file << "TRANSICION = ";
    AFDX_file << AFDX_output_t.str() << endl;
  }
  AFDX_file.close();
}

AFDX* AFDX::subset_const(vertex* vertex_init, vector<char> L){
  stack<vector<vertex* > > Dstates;
  vector<vertex* > temp_init;
  temp_init.push_back(vertex_init);
  vector<vertex* > t0 = eclosure(temp_init);
  sort(t0.begin(), t0.end(), compare_by_number_of());
  init_vertex = subset_to_vertex(t0);
  init_vertex->number_of = get_new_state();
  states_afdx.push_back(init_vertex);
  Dstates.push(t0);
  //cout << "Creating AFDX .... " << endl;
  while (!Dstates.empty()){
    vector<vertex* > T = Dstates.top();
    vertex* v_from = subset_to_vertex(T);
    Dstates.pop();
    for(unsigned int i = 0; i<L.size(); i++){
      vector<vertex* >  U = eclosure(move(T, L[i]));
      sort(U.begin(), U.end(), compare_by_number_of());
      vertex* v_to = subset_to_vertex(U);
      if(count_if(states_afdx.begin(), states_afdx.end(), compare_by_afdx_set(v_to->afdx_set)) == 0){
        //cout << "New AFDX state found " << endl;
        v_to->number_of = get_new_state();
        states_afdx.push_back(v_to);
        Dstates.push(U);
      };
      vector<vertex* >::iterator it_v_from = find_if(states_afdx.begin(), states_afdx.end(), compare_by_afdx_set(v_from->afdx_set));
      vector<vertex* >::iterator it_v_to = find_if(states_afdx.begin(), states_afdx.end(), compare_by_afdx_set(v_to->afdx_set));
      int index_v_from = distance( states_afdx.begin(), it_v_from );
      int index_v_to = distance( states_afdx.begin(), it_v_to );
      //cout << "State index from -> " << index_v_from << endl;
      //cout << "State index to -> " << index_v_to << endl;
      //cout << "with.. " << L[i] << endl;
      states_afdx[index_v_from]->vertex_to.push_back(make_pair(L[i], states_afdx[index_v_to]));
      tran_to_text(states_afdx[index_v_from]->number_of, states_afdx[index_v_to]->number_of, L[i]);
    };
  };
}

vertex* AFDX::subset_to_vertex(vector<vertex* > v){
  /*agrego todos los vertices en un subconjunto a un vertice final*/
  vertex* new_state = new vertex;
  if(v.size() > 0 ){
    for(unsigned int k = 0; k<v.size(); k++){
      if(find(new_state->afdx_set.begin(), new_state->afdx_set.end(), v[k]->number_of) == new_state->afdx_set.end()){
        new_state->afdx_set.push_back(v[k]->number_of);
      }
    }
  } else {
    new_state->afdx_set.push_back(0);
  }
  //cout << "{ ";
  //copy(new_state->afdx_set.begin(), new_state->afdx_set.end(), ostream_iterator<int>(cout, " "));
  //cout << "}"<< endl;
  return new_state;
}

vector<vertex* > AFDX::eclosure(vector<vertex* > v){
  vector< vertex* > result_v;
  stack< vertex*, vector< vertex* > > states (v);
  vertex* t;
  //cout << "E-CLOSURE "<< endl;
  //cout << "Cantidad de Estados actuales "<< v.size() << endl;
  while(!states.empty()){
    t = states.top();
    states.pop();
    //cout <<"   Estado en revision: "<< t->number_of << endl;
    if(!t->vertex_to.empty()){
      for(unsigned int j = 0; j<=t->vertex_to.size()-1; j++){
        if(t->vertex_to[j].first == char(238)){
          if(count(result_v.begin(), result_v.end(), t->vertex_to[j].second)==0){
              result_v.push_back(t->vertex_to[j].second);
              states.push(t->vertex_to[j].second);
          }
        };
      //  cout << "     Se mueve con '"<<t->vertex_to[j].first << "' hacia estado "
      //       << t->vertex_to[j].second->number_of << endl;
      };
    } else {
      //cout << "     No tiene movimiento, es estado final"<< endl;
      final_vertex = t;
    };
  }
  result_v.insert(result_v.end(), v.begin(), v.end());
  return result_v;
}

vector<vertex* > AFDX::move(vector<vertex* > v, char c){
  vector<vertex* > result_v;
  //cout << "MOVE WITH "<< c << endl;
  //cout << "Cantidad de Estados actuales "<< v.size() << endl;
  if(!v.empty()){
    for (unsigned int i = 0; i<=v.size()-1; i++){
      //cout <<"   Estado en revision: "<< v[i]->number_of << endl;
      if(!v[i]->vertex_to.empty()){
        for(unsigned int j = 0; j<=v[i]->vertex_to.size()-1; j++){
          if(v[i]->vertex_to[j].first == c){
            result_v.push_back(v[i]->vertex_to[j].second);
          };
          //cout << "     Se mueve con '"<<v[i]->vertex_to[j].first << "' hacia estado "
          //     << v[i]->vertex_to[j].second->number_of << endl;
        };
      } else {
        //cout << "     No tiene movimiento, es estado final"<< endl;
        final_vertex = v[i];
      };
    };
  }
  return result_v;
}

vertex* AFDX::get_vertex_init(){
  /*Devuelvo el vertice/estado inicial*/
  return init_vertex;
}

void AFDX::minAFD(){
  vector<vertex* > F;
  vector<vertex* > S_F;
  vector<vector<vertex* > > PI, nPI, sPI;
  for(unsigned int i = 0; i < states_afdx.size(); i++){
    bool final_state = false;
    for(unsigned int j = 0; j < states_afdx[i]->afdx_set.size(); j++){
      if (states_afdx[i]->afdx_set[j] == final_vertex->number_of){
        final_state = true;
      };
    }
    if(final_state == true){
      F.push_back(states_afdx[i]);
    } else {
      S_F.push_back(states_afdx[i]);
    }
  }
  PI.push_back(F);
  PI.push_back(S_F);
  //cout << "Size of F " << F.size() << endl;
  //cout << "Size of S-F " << S_F.size() << endl;
  //cout << "Size of PI " << PI.size() << endl;
  nPI = PI;
  while(nPI != sPI){
    //cout << "Size NPI " <<nPI.size() << endl;
    //cout << "Size sPI " << sPI.size() << endl;
    vector<vertex* > belongsMV;
    vector<vertex* > belongsnMV;
    sPI = PI;
    PI = nPI;
    nPI.clear();
    for(unsigned int k = 0; k<PI.size(); k++){ //Revisando grupo por grupo
      if(PI[k].size() > 1){ //Si es mayor que uno, entonces puede dividirse
        vector<int > control(PI[k].size()); //vector de control
        vector<vector<vector<vertex* > > > belongsMatrix(PI[k].size(), vector<vector<vertex* > >(L.size())); //matriz de pertenencia
        for(unsigned int i = 0; i<PI[k].size(); i++){ //Recorremos segun el grupo, ABCD
          for(unsigned int c = 0; c<L.size(); c++){ //Recorremos segun caracter, a b
            vector<vertex* > temp_PIKI;
            temp_PIKI.push_back(PI[k][i]);
            belongsMatrix[i][c] = searchForBelong(PI, move(temp_PIKI, L[c])[0]->number_of); //buscamos al grupo que pertenece y lo guardamos en la matriz
          }
        }
        vector<vector<vertex* > > G(PI[k].size()); //creamos todos los grupos posibles
        for(unsigned int i = 0; i<PI[k].size(); i++){ //Verfificamos para A
          if(control[i] != 1){ //Si el control aun es 0, entonces no hemos hecho ese grupo
            //cout << "Estado " << i << endl;
            if(find(G[i].begin(), G[i].end(), PI[k][i]) == G[i].end()){
                G[i].push_back(PI[k][i]); //Metemos a A
            }
            control[i] = 1; //Marcamos A
            for(unsigned int j = i+1; j<PI[k].size(); j++){ //Verificamos B, C, D
              if(control[j] != 1){
                //cout << "     con Estado "<< j << endl;
                if(belongsMatrix[i] == belongsMatrix[j]){ // Si es igual a A, entonces pertenece al mismo grupo
                  //cout << "       Estado " <<i << " es igual a  Estado " << j << endl;
                  if(find(G[i].begin(), G[i].end(), PI[k][j]) == G[i].end()){
                      G[i].push_back(PI[k][j]); //Metemos a B
                  }
                  control[j] = 1; //Marcamos B
                }
              }
            }
          }
        }
        //cout << "Ingresamos los siguientes grupos: " << endl;
        for(unsigned int g = 0; g<G.size(); g++){
          if(!G[g].empty()){
              //cout << "   Metemos grupo " << g << endl;
              if(find(nPI.begin(), nPI.end(), G[g]) == nPI.end()){
                  nPI.push_back(G[g]);
              }
          }
        }
      } else { //si es 1 entonces simplemente lo agrego
        nPI.push_back(PI[k]);
      }
    }
  }
  //cout << "Last size sPI " << sPI.size() << endl;
  cout << "MIN AFD" << endl;
  for(unsigned int i = 0; i<sPI.size(); i++){
    cout << "Group " << i << endl;
    for(unsigned int j = 0; j<sPI[i].size(); j++){
      cout << "   " <<sPI[i][j]->number_of << endl;
    }
  }
  if(final_state){
    cout << "MIN AFD - YES" << endl;
  } else {
    cout << "MIN AFD - NO" << endl;
  }
}

vector<vertex* > AFDX::searchForBelong(vector<vector<vertex* > > PI, int state){
  for(unsigned int i = 0; i<PI.size(); i++){
    for(unsigned int j = 0; j<PI[i].size(); j++){
      if(PI[i][j]->number_of == state){
        return PI[i];
      }
    }
  }
}
