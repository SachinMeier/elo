#include "main.h"



int main(int argc, const char * argv[]){
	Player p1, p2;
	for(int i = 0; i < 5; ++i){
		p1.print();
		p2.print();
		bool outcome = p1.versus(p2);
		if(outcome == 1){
			cout << "--p1 wins--\n";
		}
		else if(outcome == 0){
			cout << "--p2 wins--\n";
		}
		else{
			cout << "--- draw --\n";
		}
	}
	return 0;
} 