#pragma once
#include <chrono>
#include<iostream>
#include <map>
#include<string>
template<typename T>
class Launcher{
    T m_obj;
    public:
	Launcher(const std::string &_name,bool _active){
		g_register(_name,&m_obj,_active);
    }
};

#define REGISTER(Name,Class,Active) Launcher<Class> obj__##Class(Name,Active);
class BaseCode{

    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_end;

    void __start_timer(){
        m_start=std::chrono::high_resolution_clock::now();
    }

    void __stop_timer(){
        m_end=std::chrono::high_resolution_clock::now();
    }

    protected:

    virtual bool __run()=0;

    public:

    void run(){
        __start_timer();
        auto ret=__run();
        __stop_timer();
        std::cout<<"Time to run "<<(m_end-m_start).count()<<std::endl;
        if(ret){
            std::cout<<"All tests passed!"<<std::endl;
        }
        else{
            std::cout<<"Some tests failed"<<std::endl;
        }
    }
    virtual ~BaseCode(){

    }
};



void g_register(const std::string &_name,BaseCode *_obj,bool _active);
void rung();
