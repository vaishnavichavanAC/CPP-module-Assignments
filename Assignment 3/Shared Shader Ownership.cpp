//============================================================================
// Name        : Shared.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;

     class Shader{

private:
	 string name;
	 string type ;


public:

     Shader(string textname, string shaderType = "vertex"): name(textname), type(shaderType){

    	 cout<<"Shader Compiled :"<<name <<"("<<shaderType<<")"<<endl;

     }

     ~Shader(){

    	 cout<<"Shader Destroyed: "<<name<<endl;



     }

     };
     int getReferenceCount(const shared_ptr<Shader>& ptr) {
         return ptr.use_count();



     }
int main() {

	auto shader = make_shared<Shader>("main_vert", "vertex");
	cout << "Ref count: " << shader.use_count() << endl;
	{
	// 1
	auto rendererRef = shader;
	cout << "Ref count: " << shader.use_count() << endl;  // 2

	auto editorRef   = shader;
	cout << "Ref count: " << shader.use_count() << endl;  // 3
	}

	cout << "Ref count: " << shader.use_count() << endl;

}
