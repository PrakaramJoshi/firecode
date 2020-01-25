#include "1_800_problem.h"
#include<string>
#include<vector>
using namespace std;
// namespace std have been included for this problem.
#include<vector>
void get_mappings(std::string _mappings[],int index,std::string digits,std::string suffix,std::vector<std::string> &_result){
	if(index==digits.size()){
		_result.push_back(suffix);
		return;
	}
	std::cout<<digits<<std::endl;
	int digit=std::atoi(std::string(1,digits[index]).c_str());
	for(auto c:_mappings[digit-2]){
		std::string s(1,c);
		s=suffix+s;
		get_mappings(_mappings,index+1,digits,s,_result);

	}
}
// Add any helper functions(if needed) above.
vector<string> get_strings_from_nums(string digits)
{
	std::string mapping[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	std::vector<string> mappings;
	std::string suffix="";
	get_mappings(mapping,0,digits,suffix,mappings);
	return mappings;

}

bool One_800_Problem::__run(){
	std::string digit="6";

	auto m=get_strings_from_nums(digit);
	for(auto v:m){
		std::cout<<v<<",";
	}
	std::cout<<endl;
	return true;
}

REGISTER("1 800 Problem",One_800_Problem,true)
