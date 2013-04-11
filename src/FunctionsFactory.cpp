/*
 * FunctionsFactory.cpp
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#include "../inc/FunctionsFactory.h"

void FunctionsFactory::create(string source, vector<Function*>& funVec){
	stringstream ss(source);
	string temp;

	while(getline(ss, temp, ' ')){
		if(isXFunction(temp)){
			if(temp.length() > 1){
				temp = temp.substr(0, temp.length()-1);
				funVec.push_back( new XFunction( temp ) );
			}else{
				funVec.push_back(( new XFunction() ));
			}

			continue;
		}
		if(isFloat(temp)){
			funVec.push_back( new ConstFunction(temp) );
			continue;
		}
		if(temp == (string("-")+XFunction::name)){
			funVec.push_back( new XFunction("-") );
			continue;
		}
		if(temp == AddFunction::name){
			funVec.push_back( new AddFunction() );
			continue;
		}
		if(temp == SubFunction::name){
			funVec.push_back( new SubFunction() );
			continue;
		}
		if(temp == MulFunction::name){
			funVec.push_back( new MulFunction() );
			continue;
		}
		if(temp == DivFunction::name){
			funVec.push_back( new DivFunction() );
			continue;
		}
		if(temp == PowFunction::name){
			funVec.push_back( new PowFunction() );
			continue;
		}
		if(temp == LnFunction::name){
			funVec.push_back( new LnFunction() );
			continue;
		}
		if(temp == CosFunction::name){
			funVec.push_back( new CosFunction() );
			continue;
		}
		if(temp == SinFunction::name){
			funVec.push_back( new SinFunction() );
			continue;
		}
		if(temp == LeftBracket::name){
			funVec.push_back( new LeftBracket() );
			continue;
		}
		if(temp == RightBracket::name){
			funVec.push_back( new RightBracket() );
			continue;
		}
	}
}

bool FunctionsFactory::isFloat(string source){
	float x = atof(source.c_str());
	stringstream ss;
	ss<<x;
	if(ss.str() == source){
		return true;
	}else{
		return false;
	}
}

bool FunctionsFactory::isXFunction(string source){
	string temp = source.substr(0, source.length()-1 );
	if(source[source.length()-1] == 'x'){
		if(source.length() > 1){
			if(isFloat(temp)){
				return true;
			}
		}else{
			return true;
		}
	}
	return false;
}
