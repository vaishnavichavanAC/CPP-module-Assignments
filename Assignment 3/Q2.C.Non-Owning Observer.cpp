//============================================================================
// Name        : Non-Owning.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(string clipName, double clipDuration) : name(clipName), duration(clipDuration) {}

    string getName() const {
        return name;
    }
};

int main() {

	auto audio = make_shared<AudioClip>("explosion", 3.5);
	weak_ptr<AudioClip> observer = audio;

	if (auto clip = observer.lock())
	cout << "Clip alive: " << clip->getName() << endl;

	audio.reset();

	if (observer.expired())
	cout << "Clip already unloaded." << endl;

	return 0;
}
