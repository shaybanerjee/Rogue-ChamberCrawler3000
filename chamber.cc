#include "chamber.h"

Chamber::Chamber(const int i){
	switch(i){
		case 0: 
			for (int i = 3; i < 7; ++i){
				for (int j = 3; j < 29; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			break;
		case 1: 
			for (int i = 15; i < 22; ++i ){
				for (int j = 4; j < 25; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			break;
		case 2:
			for (int i = 10; i < 13; ++i){
				for (int j = 38; j < 50; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			break;
		case 3:
			for (int i = 3; i < 7; ++i){
				for (int j = 39; j < 62; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			for (int i = 5; i < 7; ++i){
				for (int j = 62; j<70; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			cham_pos.emplace_back(Position{6,70});
			cham_pos.emplace_back(Position{6,71});
			cham_pos.emplace_back(Position{6,72});
			for (int i = 7; i < 13; ++i){
				for (int j = 61; j < 76; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			break;
		case 4:
			for (int i = 41; i < 44; ++i){
				for (int j = 65; j < 76; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
			for (int i = 44; i < 47; ++i){
				for (int j = 37; j < 76; ++j){
					cham_pos.emplace_back(Position{i,j});
				}
			}
	}
}