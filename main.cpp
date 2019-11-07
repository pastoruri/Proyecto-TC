#include <iostream>
#include <vector>
#include <string>
#include <utility>

int contador = 2;
int fin = 0;

using namespace std;

struct scanner {
    scanner() = default;
    static vector<string> decode_word(string word) {
        vector<string> decoded_word;
        decode_aux(word, decoded_word);
        int size_count = 0;
        for (int i = 0; i < decoded_word.size(); ++i) {
            size_count += decoded_word[i].size();
        }
        if (size_count != word.size()) {
            cout << "There's a typo somewhere."<<endl;
        }
        return decoded_word;
    }
   static void decode_aux(string word, vector<string>& decoded_word) {

        if (word.size() == 0) {
            return;
        }

        switch (word[0]) {
            case 'a': {
                if(word.substr(0,4) == "atch") {
                    decoded_word.push_back("atch");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else {
                    break;
                }
            }
            case 'd': {
                if(word.substr(0,4) == "drei") {
                    decoded_word.push_back("drei");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else {
                    break;
                }
            }
            case 'e': {
                if(word.substr(0,3) == "ein") {
                    decoded_word.push_back("ein");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                } else if (word.substr(0,3) == "elf") {
                    decoded_word.push_back("elf");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                }
                else {
                    break;
                }
            }

            case 'f' : {
                if (word.substr(0,4) == "funf") {
                    decoded_word.push_back("funf");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else {
                    break;
                }
            }

            case 'h' : {
                    if (word.substr(0,7) == "hundert") {
                        decoded_word.push_back("hundert");
                        word.erase(0, 7);
                        decode_aux(word, decoded_word);
                    }
                    else {
                        break;
                    }
                }

            case 'n' : {
                if (word.substr(0,4) == "neun") {
                    decoded_word.push_back("neun");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }
            case 's' :{
                if(word[4] == 's' && word.substr(4,8) != "sieb" && word.substr(4,8) != "sech" && word.substr(4,8) != "ssig") {
                    decoded_word.push_back("sechs");
                    word.erase(0, 5);
                    decode_aux(word, decoded_word);
                }
                else if (word[4] != 's' && word.substr(0,4) == "sech") {
                    decoded_word.push_back("sech");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,4) == "sieb" && word.substr(4,6) != "en"){
                    decoded_word.push_back("sieb");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,6) == "sieben"){
                    decoded_word.push_back("sieben");
                    word.erase(0, 6);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,4) == "ssig"){
                    decoded_word.push_back("ssig");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }
            case 't' :{
                if(word.substr(0,7) == "tausend") {
                    decoded_word.push_back("tausend");
                    word.erase(0, 7);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }
            case 'u' :{
                if(word.substr(0,3) == "und") {
                    decoded_word.push_back("und");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }
            case 'v' :{
                if(word.substr(0,4) == "vier") {
                    decoded_word.push_back("vier");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }

            case 'z' :{
                if( word.substr(0,4) =="zwei" ) {
                    decoded_word.push_back("zwei");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,4) == "zehn") {
                    decoded_word.push_back("zehn");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,5) == "zwolf"){
                    decoded_word.push_back("zwolf");
                    word.erase(0, 5);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,4) == "zwan"){
                    decoded_word.push_back("zwan");
                    word.erase(0, 4);
                    decode_aux(word, decoded_word);
                }
                else if (word.substr(0,3) == "zig"){
                    decoded_word.push_back("zig");
                    word.erase(0, 3);
                    decode_aux(word, decoded_word);
                }
                else{
                    break;
                }
            }

            }





    }
};

vector<string> z1 = {"ein", "zwei", "drei", "vier", "funf", "sechs", "sieben", "acht", "neun"}; 
vector<string> z2 = {"zehn", "elf", "zwolf"};
vector<string> z3 = {"drei", "vier", "funf", "sech", "sieb", "acht", "neun" };
vector<string> z4 = {"zwan", "vier", "funf", "sech", "sieb", "acht", "neun" };
vector<string> z5 = {"hundert"};
vector<string> z6 = {"tausend"};

bool is_in_z2(const string& w) {
	for (auto& s : z2) {
		if (s == w) {
			contador = 1;
			return true;
		}
	}
	return false;
}

bool rule1(const vector<string>& svec, unsigned index) {
	string s = svec[index];

	bool accepts = false;

	for (auto& word : z1)
		if (word == s)
			accepts = true;

	return accepts;
}

bool rule2(const vector<string>& svec, unsigned index) {
	string s = svec[index];
	string next_word = svec[index+1];
	bool word_matched = false;

	for (auto& word : z3)
		if (word == s)
			word_matched = true;

	if (word_matched && next_word == "zehn"){
		contador = 2;
		return true;
	}
	else
		return false;
}

bool rule71(const vector<string>& svec, unsigned index) {
	string s = svec[index];
	string next_word = svec[index+1];
	bool word_matched = false;

	for (auto& word : z4)
		if (word == s)
			word_matched = true;

	if (word_matched && next_word == "zig")
		return true;
	else
		return false;
	
}

bool rule72(const vector<string>& svec, unsigned index) {
	string s = svec[index];
	string next_word = svec[index+1];

	return (s == "drei" && next_word == "ssig");
}

bool rule7(const vector<string>& svec, unsigned index) {
	string curr_word = svec[index];
	string next_word = svec[index+1];

	if (curr_word == "drei"){
		contador = 2;
		return rule72(svec, index);
	}
	else{
		contador = 2;
		return rule71(svec, index);
	}
}

bool ruleU(const vector<string>& svec, unsigned index) {
	string s = svec[index];
	string next_word = svec[index+1];
	bool word_matched = false;

	word_matched = rule1(svec, index);

	if (word_matched && next_word == "und"){
		contador = 2;
		return true;
	}
	else
		return false;
}

bool rule9(const vector<string>& svec, unsigned index) {	
	string s = svec[index];
	string next_word = svec[index+1];
	bool word_matched1 = false;
	bool word_matched2 = false;

	word_matched1 = rule1(svec, index);

	for (auto& word : z5)
		if (word == next_word)
			word_matched2 = true;

	if (word_matched1 && word_matched2){
		contador = 2;
		return true;
	}
	else
		return false;
}

bool rule8(const vector<string>& svec, unsigned index) {
	bool ruleU_accepted = ruleU(svec, index);
	bool rule7_accepted = false;

	rule7_accepted = rule7(svec, index+2);

	if (ruleU_accepted && rule7_accepted){
		contador = 4;
		return true;
	}
	else 
		return false;
}

pair<bool, unsigned> rule10(const vector<string>& svec, unsigned index) {
	unsigned offset = 0;
	string s = svec[index];
	bool should_use_rule2 = true;
	for (auto& word : z2)
		if (word == s)
			should_use_rule2 = false;

	bool rule2_accepted = false;
	bool next_word_in_z5 = false;

	if (should_use_rule2) {
		rule2_accepted = rule2(svec, index);
		if (svec[index+2] == "hundert") {
			contador = 3;
			next_word_in_z5 = true;
			offset = 3;
		}
	} else {
		rule2_accepted = true;
		if (svec[index+1] == "hundert") {
			contador = 2;
			next_word_in_z5 = true;
			offset = 2;
		}
	}

	return make_pair(rule2_accepted && next_word_in_z5, offset);
}

pair<bool, unsigned> rule11(const vector<string>& svec, unsigned index) {
	unsigned offset = 0;
	string s = svec[index];
	bool rule5_accepts = false;
	bool rule9_accepts = false;
	if (s == "hundert") {
		rule5_accepts = true;
		++offset;
	} else {
		rule9_accepts = rule9(svec, index);
		if (rule9_accepts)
			offset += 2;
	}

	bool rule5_or_rule9_accepts = rule5_accepts || rule9_accepts;

	if (rule5_or_rule9_accepts == false) {
		return make_pair(false, offset);
	}

	// CHECK FOR RULE 1, 2, 7, 8 ACCEPTANCE
	
	// checking rule 1
	bool rule1_accepts = false;
	if (rule9_accepts) {
		rule1_accepts = rule1(svec, index+2);
	} else {
		rule1_accepts = rule1(svec, index+1);
	}

	if (rule1_accepts && rule5_or_rule9_accepts) {
		++offset;
		contador = offset;
		return make_pair(true, offset);
	}

	// at this point, rule5 or rule 9 accepts, but rule1 doesn't
	// checking rule 2
	bool rule2_accepts = false;
	if (rule9_accepts) {
		if (is_in_z2(svec[index+2])) {
			rule2_accepts = true;
			++offset;
		} else {
			rule2_accepts = rule2(svec, index+2);
			if (rule2_accepts)
				offset += 2;
		}
	} else {
		if (is_in_z2(svec[index+1])) {
            rule2_accepts = true;
			++offset;
        } else {
            rule2_accepts = rule2(svec, index+1);
			if (rule2_accepts)
				offset += 2;
        }
	}
	
	if (rule2_accepts && rule5_or_rule9_accepts){
		contador = offset;
		return make_pair(true, offset);
	}

	// at this point, rule5 or rule9 accepts, but rule2 doesn't
	// checking rule 8

	bool rule8_accepts = false;
	if (rule9_accepts) {
		rule8_accepts = rule8(svec, index+2);
	} else {
		rule8_accepts = rule8(svec, index+1);
	}

	if (rule8_accepts && rule5_or_rule9_accepts) {
		offset += 4;
		contador = offset;
		return make_pair(true, offset);
	}

	// at this point, rule5 or rule9 accepts, but rule8 doesn't
	// checking rule 7
	
	bool rule7_accepts = false;
	if (rule9_accepts) {
		rule7_accepts = rule7(svec, index+2);	
	} else {
		rule7_accepts = rule7(svec, index+1);
	}
	
	if (rule7_accepts && rule5_or_rule9_accepts) {
		offset += 2;
		contador = offset;
		return make_pair(true, offset);
	} else {
		return make_pair(false, offset);
	}
}

bool rule12(const vector<string>& svec, unsigned index) {
	pair<bool, unsigned> rule10_a = rule10(svec, index);
	bool rule10_accepts = rule10_a.first;
	if (!rule10_accepts)
		return false;

	unsigned offset = rule10_a.second;

	// checking rule 1
	bool rule1_accepts = rule1(svec, index+offset);
	if (rule10_accepts && rule1_accepts){
		contador = rule10_a.first + 1;
		return true;
	}

	// checking rule 2
	bool rule2_accepts = false;
	int returnz2 = 0;
	if (is_in_z2(svec[index+offset])) {
		returnz2 = 1;
		rule2_accepts = true;		
	} else {
		returnz2 = 2;
		rule2_accepts = rule2(svec, index+offset);
	}
	if (rule10_accepts && rule2_accepts){
		contador = rule10_a.first + returnz2;
		return true;
	}

	// checking rule 8
	bool rule8_accepts = rule8(svec, index+offset);
	if (rule10_accepts && rule8_accepts){
		contador = rule10_a.first + 4;
		return true;
	}

	// checking rule 7
	bool rule7_accepts = rule7(svec, index+offset);
	if (rule10_accepts && rule7_accepts){
		contador = rule10_a.first + 2;
		return true;
	}
	else
		return false;
}

pair<bool, unsigned> rule13(const vector<string>& svec, unsigned index) {
	// checking rule 11 and 6
	pair<bool, unsigned> rule11_a = rule11(svec, index);
	bool rule11_accepts = rule11_a.first;
	unsigned offset = rule11_a.second;
	bool rule6_accepts = (svec[index+offset] == "tausend");
	if (rule11_accepts && rule6_accepts){
		contador = offset+1;
		return make_pair(true, offset+1);
	}
	
	// checking rule 9 and 6
	bool rule9_accepts = rule9(svec, index);
	rule6_accepts = (svec[index+2] == "tausend");
	if (rule9_accepts && rule6_accepts) {
		offset = 3;
		contador = offset;
		return make_pair(true, offset);
	}

	// checking rule 7 and 6
	bool rule7_accepts = rule7(svec, index);
	rule6_accepts = (svec[index+2] == "tausend");
	if (rule7_accepts && rule6_accepts) {
		offset = 3;
		contador = offset;
		return make_pair(true, offset);
	}

	// checking rule 1 and 6
	bool rule1_accepts = rule1(svec, index);
	rule6_accepts = (svec[index+1] == "tausend");
	if (rule1_accepts && rule6_accepts) {
		offset = 2;
		contador = offset;
		return make_pair(true, offset);
	}

	// checking rule 2 and 6
	bool rule2_accepts = false;
	if (is_in_z2(svec[index])) {
		rule2_accepts = true;
		rule6_accepts = (svec[index+1] == "tausend");
		offset = 2;
	} else {
		rule2_accepts = rule2(svec, index);
		rule6_accepts = (svec[index+2] == "tausend");
		offset = 3;
	}
	if (rule2_accepts && rule6_accepts){
		contador = offset;
		return make_pair(true, offset);
	}

	// checking rule 8
	bool rule8_accepts = rule8(svec, index);
	rule6_accepts = (svec[index+4] == "tausend");
	if (rule8_accepts && rule6_accepts) {
		offset = 5;
		contador = offset;
		return make_pair(true, offset);
	} else {
		return make_pair(false, offset);
	}
}

bool rule14(const vector<string>& svec, unsigned index) {
	pair<bool, unsigned> rule13_a = rule13(svec, index);
	bool rule13_accepts = rule13_a.first;
	bool rule6_accepts = (svec[index] == "tausend");

	unsigned returnz6 = 1;
	unsigned offset = rule13_a.second;

	unsigned final = 0;

	if (rule13_accepts){
		final = offset;
	} else {
		final = 1;
	}

	bool rule6_or_rule13_accepts = rule13_accepts || rule6_accepts;

	if (rule6_or_rule13_accepts  == false){
		return false;
	}

	// checking rule 11
	pair<bool, unsigned> rule11_a;
	bool rule11_accepts = false;
	if (rule6_accepts) {
		rule11_a = rule11(svec, index+1);
		rule11_accepts = rule11_a.first;
	} else { // rule 13 accepts
		rule11_a = rule11(svec, index+offset);
		rule11_accepts = rule11_a.first;
	}
	if (rule11_accepts && rule6_or_rule13_accepts){
		contador = final + rule11_a.second;
		return true;
	}

	// checking rule 9
	bool rule9_accepts = false;
	if (rule6_accepts) { // offset is 1
		rule9_accepts = rule9(svec, index+1);
	} else { // offset is offset
		rule9_accepts = rule9(svec, offset);
	}
	if (rule9_accepts && rule6_or_rule13_accepts){
		contador = final + 2;
		return true;
	}

	// checking rule 7
	bool rule7_accepts = false;
	if (rule6_accepts) { // offset is 1
		rule7_accepts = rule7(svec, index+1);
	} else { // offset is offset
		rule7_accepts = rule7(svec, index+offset);
	}
	if (rule7_accepts && rule6_or_rule13_accepts){
		contador = final + 2;
		return true;
	}

	// checking rule 1
	bool rule1_accepts = false;
	if (rule6_accepts) { // offset is 1
		rule1_accepts = rule1(svec, index+1);
	} else { // offset is offset
		rule1_accepts = rule1(svec, index+offset);
	}
	if (rule1_accepts && rule6_or_rule13_accepts){
		contador = final + 1;
		return true;
	}

	// checking rule 2
	unsigned rule2_cont = 0;
	bool rule2_accepts = false;
	if (rule6_accepts) { // offset is 1
		if (is_in_z2(svec[index+1])){
			rule2_cont = 1;
			rule2_accepts = true;
		}
		else{
			rule2_cont = 2;
			rule2_accepts = rule2(svec, index+1);
		}
	} else { // offset is offset
		if (is_in_z2(svec[index+offset])){
			rule2_cont = 1;
			rule2_accepts = true;
		}
		else{
			rule2_cont = 2;
			rule2_accepts = rule2(svec, index+offset);
		}
	}
	if (rule2_accepts && rule6_or_rule13_accepts){
		contador = final + rule2_cont;
		return true;
	}

	// checking rule 8
	bool rule8_accepts = false;
	if (rule6_accepts) { // offset is 1
		rule8_accepts = rule8(svec, index+1);
	} else { // offset is offset
		rule8_accepts = rule8(svec, index+offset);
	}
	if (rule8_accepts && rule6_or_rule13_accepts){
		contador = final + 4;
		return true;
	}
	else
		return false;
}

bool analyze(const vector<string>& svec, unsigned index) {

	if (svec.size() == 0){
		return false;
	}

	while (fin < svec.size()){

		if ( rule2(svec, fin) ){
			fin += contador;
			goto End;
		} 

		if ( rule7(svec, fin) ){
			fin += contador;
			goto End;
		} 

		if ( rule8(svec, fin) ){
			fin += contador;
			goto End;
		}

		if ( rule9(svec, fin) ){
			fin += contador;
			goto End;
		}

		if ( rule10(svec, fin).first ){
			fin += rule10(svec, fin).second;
			goto End;
		}

		if ( rule11(svec, fin).first ){
			fin += rule11(svec, fin).second;
			goto End;
		}

		if ( rule12(svec, fin) ){
			fin += contador;
			goto End;
		}

		if ( rule13(svec, fin).first ){
			fin += rule13(svec, fin).second;
			goto End;
		}

		if ( rule14(svec, fin) ){
			fin += contador;
			goto End;
		}

		if ( ruleU(svec, fin) ){
			fin += contador;
			goto End;
		}

		cout << "Se encontró un error.\nLeyó hasta: ";
		for (int i = 0; i < fin; ++i) {
			cout << svec[i];
		}
		cout << endl;

		return false;

		End:
			fin++;
	}

	return true;
	
}

int main(int argc, char** argv) {
	// TODO: regla de identificación de errores
	string word;

	cout << "Enter a number in German: ";
	cin >> word;

	vector<string> word_parts = scanner::decode_word(word);
	for (int i = 0; i < word_parts.size(); i++)
	   cout << word_parts[i] << " ";
	cout << endl;

	bool acepto = analyze(word_parts, 0);

	cout << "Word accepted? " << (acepto ? "Yes" : "No") << endl;

	return 0;
}
