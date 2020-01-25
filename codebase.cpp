#include "codebase.h"

std::map<std::string,std::pair<BaseCode*,bool > > *codedatabase=nullptr;;
std::map<std::string,std::pair<BaseCode*,bool > > *get_codedatabase(){
	if(codedatabase==nullptr){
		codedatabase= new std::map<std::string,std::pair<BaseCode*,bool > > ();
	}
	return codedatabase;
}
void g_register(const std::string &_name,BaseCode *_obj,bool _active){
	auto codecontainer=get_codedatabase();
	auto iter=codecontainer->find(_name);
	if(iter!=codecontainer->end()){
		std::cout<<"Cannot add duplicate code base "<<_name<<std::endl;
		std::exit(0);
	}
	(*codecontainer)[_name]=std::make_pair(_obj,_active);
}


void rung(){
	auto codecontainer=get_codedatabase();
	for(const auto & t:*codecontainer){
		if(t.second.second)
			t.second.first->run();
	}
}
