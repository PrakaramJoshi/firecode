#include "recursive_string_permutations.h"
#include<set>
#include<functional>
#include<iostream>
#include<tuple>
#include<vector>
// namespace std have been included for this problem.
using namespace  std;
void get_permutations(string &s,vector<string> &_p,std::set<int> &_used,std::string _current_permutation){
	if(_used.size()==s.length()){
		_p.push_back(_current_permutation);
	}
	for(auto i =0;i<s.length();i++){
		if(_used.find(i)==_used.end()){
			_used.insert(i);
			string s2(1,s[i]);
			get_permutations(s,_p,_used,_current_permutation+s2);
			_used.erase(i);
		}
	}
}
// Add any helper functions(if needed) above.
vector<string>  get_permutations(string s)
{
	vector<string> permutations;
	std::set<int>used;
	std::string _current_permutation;
	get_permutations(s,permutations,used,_current_permutation);
	return permutations;
}


bool RecursiveStringPermutations::__run(){

	auto permutations=get_permutations("cat");
	for(const auto & permuation:permutations){
		std::cout<<permuation<<std::endl;
	}
	return true;
}

REGISTER("RecursiveStringPermutations",RecursiveStringPermutations,false)
