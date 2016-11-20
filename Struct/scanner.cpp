#include "tree.h"
#include "afn.h"
#include "scanner.h"
#include "string"
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

Scanner::Scanner(){
  init_vertex = new vertex;
  unsigned int c = 0;
//-->size
   unsigned int n = 40;
  AFN_lineal.reserve(n);
  while(c<n){
    vertex* v = new vertex;
    AFN_lineal[c] = v;
    AFN_lineal[c]->number_of = c;
    c++;
  }
//-->init
   init_vertex = AFN_lineal[38];
//-->transitions
   AFN_lineal[7]->vertex_to.push_back(make_pair(')', AFN_lineal[7]));
   AFN_lineal[6]->vertex_to.push_back(make_pair(')', AFN_lineal[7]));
   AFN_lineal[6]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[5]->vertex_to.push_back(make_pair(')', AFN_lineal[6]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[5]));
   AFN_lineal[10]->vertex_to.push_back(make_pair('(', AFN_lineal[10]));
   AFN_lineal[9]->vertex_to.push_back(make_pair('(', AFN_lineal[10]));
   AFN_lineal[9]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[8]->vertex_to.push_back(make_pair('(', AFN_lineal[9]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[8]));
   AFN_lineal[13]->vertex_to.push_back(make_pair('+', AFN_lineal[13]));
   AFN_lineal[12]->vertex_to.push_back(make_pair('+', AFN_lineal[13]));
   AFN_lineal[12]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[11]->vertex_to.push_back(make_pair('+', AFN_lineal[12]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[11]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('a', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('b', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('c', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('d', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('e', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('f', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('g', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('h', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('i', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('j', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('k', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('l', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('m', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('n', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('o', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('p', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('q', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('r', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('s', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('t', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('u', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('v', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('w', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('x', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('y', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('z', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('A', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('B', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('C', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('D', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('E', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('F', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('G', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('H', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('I', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('J', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('K', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('L', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('M', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('N', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('O', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('P', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('Q', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('R', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('S', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('T', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('U', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('V', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('W', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('X', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('Y', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('Z', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('0', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('1', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('2', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('3', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('4', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('5', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('6', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('7', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('8', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair('9', AFN_lineal[15]));
   AFN_lineal[15]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('a', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('b', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('c', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('d', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('e', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('f', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('g', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('h', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('i', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('j', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('k', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('l', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('m', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('n', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('o', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('p', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('q', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('r', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('s', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('t', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('u', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('v', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('w', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('x', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('y', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('z', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('A', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('B', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('C', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('D', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('E', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('F', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('G', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('H', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('I', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('J', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('K', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('L', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('M', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('N', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('O', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('P', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('Q', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('R', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('S', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('T', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('U', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('V', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('W', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('X', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('Y', AFN_lineal[15]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('Z', AFN_lineal[15]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('a', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('b', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('c', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('d', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('e', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('f', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('g', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('h', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('i', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('j', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('k', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('l', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('m', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('n', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('o', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('p', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('q', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('r', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('s', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('t', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('u', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('v', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('w', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('x', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('y', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('z', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('A', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('B', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('C', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('D', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('E', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('F', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('G', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('H', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('I', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('J', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('K', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('L', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('M', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('N', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('O', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('P', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('Q', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('R', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('S', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('T', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('U', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('V', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('W', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('X', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('Y', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('Z', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('0', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('1', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('2', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('3', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('4', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('5', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('6', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('7', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('8', AFN_lineal[16]));
   AFN_lineal[16]->vertex_to.push_back(make_pair('9', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('0', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('1', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('2', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('3', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('4', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('5', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('6', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('7', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('8', AFN_lineal[16]));
   AFN_lineal[14]->vertex_to.push_back(make_pair('9', AFN_lineal[16]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[14]));
   AFN_lineal[19]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[19]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[19]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[19]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[19]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[18]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[20]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[20]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[21]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[21]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[21]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[22]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[22]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[22]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[22]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair('w', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[23]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[22]->vertex_to.push_back(make_pair('e', AFN_lineal[23]));
   AFN_lineal[21]->vertex_to.push_back(make_pair('l', AFN_lineal[22]));
   AFN_lineal[21]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[20]->vertex_to.push_back(make_pair('i', AFN_lineal[21]));
   AFN_lineal[20]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[20]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[18]->vertex_to.push_back(make_pair('h', AFN_lineal[20]));
   AFN_lineal[18]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[18]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[18]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[17]->vertex_to.push_back(make_pair('w', AFN_lineal[18]));
   AFN_lineal[17]->vertex_to.push_back(make_pair('h', AFN_lineal[19]));
   AFN_lineal[17]->vertex_to.push_back(make_pair('i', AFN_lineal[19]));
   AFN_lineal[17]->vertex_to.push_back(make_pair('l', AFN_lineal[19]));
   AFN_lineal[17]->vertex_to.push_back(make_pair('e', AFN_lineal[19]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[17]));
   AFN_lineal[26]->vertex_to.push_back(make_pair('*', AFN_lineal[26]));
   AFN_lineal[25]->vertex_to.push_back(make_pair('*', AFN_lineal[26]));
   AFN_lineal[25]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[24]->vertex_to.push_back(make_pair('*', AFN_lineal[25]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[24]));
   AFN_lineal[29]->vertex_to.push_back(make_pair('i', AFN_lineal[29]));
   AFN_lineal[29]->vertex_to.push_back(make_pair('f', AFN_lineal[29]));
   AFN_lineal[28]->vertex_to.push_back(make_pair('i', AFN_lineal[29]));
   AFN_lineal[30]->vertex_to.push_back(make_pair('i', AFN_lineal[29]));
   AFN_lineal[30]->vertex_to.push_back(make_pair('f', AFN_lineal[29]));
   AFN_lineal[30]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[28]->vertex_to.push_back(make_pair('f', AFN_lineal[30]));
   AFN_lineal[27]->vertex_to.push_back(make_pair('i', AFN_lineal[28]));
   AFN_lineal[27]->vertex_to.push_back(make_pair('f', AFN_lineal[29]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[27]));
   AFN_lineal[33]->vertex_to.push_back(make_pair('e', AFN_lineal[33]));
   AFN_lineal[33]->vertex_to.push_back(make_pair('l', AFN_lineal[33]));
   AFN_lineal[33]->vertex_to.push_back(make_pair('s', AFN_lineal[33]));
   AFN_lineal[32]->vertex_to.push_back(make_pair('e', AFN_lineal[33]));
   AFN_lineal[34]->vertex_to.push_back(make_pair('e', AFN_lineal[33]));
   AFN_lineal[34]->vertex_to.push_back(make_pair('l', AFN_lineal[33]));
   AFN_lineal[36]->vertex_to.push_back(make_pair('e', AFN_lineal[33]));
   AFN_lineal[36]->vertex_to.push_back(make_pair('l', AFN_lineal[33]));
   AFN_lineal[36]->vertex_to.push_back(make_pair('s', AFN_lineal[33]));
   AFN_lineal[36]->vertex_to.push_back(make_pair(char(238), AFN_lineal[39]));
   AFN_lineal[35]->vertex_to.push_back(make_pair('e', AFN_lineal[36]));
   AFN_lineal[35]->vertex_to.push_back(make_pair('l', AFN_lineal[33]));
   AFN_lineal[35]->vertex_to.push_back(make_pair('s', AFN_lineal[33]));
   AFN_lineal[34]->vertex_to.push_back(make_pair('s', AFN_lineal[35]));
   AFN_lineal[32]->vertex_to.push_back(make_pair('l', AFN_lineal[34]));
   AFN_lineal[32]->vertex_to.push_back(make_pair('s', AFN_lineal[33]));
   AFN_lineal[31]->vertex_to.push_back(make_pair('e', AFN_lineal[32]));
   AFN_lineal[31]->vertex_to.push_back(make_pair('l', AFN_lineal[33]));
   AFN_lineal[31]->vertex_to.push_back(make_pair('s', AFN_lineal[33]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[31]));
   AFN_lineal[37]->vertex_to.push_back(make_pair(char(32), AFN_lineal[37]));
   AFN_lineal[38]->vertex_to.push_back(make_pair(char(238), AFN_lineal[37]));
//-->finals
   AFN_lineal[6]->token_id = "token";
   AFN_lineal[9]->token_id = "token";
   AFN_lineal[12]->token_id = "token";
   AFN_lineal[15]->token_id = "token";
   AFN_lineal[23]->token_id = "keyword";
   AFN_lineal[25]->token_id = "token";
   AFN_lineal[30]->token_id = "keyword";
   AFN_lineal[36]->token_id = "keyword";
   AFN_lineal[37]->token_id = "token";
   compiler_AFN = new AFN();
   compiler_AFN->set_init_state(init_vertex);
}

void Scanner::Parse(){
  string line;
  ifstream file("texto.txt");
  size_t pos = 0;
  string token;
  while (std::getline(file, line)){
    cout << endl;
    cout << "Start of line: "<< endl << line << endl << endl;
    bool got_token = true;
    bool got_token_last = false;
    while(!line.empty()){
      cout << line << endl;
      string c = line.substr(0,1);
      got_token = compiler_AFN->simulationAFN(c, got_token);
      line.erase(0,1);
      got_token_last = !got_token;
      while(!got_token_last && !line.empty()){
        cout << "GO FOR THE MAXIMUM POWER " << endl;
        cout << line << endl;
        got_token = false;
        string c = line.substr(0,1);
        got_token = compiler_AFN->simulationAFN(c, got_token);
        if(!got_token){
          got_token_last = !got_token;
          cout << "WELCOME BACK " << endl;
          got_token = true;
        }else{
          line.erase(0,1);
        }
      }
    }
  }
}
