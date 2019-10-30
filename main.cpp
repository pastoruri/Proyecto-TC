#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct scanner{

    scanner(){}

    static vector<string> decode_word(string word){
        vector<string> decoded_word;
        decode_aux(word, decoded_word);
        int size_count = 0;

        for(int i=0; i < decoded_word.size(); ++i){
            size_count += decoded_word[i].size();
		} 

		if (size_count != word.size()) {
            cout << "There's a typo somewhere in the number passed "<<endl;
        }

        return decoded_word;
    }

   	static void decode_aux(string word, vector<string> & decoded_word) {

        if(word.size() == 0){
            return;
        }

        switch (word[0]) {
            case 'a': {
                if(word.substr(0,4) == "atch") {
                    decoded_word.push_back("atch");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }

            case 'd': {
                if(word.substr(0,4) == "drei") {
                    decoded_word.push_back("drei");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
            case 'e': {
                if(word.substr(0,3) == "ein") {
                    decoded_word.push_back("ein");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                } else if(word.substr(0,3) == "elf") {
                    decoded_word.push_back("elf");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                } else{
                    break;
                }
            }

            case 'f': {
                if(word.substr(0,4) == "funf") {
                    decoded_word.push_back("funf");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else{
                    break;
                }
            }

            case 'h': {
                if(word.substr(0,7) == "hundert") {
                    decoded_word.push_back("hundert");
                    word.erase(0, 7);
                    decode_aux(word, decoded_word);
                } else {
                    break;
      	        }
            }

            case 'n': {
                if(word.substr(0,4) == "neun") {
                    decoded_word.push_back("neun");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
            case 's': {
                if(word[4] == 's' && word.substr(4,8) != "sieb" && word.substr(4,8) != "sech" && word.substr(4,8) != "ssig") {
                    decoded_word.push_back("sechs");
                    word.erase(0, 5);
                    decode_aux(word, decoded_word);
                } else if (word[4] != 's' && word.substr(0,4) == "sech") {
                    decoded_word.push_back("sech");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,4) == "sieb" && word.substr(4,6) != "en") {
                    decoded_word.push_back("sieb");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,6) == "sieben") {
                    decoded_word.push_back("sieben");
                    word.erase(0, 6);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,4) == "ssig") {
                    decoded_word.push_back("ssig");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
            case 't': {
                if(word.substr(0,7) == "tausend") {
                    decoded_word.push_back("tausend");
                    word.erase(0, 7);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
            case 'u': {
                if(word.substr(0,3) == "und") {
                    decoded_word.push_back("und");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
            case 'v' :{
                if(word.substr(0,4) == "vier") {
                    decoded_word.push_back("vier");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }

            case 'z' :{
                if( word.substr(0,4) == "zwei" ) {
                    decoded_word.push_back("zwei");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,4) == "zehn") {
                    decoded_word.push_back("zehn");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,5) == "zwolf") {
                    decoded_word.push_back("zwolf");
                    word.erase(0, 5);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,4) == "zwan") {
                    decoded_word.push_back("zwan");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,3) == "zig") {
                    decoded_word.push_back("zig");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                } else {
                    break;
                }
            }
        }
    }
};

int main(int argc, char * argv []) {
	if (argc == 2) {
		auto a = scanner::decode_word(argv[1]);
		
		for (int i = 0; i < a.size(); ++i){
			cout << a[i] << ' ';
		}

	} else {
		cout << "Necesitas un argumento" << endl;
	}

	return 0;
}
