//============================================================================
// Name        : uniqueptr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
using namespace std;

class Texture{

	 string name;
	 int width;
	 int height;


public:
	 Texture(string textname, int w, int h): name(textname), width(w), height(h){

		 cout<<"Shared Compiled"<<endl;


	 }
	 ~Texture(){

	 		 cout<<"Shader Destroyed"<<endl;


	 	 }
	 void display() const{


		 }

};

int main() {

	auto tex1 = make_unique<Texture>("player_sprite", 512, 512);
	tex1->display();


	unique_ptr<Texture> tex2 = move(tex1);
	cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

	return 0;
}
