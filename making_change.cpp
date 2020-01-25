#include "making_change.h"
#include<set>
#include<functional>
#include<iostream>
int get_count(std::set<int,std::greater<int>> &_coins, int amount,int min_coin){
	if(amount<=0){
		return 0;
	}
	auto iter=_coins.lower_bound(std::min(amount,min_coin));
	if(iter==_coins.end()){
		return 0;
	}
	int count=0;
	for(;iter!=_coins.end();++iter){
		int r=amount-(*iter);
		if(r==0){
			count+=1;
		}
		else{
			count+=get_count(_coins,r,*iter);
		}
	}
	return count;
}
// Add any helper functions(if needed) above.
int make_change(int coins[], int n, int amount)
{
  std::set<int,std::greater<int>> coinsset;
  for(int i=0;i<n;i++){
	  coinsset.insert(coins[i]);
  }
  return get_count(coinsset,amount,amount);

}



bool MakingChange::__run(){
	int test1[]={25,10,5,1};

	std::cout<<make_change(test1,4,10)<<std::endl;
	return true;
}

REGISTER("Making Change",MakingChange,false)
